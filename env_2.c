/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:48:26 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/07 07:40:51 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **new_env, char **env, int x)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	if (x == 0)
	{
		if (!(new_env = (char **)malloc(sizeof(char *) * (i + 1))))
			return (NULL);
	}
	else
	{
		if (!(new_env = (char **)malloc(sizeof(char *) * (i + 2))))
			return (NULL);
	}
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = NULL;
	return (new_env);
}

int		get_equal(char *env)
{
	int		c;
	char	*s;
	int		i;

	i = 0;
	c = 0;
	s = ft_strchr(env, '=');
	if (s && s[0] != '=')
		return (-1);
	c = s - env;
	return (c);
}

void	del_env(char **env, char *todel)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	if (todel)
	{
		while (env[y])
			y++;
		while (env[++i])
		{
			if (ft_strncmp(env[i], todel, get_equal(env[i])) == 0)
				if (ft_strnstr(env[i], todel, ft_strlen(todel)) && (x = 1))
					ft_memdel((void **)&env[i]);
			if (x == 1)
			{
				ft_memcpy(env + i, env + i + 1, sizeof(*env) * (y - i));
				break ;
			}
		}
	}
}

char	*check_env(char *as)
{
	char	*s;
	int		i;
	char	*d;

	i = 0;
	while (as[i])
	{
		if (as[i] == '=')
			break ;
		i++;
	}
	if (as[i] != '=')
	{
		d = ft_strdup(as);
		return (d);
	}
	s = ft_strnew(i + 1);
	i = -1;
	while (as[++i])
	{
		if (as[i] == '=')
			break ;
		s[i] = as[i];
	}
	return (s);
}

void	replace_env(char **env, char *to_r)
{
	int		i;
	char	*s;

	i = -1;
	if (to_r)
	{
		s = check_env(to_r);
		while (env[++i])
		{
			if (ft_strncmp(env[i], s, (get_equal(env[i]))) == 0)
				if (ft_strnstr(env[i], s, ft_strlen(s)))
				{
					ft_memdel((void **)&env[i]);
					env[i] = ft_strdup(to_r);
					ft_memdel((void**)&s);
					break ;
				}
		}
	}
}
