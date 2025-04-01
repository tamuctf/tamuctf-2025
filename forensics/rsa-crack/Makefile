NAME := rsa-crack

all: dist

clean: .PHONY
	rm -f $(NAME).tar.gz

dist:
	tar -czf $(NAME).tar.gz private_key.pem flag.txt.enc

.PHONY: