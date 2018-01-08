/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 00:08:29 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/11/30 00:18:17 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo(char **as)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	while (as[i] != NULL)
	{
		if (as[i + 1] != NULL)
		{
			print_bn(as, i);
			ft_putchar(' ');
		}
		else
		{
			print_bn(as, i);
			ft_putchar('\n');
		}
		i++;
	}
}

void	print_bn(char **as, int i)
{
	int		y;

	y = 0;
	while (as[i][y])
	{
		if (as[i][y] && as[i][y] == '\\' && as[i][y + 1] == 'n')
		{
			ft_putchar('\n');
			y = y + 2;
		}
		ft_putchar(as[i][y]);
		y++;
	}
}
