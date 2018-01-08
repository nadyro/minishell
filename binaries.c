/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 04:52:17 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/05 09:01:51 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(char **env, char *path_name, char c)
{
	char	**paths;
	char	*chr;
	int		i;

	i = 0;
	chr = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], path_name, 5))
		{
			chr = ft_strsub(env[i], 5, ft_strlen(env[i]));
			break ;
		}
		i++;
	}
	if (chr != NULL)
	{
		paths = ft_splitchar(chr, c);
		free(chr);
		return (paths);
	}
	else
		return (NULL);
}

int		check_binary(char **as)
{
	struct stat st;

	if (stat(as[0], &st) == -1)
		return (-1);
	else
		return (0);
}

char	*join_path(char *path, char *as)
{
	char	*s;
	char	*chr;
	char	*tmp;

	s = ft_strjoin(path, "/");
	chr = s;
	tmp = ft_strjoin(chr, as);
	free(s);
	return (tmp);
}

void	terminate_fork(int x, char **as, char **env)
{
	if (x == -1)
	{
		if (access(as[0], F_OK) == 0 && access(as[0], X_OK) != 0)
		{
			ft_putstr_fd("minishell: permission denied : ", 2);
			ft_putendl_fd(as[0], 2);
		}
		else if (access(as[0], F_OK) != 0)
		{
			ft_putstr_fd("minishell: Command not found : ", 2);
			ft_putendl_fd(as[0], 2);
		}
		bt_exit(as, env);
	}
}

void	get_child(char **as, char **env)
{
	char	**path;
	char	*tmp;
	int		i;
	int		x;

	i = -1;
	x = -1;
	path = get_path(env, "PATH=", ':');
	if (as)
	{
		if (check_binary(as) == 0)
			if (execve(as[0], as, env) != -1)
				free_tabz(as, NULL);
		if (path)
			while (path[++i])
			{
				tmp = join_path(path[i], as[0]);
				if (execve(tmp, as, env) != -1 && (x = 0))
					free_tabz(as, NULL);
				free(tmp);
			}
		terminate_fork(x, as, env);
		(path ? free_tabz(path, NULL) : path);
	}
}
