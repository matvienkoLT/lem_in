/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_queue_control.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:18:55 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/26 10:18:57 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

int		push_back_way_lst(t_way **lst, ULLI deep)
{
	(*lst)->way = (ULLI*)malloc(sizeof(ULLI) * (deep + 1));
	(*lst)->deep = deep;
	ft_memset((*lst)->way, 0, (sizeof(ULLI) * deep));
	if (!((*lst)->next = (t_way*)malloc(sizeof(t_way))))
		return (EXIT_FAILURE);
	(*lst)->next->next = NULL;
	(*lst)->next->way = NULL;
	return (EXIT_SUCCESS);
}

t_queue	*create_queue(void)
{
	t_queue	*q;

	if (!(q = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	q->data = NULL;
	q->next = NULL;
	return (q);
}

int		ln_queue_push_back(t_queue **q, t_rm *data, ULLI deep)
{
	(*q)->data = data;
	(*q)->data->visited = 1;
	(*q)->data->deep = deep + 1;
	if (!((*q)->next = create_queue()))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ln_queue_first_pop(t_queue **begin)
{
	if ((*begin)->next)
	{
		(*begin) = (*begin)->next;
		return (1);
	}
	return (EMPTY_Q);
}
