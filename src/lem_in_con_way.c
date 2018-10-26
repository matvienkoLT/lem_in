/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_con_way.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 09:23:20 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/26 09:23:20 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

#define NEIGHBOR	lst->chain->neighbor
#define DEEP		lst->chain->node->deep
#define NODE_ID		lst->chain->node->id == start->id

static int	ln_ch_start_end_mark(t_lst *lst, t_rm **ptr_start)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (lst->next)
	{
		if (lst->data->p_stts == START_P)
		{
			start = 1;
			*ptr_start = lst->data;
			(*ptr_start)->visited = 1;
		}
		else if (lst->data->p_stts == END_P)
			end = 1;
		if (start && end)
			return (EXIT_SUCCESS);
		lst = lst->next;
	}
	return (EXIT_FAILURE);
}

static int	ln_ch_lst_correction(t_taker_lst *lst, t_rm **start)
{
	if (ln_ch_start_end_mark(lst->begin, start) == EXIT_FAILURE)
		return (ERR);
	if (!(lst->chain_begin->next))
		return (ERR);
	return (EXIT_SUCCESS);
}

static int	ln_search_node_neighbor(t_taker_lst *lst, t_rm *start)
{
	lst->chain = lst->chain_begin;
	while (lst->chain->next)
	{
		if (NODE_ID && !(lst->chain->neighbor->visited))
		{
			if (ln_queue_push_back(&lst->queue_curr, NEIGHBOR, DEEP))
				return (EXIT_FAILURE);
			else
				lst->queue_curr = lst->queue_curr->next;
		}
		lst->chain = lst->chain->next;
	}
	return (EXIT_SUCCESS);
}

static int	ln_queue_havoc(t_taker_lst *lst)
{
	t_rm	*start;
	t_queue	*tmp;
	int		status;

	status = EXIT_SUCCESS;
	tmp = lst->queue_begin;
	start = (t_rm*)malloc(sizeof(t_rm));
	while (lst->queue_begin->next)
	{
		start->id = lst->queue_begin->data->id;
		if (ln_queue_first_pop(&lst->queue_begin))
		{
			if (ln_search_node_neighbor(lst, start) == EXIT_FAILURE)
			{
				status = EXIT_FAILURE;
				break ;
			}
		}
	}
	free(start);
	lst->queue_begin = tmp;
	return (EXIT_SUCCESS);
}

int			ln_wave_node(t_taker_lst *lst)
{
	t_rm	*start;

	if (!(lst->queue_begin = create_queue()))
		return (EXIT_FAILURE);
	lst->queue_curr = lst->queue_begin;
	if (ln_ch_lst_correction(lst, &start) == ERR)
		return (EXIT_FAILURE);
	if (ln_search_node_neighbor(lst, start) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ln_queue_havoc(lst);
	return (EXIT_SUCCESS);
}
