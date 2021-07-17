#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/

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

all:
	@gcc -g -ltermcap -lreadline -lreadline src/*.c src/parser/*.c src/logic/*.c ${LIBFT} ${READLINE} -o ${NAME} -g
#$(OUT_DIR) $(LIBFT) $(NAME)


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

$(NAME): $(LIBFT) $(OBJ) $(HEADER) ASCII_MINISHELL
	@$(CC) $(OBJ) $(INCLUDE) $(LIBFT) -o $(NAME) -lncurses
# @echo ${GREEN}'Compile completed!'${NORMAL}

$(LIBFT):
	@cd libft && make
	@echo ${GREEN}'Libft is assembled!'${NORMAL}

$(OUT_DIR):
	@$(MKDIR_P) $@
	@cd $(OUT_DIR) && $(MKDIR_P) $(OBJ_DIR)
	@cd $(OUT_DIR) && cd logic && $(MKDIR_P) env cd_pwd
	@echo ${GREEN}'$@ dir created!'${NORMAL}

ASCII_MINISHELL:
	@echo ${RED}'__/\\\\\\\\\____________/\\\\\\\\_________________________________________/\\\\\_________________________/\\\\\\\\\\\\_____/\\\\\\\\\\\\____'
	@echo '  _\/\\\\\\________/\\\\\\________________________________________\/\\\________________________\////\\\____\////\\\____'
	@echo '   _\/\\\//\\\____/\\\//\\\__/\\\________________/\\\______________\/\\\___________________________\/\\\_______\/\\\____'
	@echo '    _\/\\\\///\\\/\\\/_\/\\\_\///___/\\/\\\\\\___\///___/\\\\\\\\\\_\/\\\_____________/\\\\\\\\_____\/\\\_______\/\\\____'
	@echo '     _\/\\\__\///\\\/___\/\\\__/\\\_\/\\\////\\\___/\\\_\/\\\//////__\/\\\\\\\\\\____/\\\/////\\\____\/\\\_______\/\\\____ '
	@echo '      _\/\\\____\///_____\/\\\_\/\\\_\/\\\__\//\\\_\/\\\_\/\\\\\\\\\\_\/\\\/////\\\__/\\\\\\\\\\\_____\/\\\_______\/\\\____'
	@echo '       _\/\\\_____________\/\\\_\/\\\_\/\\\___\/\\\_\/\\\_\////////\\\_\/\\\___\/\\\_\//\\///////______\/\\\_______\/\\\____'
	@echo '        _\/\\\_____________\/\\\_\/\\\_\/\\\___\/\\\_\/\\\__/\\\\\\\\\\_\/\\\___\/\\\__\//\\\\\\\\\\__/\\\\\\\\\__/\\\\\\\\\_'
	@echo '         _\///______________\///__\///__\///____\///__\///__\//////////__\///____\///____\//////////__\/////////__\/////////__'${NORMAL}

READLINE = readline/lib/libhistory.a readline/lib/libreadline.a

RUN:
	@gcc -Wall -Wextra -g -ltermcap -lreadline -lreadline src/*.c src/parser/*.c src/logic/*.c ${LIBFT} ${READLINE} -o ${NAME}
	
	@./minishell

re: fclean all

clean:
	@rm -rf $(OUT_DIR)
	@cd libft && make fclean
	@echo ${RED}'$(OUT_DIR) clean'${NORMAL}

fclean: clean
	@rm -f $(NAME)
	@echo ${RED}'$(NAME) clean'${NORMAL}

PHONY: re clean fclean all
