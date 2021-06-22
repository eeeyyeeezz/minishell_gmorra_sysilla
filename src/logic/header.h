#ifndef HEADER_H
# define HEADER_H
# define READLINE_LIBRARY
# include <unistd.h>
# include <termcap.h>
# include <stdlib.h>
# include "../liba/libft.h"
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <term.h>
# include "../readline/include/readline/chardefs.h"
# include "../readline/include/readline/rlconf.h"
//# include "../readline/include/readline/rltypedefs.h"
# include "../readline/include/readline/tilde.h"
# include "../readline/include/readline/rlstdc.h"
# include "../readline/include/readline/history.h"
# include "../readline/include/readline/keymaps.h"
# include "../readline/include/readline/readline.h"



#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

typedef struct s_env
{
	char		**sh_envp;
	char		*sh_path;
	char		*sh_term;
	char		*sh_name;
	char		*sh_lvl;
	int			truefd0;
	int			truefd1;
	int			ispipe;
	int			isb_in;
	int			count_str;
	int			max_chr;
}				t_env;

void	ft_envp_cpy(char *envp[], t_env *buf);
int		ft_env(char **av, t_env *sh_env);
int		echo(char **arg);
int		cd(char **argv, t_env *sh_env);
int		str_index(char *str, char c);
void	add_to_env(char *key, char *add, t_env *sh_envp);
int		export(char **av, t_env *env);
int		cnt_str(char **src);
int		cnt_chr(char **src);
void	freemass(char **arr);
void	ft_err(char *err);
int		unset(char **av, t_env *env);
int		lsh_exit(char **args);
void	shlvl(t_env *env);

typedef struct	s_sh
{
	int			sh_lvl;
	int			sh_mdepth;
}				t_sh;

extern	t_sh 	tsh;

// char *builtin_str[] = {
//   "cd",
//   "export",
//   "unset"
// };

// int (*builtin_func[]) (char **, t_env *env) = {
//   &cd,
//   &export,
//   &unset
// };

#endif