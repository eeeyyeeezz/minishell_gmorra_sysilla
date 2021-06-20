NAME := minishell

all: $(NAME) 

$(NAME):
		gcc main.c bildin/shlvl.c bildin/cd.c bildin/echo.c bildin/env.c bildin/export.c bildin/header.h bildin/tr_env.c bildin/unset.c liba/libft.a -g