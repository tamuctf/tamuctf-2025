# deployment vars
NAME := xorox

# ===========================================================
# NOTE: if not compiling, the $(NAME) dep long with compilation
# 	directive can be safely remove
# ============================================================

# build vars
CC := $(or $(CC),gcc)
CFLAGS := -O0 -s -masm=intel -mavx2

all: $(NAME)

$(NAME): main.c
	$(CC) $(CFLAGS) $^ -o $@

clean: .PHONY
	rm -f $(NAME) $(NAME).tar.gz

dist: $(NAME)
	tar -czf $(NAME).tar.gz $(NAME)

.PHONY:
