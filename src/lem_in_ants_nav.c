/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_ants_nav.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:08:42 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/28 17:08:42 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

static void	start_n_end_p(t_taker_lst *lst, t_rm **begin, t_rm **end)
{
	lst->curr = lst->begin;
	while (lst->curr->next)
	{
		if (lst->curr->data->p_stts == START_P)
		{
			(*begin) = lst->curr->data;
			(*begin)->ant = lst->ants;
		}
		else if (lst->curr->data->p_stts == END_P)
			(*end) = lst->curr->data;
		if ((*begin) && (*end))
			break ;
		lst->curr = lst->curr->next;
	}
}

static void	add_ant(t_road *box, t_taker_lst *lst, ULLI deep)
{
	ULLI	i;
	ULLI	*who_there;

	i = 1;
	who_there = box->road;
	who_there[1] += 1;
	while (i <= deep)
	{
		if (who_there[i - 1] > 0)
			who_there[i] = who_there[i - 1] - 1;
		box->par[5] = who_there[deep];
		i++;
	}
	ln_print(box, lst, deep);
	if (deep != 1)
		ft_printf("\n");
}

static void	c_ways(t_taker_lst *lst, ULLI *ways)
{
	t_way	*roads;

	ways[0] = 0;
	ways[6] = 0;
	roads = &lst->ways;
	while (roads->next)
	{
		(ways[0])++;
		roads = roads->next;
	}
	if (*ways > 1 && g_fl != MOD_ORDNR && g_fl != MOD_INFO)
	{
		if ((ways[2] = lst->ants % ways[0]) == 0)
			ways[1] = (lst->ants / ways[0]);
		else
		{
			ways[1] = (lst->ants / ways[0]);
			ways[6] = lst->ants % ways[0];
			ft_printf("%i\n", ways[6]);
		}
	}
	else
		ways[1] = lst->ants;
}

static void	ln_road(ULLI *way, ULLI deep, t_taker_lst *lst, ULLI *w)
{
	t_rm	*begin;
	t_rm	*end;
	ULLI	*road;
	t_road	par;

	begin = NULL;
	end = NULL;
	if (!(road = (ULLI*)malloc(sizeof(ULLI) * (deep + 1))))
		return ;
	ft_memset(road, 0, (sizeof(ULLI) * (deep + 1)));
	start_n_end_p(lst, &begin, &end);
	road[1] = w[4];
	par.way = way;
	par.road = road;
	par.par = w;
	while (end->ant < (int)(par.par[1] * par.par[3] + par.par[6]))
	{
		add_ant(&par, lst, deep);
		end->ant = w[5];
	}
	w[4] = end->ant;
	free(road);
}

void		ln_now_ants_will_go(t_taker_lst *lst)
{
	t_way	*road;
	ULLI	ways[7];
	int		k;

	k = 1;
	road = &lst->ways;
	ways[3] = 1;
	ways[4] = 0;
	c_ways(lst, &ways[0]);
	while (road->next && k)
	{
		ln_road(road->way, road->deep, lst, &ways[0]);
		road = road->next;
		ways[3]++;
		if (g_fl == MOD_ORDNR || g_fl == MOD_INFO)
			k = 0;
	}
	if (lst->ways.deep == 1)
		ft_printf("\n");
}
