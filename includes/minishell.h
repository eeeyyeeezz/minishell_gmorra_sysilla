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
# include "../readline/include/readline/chardefs.h"
# include "../readline/include/readline/rlconf.h"
# include "../readline/include/readline/tilde.h"
# include "../readline/include/readline/rlstdc.h"
# include "../readline/include/readline/history.h"
# include "../readline/include/readline/keymaps.h"
# include "../readline/include/readline/readline.h"

# define LSH_RL_BUFSIZE 1024
# define LSH_TOK_BUFSIZE 64
# define LSH_TOK_DELIM " \t\r\n\a"
# define N_S_F_D "minishell: no such file or directory:"
# define CMD_NF "command not found"
# define N_V_I "not a valid identifier"
# define U_CHR unsigned char
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RES "\e[0m"

typedef struct s_flags
{
	int					count;
	int					chr_count;
	int					cmd_count;
	int					flag_quote;
	int					flag_dollar_error;
	int					get_strlen;
	int					begin;
	int					str_end;
	int					end;
	int					ft_arg;
	int					ft_cmd;
	int					d_flag;
	int					ft_error;
}						t_flags;

typedef struct s_pars {
	char				***ft_pipes;
	char				***args;
	char				**ft_cmd;
	int					*chr;
	char				*info;
}						t_pars;

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

typedef struct s_struct
{
	t_flags				flags;
	t_pars				pars;
	t_env				env;
	int					fd;
	char				*term_name;
	char				**envp;
	t_list				*path;
}						t_struct;

void					free_all(t_struct *global);

int						ft_escape(char s);
void					ft_error(char *str);
void					ft_putstr(char *s);
int						ft_putchar(int word);
int						ft_issleter(char s);
int						ft_isspaces(char word);
void					ft_parser(t_struct *global, char *line);
char					*skip_quote(char *line, char *str, int *i, char quote);
int						skip_quote_i(char *line, char quote);
int						str_in_str(char *haystack, char *needle);
void					print_double(char **arg, char *str);
void					print_aboba(char ***arg, char *str);
int						count_malloc_chr(char *line);
int						count_twodimarray(char **array);
int						ft_isalnum_cd(int c);
void					pars_add_back(t_pars **lst, t_pars *new);
void					pars_unset(char *line, t_struct *global);
int						ft_chr(char s);
int						chr_to_int(char s, char next);
void					ft_free(void **var);
int						ft_strlen_array(char **arr);
int						count_arguments(char *line, int begin);
void					init_all(t_struct *global);
int						ft_isalnum_new(int c);
char					*encode_lines(char *line);
int						plus_end(char *line, int end);
int						plus_begin(char *line, int begin, int end);
char					**decode_lines(char **encode_lines);
char					*quote_encode(char *line, int *i, char quote);
char					*skip_quote(char *line, char *str, int *i, char quote);
void					syntax_error(t_struct *global, char *line);
char					*ft_strjoin_new(char *s1, char *s2);
char					*ft_strjoin_char(char *s1, char s2);
char					*find_chr_commands(t_struct *global, char *line);
void					get_all_arguments(t_struct *global, char *line);
char					**fill_all_arguments(t_struct *global, char *line);
char					**get_all_commands(t_struct *global, char *line);
int						pars_characters(t_struct *global, char *line);
int						ft_ft_strnstr(char *big, char *little);
void					make_pipe_array(t_struct *global);
void					skip_single_quote(char *line, int *i);
char					*get_whole_str(char *str,
							char *old_str, int begin, int get_strlen);
char					*get_old_str(char *str, int begin);
char					*connect_dollar_string(char *str,
							char *dollar_str, int begin, int get_strlen);
int						itterate_end(t_struct *global, char *line, int *i);
char					*get_str(t_struct *global, char *str,
							char *dollar_str, int begin);
char					*dollar_error(t_struct *global,
							char *dollar_str, char *str);
char					*get_dollar(t_struct *global, char *line,
							char *str, int end);
char					*change_dollar_string(t_struct *global,
							char *dollar_string);

// LOGIC
int						double_right(char *name);
int						single_right(char *name);
int						single_left(char *name);
char					**until_stop(char *stop);
void					double_left(char *stop, char **command,
							t_struct *global);
void					chld_sig(void);
int						ft_isnum(char *str);
void					print_sortmass(char **sort_mass);
int						pwd(t_env *env);
void					export_plus(char *av, t_env *env, int index_eq);
int						ft_isnu(char *s);
void					in_export_while(char **av, t_env *env, int index_eq,
							int i);
void					pid_nonzero(t_env *env, int status, int *fd);
int						builtin_func2(char **args, t_env *env, int i);
char					*ft_strjoin_slash(char const *s1, char const *s2);
int						ft_exit(char **ret, t_env *env);
char					*ft_strndup(const char *s, size_t n);
int						ft_strmasschr(char *what, char **where, int cmplen);
void					ft_envp_cpy(char *envp[], t_env *buf);
int						ft_env(char **av, t_env *sh_env);
int						ft_echo(char **arg);
int						ft_cd(char **argv, t_env *sh_env);
int						str_index(char *str, char c);
void					add_to_env(char *key, char *add, t_env *sh_envp);
int						ft_export(char **av, t_env *env);
int						cnt_str(char **src);
int						cnt_chr(char **src);
void					freemass(char **arr);
int						ft_err(char *err);
int						ft_unset(char **av, t_env *env);
int						lsh_exit(char **args);
void					shlvl(t_env *env);
void					add_to_env_plus(char *key, char *add, t_env *env);
char					*ft_strdup_clean(char *s1);
char					*ft_strjoin_clean(char *s1, char *s2);
int						lsh_execute(char **args, t_struct *global);
void					start_pipe(t_env *env, char **args);
void					pipeline(char ***cmd, t_env *env);
void					chld_sig(void);
int						lsh_execute_pipe(char **args, char **envp, t_env *env);
int						exec_path(char **args, char **envp, t_env *env);
int						ft_isnum(char *str);
int						bildin(char **args, t_env *env);
char					*ft_strmasschr_char(char *what, char **where,
							int cmplen);
char					**ft_new_str(char **arr, char *new_str);
void					redidirecti(t_struct *global);

// \LOGIC

#endif
