/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:39:10 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/21 11:39:11 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

int	main(int argc, char **argv)
{
	t_taker_lst	lst;

	lst.ways.next = NULL;
	g_fl = 0;
	if (argc >= 2)
	{
		if (!ft_strcmp(argv[1], "-ways"))
			g_fl = MOD_WAYS;
		else if (!ft_strcmp(argv[1], "-info"))
			g_fl = MOD_INFO;
		else if (!ft_strcmp(argv[1], "-wi"))
			g_fl = MOD_TOGTHR;
	}
	if (ln_reader(&lst) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
