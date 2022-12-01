# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 17:34:44 by fdagbert          #+#    #+#              #
#    Updated: 2020/08/12 19:06:51 by fdagbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m

NAME = libft.a

SRC_PATH = src
FUNCTIONS = ft_bzero.c			\
			ft_memset.c			\
			ft_memmove.c		\
			ft_strlen.c			\
			ft_wcslen.c			\
			ft_isdigit.c		\
			ft_atoi.c			\
			ft_itoa.c			\
			ft_strcat.c			\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_strnew.c			\
			ft_strchr.c			\
			ft_strjoin.c		\
			ft_strcmp.c			\
			ft_get_next_line.c	\
			ft_abs.c			\
			ft_fabs.c			\
			ft_dabs.c			\
			ft_add_c.c			\
			ft_sub_c.c			\
			ft_mult_c.c			\
			ft_div_c.c			\
			ft_pow_c.c
SRC = $(addprefix $(SRC_PATH)/, $(FUNCTIONS))

OBJ_PATH = obj
OBJ_SRC = $(FUNCTIONS:.c=.o)
OBJECTS = $(addprefix $(OBJ_PATH)/, $(OBJ_SRC))

INC_PATH = include
INC_SRC = $(INC_PATH)/libft.h				\
		  $(INC_PATH)/ft_get_next_line.h

INC_CC = -I$(INC_PATH)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "$(CYAN)Compiling... $(RESET)"
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "$(GREEN)$(NAME) is ready ! ✓\n$(YELLOW)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@printf "$(CYAN)Compiling... $<$(RESET)"
	@$(CC) -g $(CFLAGS) $(INC_CC) -o $@ -c $<
	@printf "$(CYAN) OK\n$(RESET)"

clean:
	@printf "$(RED)"
	@rm -fv $(OBJECTS)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@printf "$(YELLOW)"

fclean: clean
	@printf "$(RED)"
	@rm -fv $(NAME)
	@printf "$(RESET)"

re: fclean all
