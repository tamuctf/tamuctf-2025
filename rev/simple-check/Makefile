# deployment vars
NAME := simple-check

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
SERVICES := SHELL

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
DOCKER_RUNTIME := --privileged --read-only --memory=4g --cpus=1.5 --restart=always --tmpfs /tmp


# ============================================================
# NOTE: if not compiling, the $(NAME) dep along with compilation
# 	directive can be safely removed
#	docker directives may be removed if docker is not used
#	dist directives should be omitted if there is no distributable
# ============================================================

# build vars
CC := $(or $(CC),gcc)
CFLAGS := -O0 -fno-stack-protector

all: $(NAME)

clean: .PHONY
	rm -f $(NAME).tar.gz

build: Dockerfile flag.txt
	docker $(DOCKER_GLOBAL) build -t $(NAME) \
		--build-arg name=$(NAME) \
		--build-arg shell_port=$(SHELL_CPORT) \
		.

run:
	$(eval ports := $(shell python -c "for h, c in zip('$(HPORTS)'.split(), '$(CPORTS)'.split()): print(f' -p {h}:{c}')"))
	docker $(DOCKER_GLOBAL) run $(DOCKER_RUNTIME) -d --name $(NAME)$(SUFFIX) $(ports) $(REGISTRY)$(NAME)

extract: build .PHONY
	mkdir -p build
	$(eval id := $(shell docker create $(NAME)))
	docker cp $(id):/call-logger build/call-logger
	docker cp $(id):/read-any-file build/read-any-file
	docker rm -v $(id)

dist: extract
	ln solver-template.py build/solver-template.py
	tar -czvf $(NAME).tar.gz build --transform s/build/$(NAME)/

.PHONY:
