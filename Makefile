# --------- GLOBAL VARIABLES ----------
SHELL := bash
.SHELLFLAGS := -eu -o pipefail -c # strict bash mode
# set -e = exit if any command has non zero exit status
# set -u = exit if undefined var used
# set -o pipefail = get error code of any pipe failing
.DELETE_ON_ERROR:
# if a Make rule fails, it’s target file is deleted. This ensures the next time you run Make, it’ll properly re-run the failed rule, and guards against broken files.
MAKEFLAGS += --warn-undefined-variables # warn about Make variables that don’t exist


# --------- PROJECT VARIABLES ---------
NAME := libft.a
HEADER := libft.h
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := -rcs
RM := rm -rf

# --- LIBFT---
SRC_LIBFT :=	ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memmove.c \
		ft_strchr.c ft_strlen.c ft_strrchr.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_strdup.c ft_calloc.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_LIBFT_BONUS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
OBJ_LIBFT_BONUS = $(SRC_LIBFT_BONUS:.c=.o)

# --- PRINTF ---
DIR_PRINTF :=	printf/
SRC_PRINTF :=	$(DIR_PRINTF)ft_printf.c $(DIR_PRINTF)print_nbr.c $(DIR_PRINTF)print_addr.c \
		$(DIR_PRINTF)print_stdout.c $(DIR_PRINTF)print_hex.c $(DIR_PRINTF)print_unsigned.c
OBJ_PRINTF =	$(SRC_PRINTF:.c=.o)

# --- GET NEXT LINE ---
DIR_GNL :=	get_next_line/
SRC_GNL :=	$(DIR_GNL)get_next_line.c $(DIR_GNL)get_next_line_utils.c
OBJ_GNL =	$(SRC_GNL:.c=.o)
SRC_GNL_BONUS = $(DIR_GNL)get_next_line_utils_bonus.c $(DIR_GNL)get_next_line_bonus.c
OBJ_GNL_BONUS = $(SRC_GNL_BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	${AR} ${ARFLAGS} $(NAME) $(OBJ)

bonus: $(OBJ) ${OBJ_BONUS}
	${AR} ${ARFLAGS} $(NAME) $(OBJ) ${OBJ_BONUS}

%.o: %.c Makefile ${HEADER}
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ) ${OBJ_BONUS}

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
