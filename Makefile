# --------- GLOBAL VARIABLES ----------
SHELL := bash
#.SHELLFLAGS := -eu -o pipefail -c # strict bash mode
## set -e = exit if any command has non zero exit status
## set -u = exit if undefined var used
## set -o pipefail = get error code of any pipe failing

.DELETE_ON_ERROR:
## if a Make rule fails, it’s target file is deleted. This ensures the next time you run Make, it’ll properly re-run the failed rule, and guards against broken files.
MAKEFLAGS += --warn-undefined-variables # warn about Make variables that don’t exist


# --------- PROJECT VARIABLES ---------
NAME := libft.a
HEADER := header/libft.h
CFLAGS := -Wall -Wextra -Werror
FSANITIZE = -fsanitize=address
ARFLAGS := -rcs
RM := rm -rf

SRC_FOLDER := src/
SRC = $(addprefix $(SRC_FOLDER), $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL))

#DIRS = $(addprefix $(SRC_FOLDER),$(DIR_LIBFT) $(DIR_PRINTF) $(DIR_GNL))

OBJ_DIR := obj/
OBJ = $(subst $(SRC_FOLDER),$(OBJ_DIR),$(SRC:.c=.o))


# ---- LIBFT----
DIR_LIBFT := $(SRC_FOLDER)libft/
SRC_LIBFT := ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memmove.c \
		ft_strchr.c ft_strlen.c ft_strrchr.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_strdup.c ft_calloc.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


# ---- PRINTF ----
DIR_PRINTF := $(SRC_FOLDER)printf/
SRC_PRINTF := ft_printf.c print_nbr.c print_addr.c print_stdout.c print_hex.c print_unsigned.c


# ---- GET NEXT LINE ----
DIR_GNL := $(SRC_FOLDER)get_next_line/
SRC_GNL := get_next_line.c get_next_line_utils.c


# --------- RECIPES ---------
all: makefolder $(NAME)

#print : $(DIRS)*.c
#	@echo "$<"
#	@echo "loli $(DIRS)"

$(NAME): $(OBJ)
	${AR} ${ARFLAGS} $(NAME) $(OBJ)

#$(OBJ_DIR)%.o : $(DIRS)%.c
#	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(DIR_LIBFT)%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(DIR_PRINTF)%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(DIR_GNL)%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

makefolder :
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) test.out

re: fclean
	make all

debug : libft/libft.a
	cc $(FSANITIZE) -Wall -Wextra -Werror $(SRC) -L ./libft -lft -o $(NAME)_debug  && ./$(NAME)_debug $(ARG) && echo "" && ./$(NAME)_debug $(ARG) | ./checker $(ARG)

test: all
	@${CC} -o test.out tests.c $(NAME)
	@./test.out | cat -e

.PHONY: all bonus makefolder clean fclean re debug test
