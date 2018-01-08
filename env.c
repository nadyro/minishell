/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:31:35 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/06 20:53:19 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_from_env(char **env, char *object, int l)
{
	char	*ch;
	int		i;

	i = 0;
	ch = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], object, l))
		{
			ch = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	return (ch);
}

char	**swap_env(char **env, char *old, char *new)
{
	int		i;
	char	*s;
	char	*s1;

	i = -1;
	while (env[++i])
		if (ft_strnstr(env[i], "OLDPWD=", 7))
		{
			ft_memdel((void **)&env[i]);
			s = ft_strnew(ft_strlen(old) + 7);
			ft_memcpy(s, "OLDPWD=", 7);
			ft_memcpy(&s[7], ft_strchr(old, '=') + 1, ft_strlen(old));
			env[i] = s;
		}
	i = -1;
	while (env[++i])
		if (ft_strnstr(env[i], "PWD=", 4))
		{
			ft_memdel((void **)&env[i]);
			s1 = ft_strnew(4 + ft_strlen(new));
			ft_memcpy(s1, "PWD=", 4);
			ft_memcpy(&s1[4], ft_strchr(new, '=') + 1, ft_strlen(new));
			env[i] = s1;
		}
	return (env);
}

char	**elag_env(char **env, char *pwd)
{
	char	*full_cwd;
	char	*cwd;
	char	*get_wd;

	cwd = NULL;
	get_wd = getcwd(cwd, 1024);
	if (get_wd)
	{
		full_cwd = ft_strnew(ft_strlen(get_wd) + 4);
		ft_memcpy(full_cwd, "PWD=", 4);
		ft_memcpy(&full_cwd[4], get_wd, ft_strlen(get_wd));
		env = swap_env(env, pwd, full_cwd);
		free(full_cwd);
		free(get_wd);
	}
	return (env);
}
