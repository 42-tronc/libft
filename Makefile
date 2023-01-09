# --------- GLOBAL VARIABLES ----------
#SHELL := bash
#.SHELLFLAGS := -eu -o pipefail -c # strict bash mode
## set -e = exit if any command has non zero exit status
## set -u = exit if undefined var used
## set -o pipefail = get error code of any pipe failing
#.DELETE_ON_ERROR:
## if a Make rule fails, it’s target file is deleted. This ensures the next time you run Make, it’ll properly re-run the failed rule, and guards against broken files.
#MAKEFLAGS += --warn-undefined-variables # warn about Make variables that don’t exist


# --------- PROJECT VARIABLES ---------
NAME := libft.a
HEADER := libft.h
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := -rcs
RM := rm -rf

SRC = $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL_BONUS)

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

# ---- LIBFT----
DIR_LIBFT := libft/
HEADER_LIBFT := libft.h
SRC_LIBFT := ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memmove.c \
		ft_strchr.c ft_strlen.c ft_strrchr.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_strdup.c ft_calloc.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
## - BONUS -
#SRC_LIBFT_BONUS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


# ---- PRINTF ----
DIR_PRINTF := printf/
HEADER_PRINTF := ft_printf.h
SRC_PRINTF = ft_printf.c print_nbr.c print_addr.c print_stdout.c print_hex.c print_unsigned.c


# ---- GET NEXT LINE ----
DIR_GNL := get_next_line/
HEADER_GNL := get_next_line.h
SRC_GNL := get_next_line.c get_next_line_utils.c
## - BONUS -
HEADER_GNL_BONUS := get_next_line_bonus.h
SRC_GNL_BONUS = get_next_line_utils_bonus.c get_next_line_bonus.c


# --------- RECIPES ---------
all: makefolder $(NAME)

$(NAME): $(OBJ)
	${AR} ${ARFLAGS} $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(DIR_LIBFT)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(DIR_PRINTF)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(DIR_GNL)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

makefolder :
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ) ${OBJ_BONUS}
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
