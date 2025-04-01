# deployment vars
NAME := sandbox

# ============================================================
# NOTE: the following are only necessary if hosting containers
# This can be safely removed
# ============================================================

REGISTRY :=
SUFFIX :=

# configurable vars:
# HPORTS="8888 8889" make -e ...
CPORTS := 5000
HPORTS := $(CPORTS)
SERVICES := SOCKET

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
# TODO - CHANGE LATER
DOCKER_RUNTIME := --memory=4g --cpus=1 --restart=always --privileged

all: build

build: .PHONY
	docker $(DOCKER_GLOBAL) build -t $(NAME) .

run:
	$(eval ports := $(shell python -c "for h, c in zip('$(HPORTS)'.split(), '$(CPORTS)'.split()): print(f' -p {h}:{c}')"))
	docker $(DOCKER_GLOBAL) run $(DOCKER_RUNTIME) -d --name $(NAME)$(SUFFIX) $(ports) $(REGISTRY)$(NAME)

stop:
	docker $(DOCKER_GLOBAL) rm -f $(NAME)$(SUFFIX)

clean: stop
	rm -rf $(NAME).tar.gz

dist:
	tar -czf $(NAME).tar.gz solver-template.py sandbox.c Dockerfile user-data.yaml metadata.yaml start.sh

.PHONY: