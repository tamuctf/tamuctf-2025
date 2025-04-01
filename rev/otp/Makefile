NAME := otp
CFLAGS := -Wl,-z,relro,-z,now -g -static -flto

$(NAME): $(NAME).c
	gcc $(CFLAGS) $^ -o $@

clean:
	rm -rf $(NAME) $(NAME).tar.gz dump encrypted_flag.bin

docker: Dockerfile
	docker build --rm -t $(NAME) --build-arg name=$(NAME) .

extract: docker
	$(eval id := $(shell docker run --privileged -t -d $(NAME)))
	docker exec --privileged $(id) /$(NAME) flag.txt encrypted_flag.bin
	mkdir $(NAME)
	docker cp $(id):/$(NAME) $(NAME)/$(NAME)
	docker cp $(id):/dump $(NAME)
	docker cp $(id):/encrypted_flag.bin $(NAME)
	cp $(NAME).c $(NAME)
	docker container rm -f $(id)

dist: extract
	tar -czf $(NAME).tar.gz $(NAME)
