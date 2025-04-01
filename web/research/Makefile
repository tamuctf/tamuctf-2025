# deployment vars
NAME := research

# ============================================================
# NOTE: the following are only necessary if hosting containers
# This can be safely removed
# ============================================================

REGISTRY :=
SUFFIX :=

# configurable vars:
# HPORTS="8888 8889" make -e ...
CPORTS := 8000
HPORTS := $(CPORTS)
SERVICES := HTTP

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
DOCKER_RUNTIME := --memory=2g --cpus=10 --restart=always


# ============================================================
# NOTE: if not compiling, the $(NAME) dep along with compilation
# 	directive can be safely removed
#	docker directives may be removed if docker is not used
#	dist directives should be omitted if there is no distributable
# ============================================================
clean: .PHONY
	rm -f $(NAME).tar.gz
	docker container rm -f $(NAME)$(SUFFIX) 

build: Dockerfile 
	docker $(DOCKER_GLOBAL) build -t $(NAME) --build-arg port=$(HTTP_CPORT) .

run:
	$(eval ports := $(shell python -c "for h, c in zip('$(HPORTS)'.split(), '$(CPORTS)'.split()): print(f' -p {h}:{c}')"))
	docker $(DOCKER_GLOBAL) run $(DOCKER_RUNTIME) --name $(NAME)$(SUFFIX) -d \
		--read-only \
		--mount type=tmpfs,destination=/tmp,tmpfs-mode=1777,tmpfs-size=1G \
		--mount type=tmpfs,destination=/var/tmp,tmpfs-mode=1777,tmpfs-size=1G \
		--mount type=tmpfs,destination=/var/lib/nginx,tmpfs-mode=750,tmpfs-size=64M \
		--mount type=tmpfs,destination=/run,tmpfs-mode=755,tmpfs-size=10M \
		--mount type=tmpfs,destination=/run/php-fpm,tmpfs-mode=755,tmpfs-size=10M \
		$(ports) $(REGISTRY)$(NAME)

dist:
	tar -czf $(NAME).tar.gz editor src/ Dockerfile maintenance.sh nginx.conf start.sh 

.PHONY:
