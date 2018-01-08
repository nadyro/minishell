/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:27:32 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/07 07:35:43 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**fork_monastery(char *line, char **env)
{
	pid_t	master;
	char	**as;
	int		b;

	as = ft_split_whitespaces(line);
	if (as[0])
	{
		b = is_builtin(as);
		if (b == 0)
		{
			master = fork();
			if (master > 0)
			{
				waitpid(master, NULL, 0);
			}
			if (master == 0)
				get_child(as, env);
		}
		else if (b > 0 && b <= 6)
		{
			env = dispatch_builtin(as, env);
		}
	}
	free_tabz(as, NULL);
	return (env);
}

int		main(int ac, char **av, char **env)
{
	char		*line;
	char		**tmp;
	static char	**meta_env;
	int			i;

	i = 0;
	tmp = NULL;
	meta_env = copy_env(tmp, env, 0);
	(void)av;
	while (1)
	{
		ft_putstr("$> ");
		if (get_next_line(0, &line) == 1)
		{
			if (ft_strcmp(line, "\0") != 0)
			{
				meta_env = fork_monastery(line, meta_env);
			}
			free(line);
		}
	}
	return (ac);
}
