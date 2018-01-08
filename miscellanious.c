/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellanious.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 04:51:36 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/07 07:39:46 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tabz(char **as, char *tab)
{
	int		i;

	i = 0;
	while (as[i])
	{
		free(as[i]);
		i++;
	}
	free(as);
	if (tab != NULL)
		free(tab);
}
