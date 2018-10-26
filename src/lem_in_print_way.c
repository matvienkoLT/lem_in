/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:33:34 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/26 13:33:36 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

#define ID		lst->curr->data->id
#define NAME 	lst->curr->data->name
#define N_DEEP	lst->chain->node->deep
#define NE_DEEP lst->chain->neighbor->deep

static void	ln_feeling_deep(ULLI *way, ULLI *id, ULLI deep, t_chain *chain)
{
	while (chain->next)
	{
		if (chain->node->deep == deep && chain->neighbor->id == *id)
		{
			way[deep] = chain->node->id;
			*id = chain->node->id;
			break ;
		}
		chain = chain->next;
	}
}

static void	ln_print_h(t_way *curr_w, ULLI deep, t_taker_lst *lst)
{
	if (deep < curr_w->deep)
		ft_printf("{cyan}%s{yellow}-> ", NAME);
	else
		ft_printf("{cyan}%s{eoc}", NAME);
}

static void	ln_printer(t_way *curr_w, t_taker_lst *lst)
{
	ULLI deep;

	deep = 0;
	lst->curr = lst->begin;
	if (!curr_w->next)
		ft_printf("NO WAY\n");
	while (curr_w->next)
	{
		while (lst->curr->next)
		{
			if (ID == curr_w->way[deep] && deep <= curr_w->deep)
			{
				if (ID != 0)
					ln_print_h(curr_w, deep, lst);
				deep++;
				lst->curr = lst->begin;
			}
			else
				lst->curr = lst->curr->next;
		}
		ft_printf("\n");
		deep = 0;
		curr_w = curr_w->next;
		lst->curr = lst->begin;
	}
}

static void	ln_deeper(ULLI deep, t_taker_lst *lst, t_way *curr_w)
{
	ULLI	id;

	id = lst->chain->node->id;
	deep = lst->chain->node->deep;
	curr_w->way[deep + 1] = lst->chain->neighbor->id;
	curr_w->way[deep] = lst->chain->node->id;
	while (deep > 0)
		ln_feeling_deep(curr_w->way, &id, --deep, lst->chain_begin);
}

int			ln_print_ways(t_taker_lst *lst)
{
	t_way	*curr_w;

	lst->chain = lst->chain_begin;
	curr_w = &lst->ways;
	while (lst->chain->next)
	{
		if (lst->chain->neighbor->p_stts == END_P && N_DEEP < NE_DEEP)
		{
			if (push_back_way_lst(&curr_w, lst->chain->neighbor->deep))
				return (EXIT_FAILURE);
			else
			{
				ln_deeper(lst->chain->node->deep, lst, curr_w);
				curr_w = curr_w->next;
			}
		}
		lst->chain = lst->chain->next;
	}
	if (g_fl == 2 || !(lst->ways.next))
		ln_printer(&lst->ways, lst);
	return (EXIT_SUCCESS);
}
