# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:04:21 by fdagbert          #+#    #+#              #
#    Updated: 2022/12/01 20:21:30 by fdagbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=\x1b[0m
RESET=\033[0m
BLACK=\033[0;30m
RED=\033[0;31m
GREEN =\033[32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m

NAME = fractol

SRC_PATH = src
LIB_PATH = lib
OBJ_PATH = obj
INC_PATH = include

LIBFT = libft.a
LIBPTF = libftprintf.a
LIBMLX = libmlx.a

LIBFT_PATH = $(LIB_PATH)/libft
LIBPTF_PATH = $(LIB_PATH)/ft_printf
LIBMLX_PATH = $(LIB_PATH)/minilibx-linux

FRACT_FCT = main.c											\
			ft_init_conf.c									\
			ft_init_names.c									\
			ft_init_colors.c								\
			ft_check_args.c									\
			ft_check_opt_arg.c								\
			ft_init_grid.c									\
			ft_init_border.c								\
			ft_set_grid.c									\
			ft_set_fractal.c								\
			ft_set_buddha.c									\
			ft_set_pthr.c									\
			ft_set_ssaa.c									\
			ft_set_img.c									\
			ft_set_gradient.c								\
			ft_set_hsv.c									\
			fractal_multibrot.c								\
			fractal_buddhabrot.c							\
			fractal_newton.c								\
			fractal_sierpinski.c							\
			fractal_barnsley.c								\
			ft_bresenham.c									\
			ft_start_hook.c									\
			ft_press_key.c									\
			ft_press_key_letter.c							\
			ft_set_fdf.c									\
			ft_get_date.c									\
			ft_str_date.c									\
			hook_move_mouse.c								\
			hook_move_axes.c								\
			hook_move_c.c									\
			hook_clean.c									\
			hook_parameter.c								\
			hook_mode.c										\
			hook_roll.c										\
			hook_bkg.c										\
			hook_rgb.c										\
			hook_hsv.c										\
			hook_psy.c										\
			ft_print_buddha.c								\
			ft_print_nebula.c								\
			ft_print_hud.c									\
			ft_print_infos.c								\
			ft_print_params.c								\
			ft_print_colors.c								\
			ft_print_modes.c								\
			ft_print_full_cmd.c								\
			ft_print_full_next.c							\
			ft_end.c											
FRACT_SRC = $(addprefix $(SRC_PATH)/,$(FRACT_FCT))

FRACT_OBJ = $(FRACT_FCT:.c=.o)
FRACT_OBJ_SRC = $(addprefix $(OBJ_PATH)/,$(FRACT_OBJ))

OBJECTS = $(FRACT_OBJ_SRC)

HEAD_SRC = $(LIBFT_PATH)/$(INC_PATH)/libft.h				\
		   $(LIBFT_PATH)/$(INC_PATH)/ft_get_next_line.h		\
		   $(LIBPTF_PATH)/$(INC_PATH)/ft_printf.h			\
		   $(LIBMLX_PATH)/mlx.h								\
		   $(LIBMLX_PATH)/mlx_int.h							\
		   $(INC_PATH)/errors.h								\
		   $(INC_PATH)/colors.h								\
		   $(INC_PATH)/keys_linux.h							\
		   $(INC_PATH)/structs.h							\
		   $(INC_PATH)/fractol.h

CC = clang
CFLAGS = -Wall -Wextra -Werror -Ofast
DFLAGS = -fsanitize=address

LIBPTF_FLAGS = -L$(LIB_PATH)/ft_printf -lftprintf
LBX_FLAGS = -L$(LIB_PATH)/minilibx-linux -lX11 -lXext -lmlx -lm -lbsd
PTHR_FLAGS = -lpthread

INCLUDES = $(LIBFT_PATH)/$(INC_PATH) $(LIBPTF_PATH)/$(INC_PATH) $(LIBMLX_PATH) \
			$(INC_PATH)
INC_CC = $(foreach DIR,$(INCLUDES),-I$(DIR))

.PHONY: all, clean, fclean, re, lib

all:
	@printf "$(YELLOW)"
	@$(MAKE) $(NAME)
	@printf "$(RESET)"

$(NAME): $(LIBFT_PATH)/$(LIBFT) $(LIBPTF_PATH)/$(LIBPTF) $(OBJECTS)
	@printf "$(PURPLE)Compiling... $(RESET)"
	@$(CC) -o $(NAME) $(OBJECTS) $(INC_CC) $(LIBPTF_FLAGS) $(LBX_FLAGS) \
				$(PTHR_FLAGS)
	@printf "$(GREEN)$(NAME) is ready ! ✓\n$(YELLOW)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEAD_SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@printf "$(PURPLE)Compiling... $<$(RESET)"
	@$(CC) -g $(CFLAGS) $(INC_CC) -o $@ -c $<
	@printf "$(PURPLE) OK\n$(RESET)"

$(LIBFT_PATH)/$(LIBFT): lib

lib:
	@printf "$(YELLOW)"
	@$(MAKE) -C $(LIBMLX_PATH)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(LIBPTF_PATH)

clean:
	@printf "$(YELLOW)"
	@$(MAKE) -C $(LIBMLX_PATH) clean
	@printf "$(YELLOW)"
	@$(MAKE) -C $(LIBFT_PATH) clean
	@printf "$(YELLOW)"
	@$(MAKE) -C $(LIBPTF_PATH) clean
	@printf "$(RED)"
	@rm -fv $(OBJECTS)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@rm -fv $(DSYM)
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED)"
	@rm -fv $(LIBFT_PATH)/$(LIBFT)
	@rm -fv $(LIBPTF_PATH)/$(LIBPTF)
	@rm -fv $(NAME)
	@printf "$(RESET)"

re: fclean all
