# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 18:49:56 by gmorra            #+#    #+#              #
#    Updated: 2021/05/21 16:49:19 by ncliff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

HEADER	= includes/get_next_line.h includes/minishell.h

SRC		=	main.c \
			str_fnc.c\
			parser/encode_lines.c\
			parser/pars_unset.c\
			parser/hist_lst.c\
			parser/pars_line.c\
			parser/open_file_history.c\
			parser/pars_characters.c\
			parser/syntax_error.c\
			parser/pars_cd.c\
			parser/key_hook.c\
			parser/pars_env.c\
			parser/init_termios.c\
			parser/ft_escape.c \
			parser/ft_putchar.c \
			parser/ft_strnstr.c \
			parser/ft_isalnum_new.c\
			parser/ft_strjoin_new.c \
			parser/skip_cmd.c \
			parser/pocket_printf.c\
			parser/ft_error.c \
			parser/ft_parser.c \
			parser/pars_echo.c \
			logic/logic_choice.c\
			logic/env/env_func.c \
			logic/env/export_func.c \
			logic/env/export_env.c \
			logic/env/path_pars.c \
			logic/env/env_cp_sort.c \
			logic/env/unset_func.c \
			logic/cd_pwd/cd_func.c \
			parser/pars_export.c \
			parser/get_env_info.c\
			parser/pars_double_quotes.c \
			parser/pars_without_quotes.c \
			parser/find_redirects_pipes.c\
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c


CC		= gcc

LIBFT = libft/libft.a

CFLAGS =

INCLUDE = -Iincludes

SRC_DIR = $(addprefix src/, $(SRC))

OBJ		= $(patsubst src/%.c, obj/%.o, $(SRC_DIR))

OUT_DIR = obj

OBJ_DIR	=	parser \
			get_next_line \
			logic

MKDIR_P	= mkdir -p

all: $(OUT_DIR) $(LIBFT) $(NAME)

obj/%.o:	src/%.c
	$(CC) -g $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(INCLUDE) $(LIBFT) -o $(NAME) -lncurses
	@echo '$(cgreen)Good compile!$(cwhite)'

$(LIBFT):
	@cd libft && make
	@echo '$(cgreen)Libft compile$(cwhite)'

$(OUT_DIR):
	@$(MKDIR_P) $@
	@cd $(OUT_DIR) && $(MKDIR_P) $(OBJ_DIR)
	@cd $(OUT_DIR) && cd logic && $(MKDIR_P) env cd_pwd
	@echo '$(cgreen)$@ dir create$(cwhite)'
	@echo "\033[1A"

RUN:
	@gcc -g ${SRC_DIR} ${LIBFT} -lncurses -o ${NAME}
	@./minishell

re: fclean all

clean:
	@/bin/rm -rf $(OUT_DIR)
	@cd libft && make fclean
	@echo '$(ccred)$(OUT_DIR) delete$(cwhite)'

fclean: clean
	@/bin/rm -f $(NAME)
	@echo '$(ccred)$(NAME) file delete$(cwhite)'

cgreen=$(shell echo "\033[1;32m")
ccred=$(shell echo "\033[1;31m")
cwhite=$(shell echo "\033[1;0m")
