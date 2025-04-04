# deployment vars
NAME := stack

# ============================================================
# NOTE: the following are only necessary if hosting containers
# This can be safely removed
# ============================================================

REGISTRY :=
SUFFIX :=

# configurable vars:
# HPORTS="8888 8889" make -e ...
CPORTS := 1337
HPORTS := $(CPORTS)
SERVICES := PWN

# generate service -> port mappings: SERVICE_PORT := PORT
# this is necessary for docker compose string substitution via env variables
# also useful for containers requiring build args for setting ports on multiple services
$(foreach var, \
    $(shell \
				python -c "for s, p in zip('$(SERVICES)'.split(), '$(CPORTS)'.split()): print(f'{s}_CPORT:={p}')" \
    ), $(eval $(var)) \
)

# docker
DOCKER_CONTEXT := default
DOCKER_GLOBAL := --context $(DOCKER_CONTEXT)
DOCKER_RUNTIME := --memory=128m --cpus=0.2 --read-only --restart=always


# ============================================================
# NOTE: if not compiling, the $(NAME) dep along with compilation
# 	directive can be safely removed
#	docker directives may be removed if docker is not used
#	dist directives should be omitted if there is no distributable
# ============================================================

# build vars
CC := gcc
CFLAGS :=
LDFLAGS := -l:libcapstone.a
all: $(NAME)

$(NAME): $(NAME).c
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@ 

clean: .PHONY
	rm -rf $(NAME).tar.gz build
	docker container rm -f $(NAME)$(SUFFIX)

build: Dockerfile
	docker $(DOCKER_GLOBAL) build -t $(NAME) \
		--build-arg name=$(NAME) \
		--build-arg port=$(PWN_CPORT) \
		.

run:
	$(eval ports := $(shell python -c "for h, c in zip('$(HPORTS)'.split(), '$(CPORTS)'.split()): print(f' -p {h}:{c}')"))
	docker $(DOCKER_GLOBAL) run $(DOCKER_RUNTIME) -d --name $(NAME)$(SUFFIX) $(ports) $(REGISTRY)$(NAME)

extract:
	mkdir build
	$(eval id := $(shell docker create $(NAME)))
	docker cp $(id):/pwn/$(NAME) build/$(NAME)
	docker cp $(id):/lib/x86_64-linux-gnu/libc-2.28.so build/libc.so.6
	docker cp $(id):/lib/x86_64-linux-gnu/ld-2.28.so build/ld-2.28.so
	docker rm -v $(id)

dist: extract
	cp $(NAME).c build
	cp solver-template.py build
	mv build $(NAME)
	tar -czf $(NAME).tar.gz $(NAME)
	rm -rf $(NAME)

.PHONY:
