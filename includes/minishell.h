#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef	struct 			s_flags
{
	int					flag;
}						t_flags;


typedef	struct			s_pars {
	t_list				*arg;
	// char				**execve_args;
	int					cmd;
	int					chr;
	char				*info_env;
	char				*first_line;
	char				*first_word;
	char				*info;
	struct s_pars		*next;
}						t_pars;

typedef	struct			s_history
{
	void				*content;
	struct s_history 	*next;
	struct s_history 	*prev;
}						t_history;

typedef	struct			s_struct
{
	char				*term_name;
	t_flags				flags;
	t_pars				pars;
	char				**env;
	t_list				*path;
	t_history			*history;
	int					fd;
}						t_struct;

t_pars					*pars_st_new();
int						ft_isalnum_cd(int c);
void					pars_add_back(t_pars **lst, t_pars *new);
void					pars_unset(char *line, t_struct *global);
void					ft_exit();
int						ft_chr(char s);
void					write_minishell();
int						chr_to_int(char s, char next);
void					ft_free(void **var);
int						ft_strlen_array(char **arr);
int						count_arguments(char *line, int begin);
void					gnl_history_to_list(t_struct *global);
void					open_file_history(char *line, t_struct *global);
void					init_termios(t_struct *global);
void					init_all(t_struct *global);
int						key_escape(char *str);
int						ft_escape(char s);
void					ft_error(char *str);
void					ft_putstr(char *s);
int						ft_putchar(int word);
int						ft_issleter(char s);
int						ft_isspaces(char word);
void					ft_parser(t_struct *global);
int						ft_strcmp(char *s1, char *s2);
int						skip_cmd(char *big, char *little);
int						ft_isalnum_new(int c);
char					*encode_lines(char *line);
char					**decode_lines(char **encode_lines);
char					*quote_encode(char *line, int *i, char quote);
char					*skip_quote(char *line, char *str, int *i, char quote);
int						pars_arguments_line(char *line, t_struct *global);
void					pars_cd(char *line, t_struct *global);
void					syntax_error(char *line, t_struct *global);
char					*key_hook(char *str, char *line, t_struct *global);
char					*pars_dollar_sign(char *str, t_struct *global);
void					syntax_error(char *line, t_struct *global);
char					*ft_strjoin_new(char *s1, char *s2);
char					*ft_strjoin_char(char *s1, char s2);
void					pars_env(char *line, t_struct *global);
int						pars_characters(char *line, t_struct *global);
void					find_redirects_pipes(char *line, t_struct *global);
int						ft_ft_strnstr(char *big, char *little);
void					pars_echo(char *line, t_struct *global);
void					pars_export(char *line, t_struct *global);
void					ft_write(char *line, char *str, char *close);
int						pars_double_quotes(char *line, t_struct *global);
int						pars_without_quotes(char *line, t_struct *global);
void					ft_histclear(t_history **lst, void (*del)(void*));
void					ft_histadd_back(t_history **lst, t_history *new);
t_history				*ft_histnew(void *content);


#endif
