/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 04:50:50 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/07 01:38:48 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bt_exit(char **as, char **env)
{
	int e;

	if (as[1] != NULL)
	{
		e = ft_atoi(as[1]);
		free_tabz(as, NULL);
		free_tabz(env, NULL);
		exit(e);
	}
	else
	{
		free_tabz(as, NULL);
		free_tabz(env, NULL);
		exit(0);
	}
}

int		is_builtin(char **as)
{
	if (ft_strcmp(as[0], "cd") == 0)
		return (1);
	if (ft_strcmp(as[0], "echo") == 0)
		return (2);
	if (ft_strcmp(as[0], "setenv") == 0)
		return (3);
	if (ft_strcmp(as[0], "unsetenv") == 0)
		return (4);
	if (ft_strcmp(as[0], "env") == 0)
		return (5);
	if (ft_strcmp(as[0], "exit") == 0)
		return (6);
	return (0);
}

char	**dispatch_builtin(char **as, char **env)
{
	if (is_builtin(as) == 1)
		bt_cd(as, env);
	if (is_builtin(as) == 2)
		bt_echo(as);
	if (is_builtin(as) == 3)
		env = bt_setenv(as, env);
	if (is_builtin(as) == 4)
		bt_unsetenv(as, env);
	if (is_builtin(as) == 5)
		bt_env(as, env);
	if (is_builtin(as) == 6)
		bt_exit(as, env);
	return (env);
}
