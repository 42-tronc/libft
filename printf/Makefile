NAME := libftprintf.a
HEADER := ft_printf.h

CC := gcc
CFLAGS := -Wall -Wextra -Werror
AR := ar
ARFLAGS := -rcs
RM := rm -rf

SRC := ft_printf.c \
	print_addr.c \
	print_hex.c \
	print_nbr.c \
	print_stdout.c \
	print_unsigned.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

test: $(NAME)
	@${CC} -o lol.out tests.c $(NAME)
	./lol.out
	@$(RM) lol.out $(OBJ) $(NAME)

$(NAME): $(OBJ)
	${AR} ${ARFLAGS} $(NAME) $(OBJ)

%.o: %.c Makefile ${HEADER}
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
