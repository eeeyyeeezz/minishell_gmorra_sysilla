/*
;;;;;	MAKEFILE.H
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#ifndef MINISHELL_H
# define MINISHELL_H
# define READLINE_LIBRARY

# include <termcap.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include "../readline/include/readline/chardefs.h"
# include "../readline/include/readline/rlconf.h"
# include "../readline/include/readline/tilde.h"
# include "../readline/include/readline/rlstdc.h"
# include "../readline/include/readline/history.h"
# include "../readline/include/readline/keymaps.h"
# include "../readline/include/readline/readline.h"

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
#define N_S_F_D "minishell: no such file or directory:"
#define CMD_NF "command not found"


typedef	struct 			s_flags
{
	// int					flag;
	int					ft_arg;
	int					ft_cmd;
	int					d_flag;
	int					ft_error;
}						t_flags;


typedef	struct			s_pars {
	char				***args;
	// char				***args;
	int					*chr;
	// char				***args;
	char				**ft_cmd;
	char				*info;
	int					*pipis;
}						t_pars;

typedef	struct			s_history
{
	void				*content;
	struct s_history 	*next;
	struct s_history 	*prev;
}						t_history;

typedef struct s_env
{
	char		**sh_envp;
	char		*sh_path;
	char		*sh_term;
	char		*sh_name;
	char		*sh_lvl;
	int			cn;
	int			pip;
	int			basefd0;
	int			basefd1;
	int			pid[100];
	int			ispipe;
	int			isb_in;
	int			count_str;
	int			max_chr;
	int			status;
}				t_env;

typedef struct	s_sh
{
	int			sh_lvl;
	int			sh_mdepth;
}				t_sh;


typedef	struct			s_struct
{
	t_flags				flags;
	t_pars				pars;
	t_env				env;
	int					fd;
	char				*term_name;
	char				**envp;
	t_list				*path;
	t_history			*history;
}						t_struct;

t_pars					*pars_st_new();
int						str_in_str(char *haystack, char *needle);
void					print_double(char **arg, char *str);
void					print_aboba(char ***arg, char *str);
char					*find_chr_commands(t_struct *global, char *line);
int						count_malloc_chr(char *line);
int						count_twodimarray(char **array);
int						ft_isalnum_cd(int c);
void					pars_add_back(t_pars **lst, t_pars *new);
void					pars_unset(char *line, t_struct *global);
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
void					enter_pressed(t_struct *global, char *line);
void					ft_parser(t_struct *global, char *line);
int						ft_strcmp(char *s1, char *s2);
int						skip_cmd(char *big, char *little);
int						ft_isalnum_new(int c);
char					*encode_lines(char *line);
char					**decode_lines(char **encode_lines);
char					*quote_encode(char *line, int *i, char quote);
char					*skip_quote(char *line, char *str, int *i, char quote);
int						pars_arguments_line(char *line, t_struct *global);
void					pars_cd(char *line, t_struct *global);
char					*key_hook(char *str, char *line, t_struct *global);
char					*pars_dollar_sign(char *str, t_struct *global);
void					syntax_error(t_struct *global, char *line);
char					*ft_strjoin_new(char *s1, char *s2);
char					*ft_strjoin_char(char *s1, char s2);
void					pars_env(char *line, t_struct *global);
void					get_clean(t_struct *global, char **arg);
void					count_pipes(t_struct *global, int *line);
char					**fill_all_arguments(t_struct *global, char *line);
char					**get_all_commands(char *line, t_struct *global);
void					get_all_arguments(char *line, t_struct *global);
int						pars_characters(t_struct *global, char *line);
int						ft_ft_strnstr(char *big, char *little);
void					pars_echo(char *line, t_struct *global);
void					pars_export(char *line, t_struct *global);
void					ft_write(char *line, char *str, char *close);
int						pars_double_quotes(char *line, t_struct *global);
int						pars_without_quotes(char *line, t_struct *global);
void					ft_histclear(t_history **lst, void (*del)(void*));
void					ft_histadd_back(t_history **lst, t_history *new);
t_history				*ft_histnew(void *content);


// LOGIC

char			*ft_strjoin_slash(char const *s1, char const *s2);
int				ft_exit(char **ret, t_env *env);
char			*ft_strndup(const char *s, size_t n);
int				ft_strmasschr(char *what, char **where, int cmplen);
void			ft_envp_cpy(char *envp[], t_env *buf);
int				ft_env(char **av, t_env *sh_env);
int				ft_echo(char **arg);
int				ft_cd(char **argv, t_env *sh_env);
int				str_index(char *str, char c);
void			add_to_env(char *key, char *add, t_env *sh_envp);
int				ft_export(char **av, t_env *env);
int				cnt_str(char **src);
int				cnt_chr(char **src);
void			freemass(char **arr);
int				ft_err(char *err);
int				ft_unset(char **av, t_env *env);
int				lsh_exit(char **args);
void			shlvl(t_env *env);
void			add_to_env_plus(char *key, char *add, t_env *env);
char			*ft_strdup_clean(char *s1);
char			*ft_strjoin_clean(char *s1, char *s2);
int				lsh_execute(char **args, char **envp, t_struct *global);
void			start_pipe(t_env *env, char **args);
void			pipeline(char ***cmd, t_env *env);
void			chld_sig(void);
int				lsh_execute_pipe(char **args, char **envp, t_env *env);
int				exec_path(char **args, char **envp, t_env *env);
int				lsh_num_builtins();
int 			ft_isnum(char *str);
int				bildin(char **args, t_env *env);
char			*ft_strmasschr_char(char *what, char **where, int cmplen);
char			**ft_new_str(char **arr, char *new_str);
void			redidirecti(t_struct *global);

// \LOGIC

#endif
