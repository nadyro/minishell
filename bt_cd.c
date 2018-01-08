/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:39:57 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/06 20:52:57 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path_rights(char *d)
{
	if (d != NULL)
	{
		if (access(d, F_OK) == 0 && access(d, X_OK) != 0)
		{
			ft_putstr_fd("cd: permission denied : ", 2);
			ft_putendl_fd(d, 2);
		}
		else if (access(d, F_OK) != 0)
		{
			ft_putstr_fd("cd: no such file or directory : ", 2);
			ft_putendl_fd(d, 2);
		}
	}
}

void	cd_dash_n_go(char *d, char **env)
{
	int		x;
	char	*pwd;
	char	*oldpwd;
	int		i;

	i = 0;
	pwd = get_from_env(env, "PWD=", 4);
	oldpwd = get_from_env(env, "OLDPWD=", 7);
	if (d != NULL && oldpwd)
	{
		if (ft_strcmp(d, "-") == 0)
		{
			if (pwd && oldpwd)
				env = swap_env(env, pwd, oldpwd);
			if ((x = chdir(&oldpwd[7])) == -1)
				path_rights(&oldpwd[7]);
		}
		else if ((x = chdir(d) == -1))
			path_rights(d);
		else if (pwd)
			env = elag_env(env, pwd);
	}
	free(pwd);
	free(oldpwd);
}

void	cd_home(char *h, char **env)
{
	int		x;
	int		i;
	char	*pwd;
	char	*home;

	i = 0;
	home = NULL;
	pwd = get_from_env(env, "PWD=", 4);
	while (env[i])
		if ((home = ft_strnstr(env[i++], "HOME=", 5)))
			break ;
	if (h == NULL)
		if (home != NULL)
		{
			home = ft_strdup(&home[5]);
			if ((x = chdir(home)) == -1)
			{
				ft_putstr_fd("cd : no such file or directory : ", 2);
				ft_putendl_fd(home, 2);
			}
			else if (pwd)
				env = elag_env(env, pwd);
			free(home);
		}
	free(pwd);
}
