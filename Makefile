#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/

NAME	= minishell

HEADER	= includes/minishell.h

SRC		=	src/main.c \
			src/main_utils.c \
			src/parser/encode_lines.c\
			src/parser/ft_isalnum_new.c\
			src/parser/get_all_arguments.c\
			src/parser/get_dollar_utils_2.c\
			src/parser/find_chr_commands.c\
			src/parser/ft_parser.c\
			src/parser/get_all_commands.c\
			src/parser/plus_end_begin.c\
			src/parser/ft_error.c\
			src/parser/ft_putchar.c\
			src/parser/get_dollar.c\
			src/parser/syntax_error.c\
			src/parser/ft_escape.c\
			src/parser/ft_strjoin_new.c\
			src/parser/get_dollar_utils.c\
			src/parser/utils.c\

SRC_LOGIC = src/logic/cd.c\
			src/logic/export.c\
			src/logic/libft_utils_2.c\
			src/logic/shlvl.c\
			src/logic/tr_lsh_exec.c\
			src/logic/echo.c\
			src/logic/for_redirects.c\
			src/logic/lsh_exec.c\
			src/logic/tr_env.c\
			src/logic/tr_pipe.c\
			src/logic/env.c\
			src/logic/ft_pwd.c\
			src/logic/tr_env2.c\
			src/logic/unset.c\
			src/logic/exec_pipe.c\
			src/logic/libft_utils.c\
			src/logic/redirects.c\
			src/logic/tr_export.c\

CC		= gcc

LIBFT = libft/libft.a

READLINE = readline/lib/libhistory.a readline/lib/libreadline.a

CFLAGS = -Wall -Wextra -Werror -ltermcap -lreadline -lreadline

INCLUDE = -Iincludes

SRC_DIR = $(addprefix src/, $(SRC))

OBJ		= $(patsubst src/%.c, obj/%.o, $(SRC_DIR))

OUT_DIR = obj

OBJ_DIR	=	parser \
			get_next_line \
			logic

MKDIR_P	= mkdir -p

all: ${NAME}

${NAME}:
	@gcc -g ${CFLAGS} ${SRC} ${SRC_LOGIC} ${LIBFT} ${READLINE} -o ${NAME} -g
	@echo ${RED}'__/\\\\\\\\\____________/\\\\\\\\_________________________________________/\\\\\_________________________/\\\\\\\\\\\\_____/\\\\\\\\\\\\____'
	@echo '  _\/\\\\\\________/\\\\\\________________________________________\/\\\________________________\////\\\____\////\\\____'
	@echo '   _\/\\\//\\\____/\\\//\\\__/\\\________________/\\\______________\/\\\___________________________\/\\\_______\/\\\____'
	@echo '    _\/\\\\///\\\/\\\/_\/\\\_\///___/\\/\\\\\\___\///___/\\\\\\\\\\_\/\\\_____________/\\\\\\\\_____\/\\\_______\/\\\____'
	@echo '     _\/\\\__\///\\\/___\/\\\__/\\\_\/\\\////\\\___/\\\_\/\\\//////__\/\\\\\\\\\\____/\\\/////\\\____\/\\\_______\/\\\____ '
	@echo '      _\/\\\____\///_____\/\\\_\/\\\_\/\\\__\//\\\_\/\\\_\/\\\\\\\\\\_\/\\\/////\\\__/\\\\\\\\\\\_____\/\\\_______\/\\\____'
	@echo '       _\/\\\_____________\/\\\_\/\\\_\/\\\___\/\\\_\/\\\_\////////\\\_\/\\\___\/\\\_\//\\///////______\/\\\_______\/\\\____'
	@echo '        _\/\\\_____________\/\\\_\/\\\_\/\\\___\/\\\_\/\\\__/\\\\\\\\\\_\/\\\___\/\\\__\//\\\\\\\\\\__/\\\\\\\\\__/\\\\\\\\\_'
	@echo '         _\///______________\///__\///__\///____\///__\///__\//////////__\///____\///____\//////////__\/////////__\/////////__'${NORMAL}
	@echo ${GREEN}"Compile done!"${NORMAL}



obj/%.o:	src/%.c
	@$(CC) -g $(CFLAGS) -c $< -o $@

# COLORS

RED = "\033[0;31m"
BLUE = "\033[0;34m"
YELLOW = "\033[0;33m"
WHITE = "\033[1;37m"
GREEN = "\033[0;32m"
PURPLE = "\033[0;35m"
GRAY = "\033[1;30m"
NORMAL = "\033[0m"
MARK = "U+2713"

# /COLORS

RUN:
	@gcc -Wall -Wextra ${CFLAGS} ${SRC} ${SRC_LOGIC} ${LIBFT} ${READLINE} -o ${NAME}
	@./minishell

re: fclean all

clean:
	@rm -rf src/*.o
	@echo ${RED}'$(OUT_DIR) clean'${NORMAL}

fclean: clean
	@rm -f ${NAME}
	@echo ${RED}'$(NAME) clean'${NORMAL}

PHONY: re clean fclean all
