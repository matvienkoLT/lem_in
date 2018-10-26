/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:25:39 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/24 10:25:39 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

#define NM	lst->data->name
#define X	lst->data->x
#define Y	lst->data->y

void	lem_in_test_print(t_lst *lst)
{
	while (lst->next)
	{
		if (lst->data->p_stts == START_P)
			ft_printf("{bold}{byellow}{black}##START{eoc}\n");
		else if (lst->data->p_stts == END_P)
			ft_printf("{bold}{bgreen}{black}##END{eoc}\n");
		ft_printf("%s %i %i\n", NM, X, Y);
		lst = lst->next;
	}
	ft_printf("\n");
}

void	lem_in_ls_chain_print(t_chain *lst)
{
	while (lst->next)
	{
		ft_printf("%s-%s\n", lst->node->name, lst->neighbor->name);
		lst = lst->next;
	}
	ft_printf("\n");
}

void	ln_print(t_road *box, t_taker_lst *lst, ULLI deep)
{
	ULLI	i;
	ULLI	*who_there;
	t_lst	*curr;

	who_there = box->road;
	curr = lst->begin;
	i = 1;
	while (i <= deep)
	{
		while (curr->next)
		{
			if (curr->data->id == box->way[i] && who_there[i] > box->par[4] &&
				who_there[i] <= (box->par[1] * box->par[3] + box->par[6]))
			{
				ft_printf("L%llu-%s ", who_there[i], curr->data->name);
				break ;
			}
			curr = curr->next;
		}
		curr = lst->begin;
		i++;
	}
}
