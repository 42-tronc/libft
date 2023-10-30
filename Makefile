# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 13:33:54 by croy              #+#    #+#              #
#    Updated: 2023/10/30 17:21:00 by croy             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# --------- GLOBAL VARIABLES ----------
SHELL := bash
.SHELLFLAGS := -eu -o pipefail -c # strict bash mode
## set -e = exit if any command has non zero exit status
## set -u = exit if undefined var used
## set -o pipefail = get error code of any pipe failing

.DELETE_ON_ERROR:
## if a Make rule fails, it’s target file is deleted. This ensures the next time you run Make, it’ll properly re-run the failed rule, and guards against broken files.
MAKEFLAGS += --warn-undefined-variables # warn about Make variables that don’t exist

# --------- FORMATTING ----------
# see https://misc.flogisoft.com/bash/tip_colors_and_formatting
FG_BLACK 			:= \033[30m
FG_RED 				:= \033[31m
FG_GREEN 			:= \033[32m
FG_YELLOW 			:= \033[33m
FG_BLUE 			:= \033[34m
FG_MAGENTA 			:= \033[35m
FG_CYAN 			:= \033[36m
FG_LIGHT_GRAY 		:= \033[37m
FG_DEFAULT 			:= \033[39m
FG_DARK_GRAY 		:= \033[90m
FG_LIGHT_RED 		:= \033[91m
FG_LIGHT_GREEN 		:= \033[92m
FG_LIGHT_YELLOW 	:= \033[93m
FG_LIGHT_BLUE 		:= \033[94m
FG_LIGHT_MAGENTA 	:= \033[95m
FG_LIGHT_CYAN 		:= \033[96m
FG_WHITE 			:= \033[97m

BG_BLACK 			:= \033[40m
BG_RED 				:= \033[41m
BG_GREEN 			:= \033[42m
BG_YELLOW 			:= \033[43m
BG_BLUE 			:= \033[44m
BG_MAGENTA 			:= \033[45m
BG_CYAN 			:= \033[46m
BG_LIGHT_GRAY 		:= \033[47m
BG_DEFAULT 			:= \033[49m
BG_DARK_GRAY 		:= \033[100m
BG_LIGHT_RED 		:= \033[101m
BG_LIGHT_GREEN 		:= \033[102m
BG_LIGHT_YELLOW 	:= \033[103m
BG_LIGHT_BLUE 		:= \033[104m
BG_LIGHT_MAGENTA 	:= \033[105m
BG_LIGHT_CYAN 		:= \033[106m
BG_WHITE 			:= \033[107m

BOLD		:= \033[1m
DIM			:= \033[2m
ITALIC		:= \033[3m
UNDERLINE	:= \033[4m
BLINK		:= \033[5m
REVERSE		:= \033[7m
HIDDEN		:= \033[8m
STRIKED		:= \033[9m
RESET		:= \033[0m


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
SRC_LIBFT := ft_arrlen.c ft_atoi.c ft_isalpha.c ft_countchar.c ft_isprint.c ft_memcpy.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memmove.c \
	ft_strchr.c ft_strlen.c ft_strrchr.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strcat.c ft_strlcat.c ft_strcmp.c ft_strncmp.c ft_tolower.c ft_strdup.c ft_strndup.c \
	ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


# ---- PRINTF ----
DIR_PRINTF := $(SRC_FOLDER)printf/
SRC_PRINTF := ft_printf.c print_nbr.c print_addr.c print_stdout.c print_hex.c print_unsigned.c


# ---- GET NEXT LINE ----
DIR_GNL := $(SRC_FOLDER)get_next_line/
SRC_GNL := get_next_line.c get_next_line_utils.c


# --------- RECIPES ---------
all: makefolder $(NAME)

$(NAME): $(OBJ)
	${AR} ${ARFLAGS} $(NAME) $(OBJ)
	@echo -e "$(BG_LIGHT_GREEN)Compiled:\t$(RESET) $(FG_WHITE)$(UNDERLINE)$(NAME)$(RESET) has been created"

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
	@echo -e "$(FG_RED)Clean:\t\t $(FG_LIGHT_GRAY)$(ITALIC)$(NAME) object files$(RESET) have been deleted"

fclean: clean
	$(RM) $(NAME)
	$(RM) test.out
	@echo -e "$(FG_RED)FClean:\t\t $(FG_LIGHT_GRAY)$(UNDERLINE)$(NAME)$(RESET) has been deleted"

re: fclean
	make all

# TODO fix this command
debug : $(NAME)
	$(CC) $(CFLAGS) $(FSANITIZE) $(SRC) -L ./libft -lft -o $(NAME)_debug  && ./$(NAME)_debug $(ARG) && echo "" && ./$(NAME)_debug $(ARG) | ./checker $(ARG)

leaks : all
	@echo "Arg='$(ARG)'"
	leaks -atExit -- ./$(NAME) $(ARG)

test: all
	${CC} -o test.out tests.c $(NAME)
	@./test.out | cat -e

print:
	@echo -e "$(RESET)regular$(RESET)"
	@echo -e "$(BOLD)bold$(RESET)"
	@echo -e "$(DIM)dim$(RESET)"
	@echo -e "$(ITALIC)loli$(RESET)"
	@echo -e "$(UNDERLINE)underline$(RESET)"
	@echo -e "$(BLINK)blink$(RESET)"
	@echo -e "$(REVERSE)reverse$(RESET)"
	@echo -e "$(HIDDEN)hidden$(RESET)"
	@echo -e "$(STRIKED)striked$(RESET)"
	@echo -e "$(LOLI)loli$(RESET)"
	@echo -e "$(RESET)reset$(RESET)"

.PHONY: all makefolder clean fclean re debug test
.SILENT:
