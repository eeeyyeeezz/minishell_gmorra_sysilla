#include "../../includes/minishell.h"

void	export_plus(char *av, t_env *env, int index_eq)
{
	char	*key;
	char	*tmp;

	tmp = ft_strndup(av, index_eq - 1);
	if (!tmp || !(ft_isnu(tmp)))
	{
		env->status = 1;
		printf("minishell: export: `%s': not a valid identifier\n", key);
	}
	key = ft_strjoin(tmp, "=");
	add_to_env_plus(key, &av[index_eq + 1], env);
	free(key);
	free(tmp);
}

int	ft_isnu(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] <= '9' && s[i] >= '0')
			i++;
		else
			return (1);
	}
	return (0);
}

void	in_export_while(char **av, t_env *env, int index_eq, int i)
{
	char	*key;
	char	*tmp;

	if (av[i][index_eq - 1] == '+')
		export_plus(av[i], env, index_eq);
	else
	{
		tmp = ft_strndup(av[i], index_eq);
		if (!tmp || !(ft_isnu(tmp)))
		{
			printf("minishell: export: `%s': %s\n", tmp, N_V_I);
			env->status = 1;
		}
		else
		{
			key = ft_strjoin(tmp, "=");
			if (!(ft_strchr(av[i], '=')))
				add_to_env(key, "", env);
			else
				add_to_env(key, &av[i][index_eq + 1], env);
			free(key);
		}
		free(tmp);
	}
}

void	print_sortmass(char **sort_mass)
{
	int	i;

	i = 0;
	while (sort_mass[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(sort_mass[i], 1);
		i++;
	}
}
