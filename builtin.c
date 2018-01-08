/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 04:49:51 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/07 07:04:29 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bt_cd(char **as, char **env)
{
	cd_dash_n_go(as[1], env);
	cd_home(as[1], env);
}

void	bt_echo(char **as)
{
	print_echo(as);
}

char	**bt_setenv(char **as, char **envi)
{
	int		i;
	char	**env;
	char	**new_env;
	char	*s;

	i = -1;
	new_env = NULL;
	env = copy_env(new_env, envi, 1);
	free_tabz(envi, NULL);
	if (as[1])
	{
		s = check_env(as[1]);
		while (env[++i] != NULL)
			if (s && ft_strncmp(env[i], s, get_equal(env[i])) == 0)
				if (ft_strnstr(env[i], s, (ft_strlen(s))))
				{
					replace_env(env, as[1]);
					ft_memdel((void**)&s);
					return (env);
				}
		env[i] = ft_strdup(as[1]);
		env[i + 1] = NULL;
		ft_memdel((void**)&s);
	}
	return (env);
}

void	bt_unsetenv(char **as, char **env)
{
	del_env(env, as[1]);
}

void	bt_env(char **as, char **env)
{
	int i;

	i = 0;
	(void)as;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}
