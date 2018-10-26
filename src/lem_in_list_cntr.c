/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_list_cntr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:15:06 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/24 10:15:08 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

t_lst	*create_list(void)
{
	t_lst	*point;

	if (!(point = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(point->data = (t_rm*)malloc(sizeof(t_rm))))
		return (NULL);
	point->data->ant = 0;
	point->data->p_stts = 0;
	point->data->deep = 0;
	point->data->id = 0;
	point->data->x = -1;
	point->data->y = -1;
	point->data->visited = 0;
	point->data->name = NULL;
	point->next = NULL;
	return (point);
}

int		ln_push_back(t_lst **lst, t_data *data)
{
	(*lst)->data->x = data->x;
	(*lst)->data->y = data->y;
	(*lst)->data->id = data->id;
	(*lst)->data->name = data->name;
	(*lst)->data->p_stts = data->p_stts;
	if (!((*lst)->next = create_list()))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_chain	*create_chain_lst(void)
{
	t_chain	*point;

	if (!(point = (t_chain*)malloc(sizeof(t_chain))))
		return (NULL);
	point->neighbor = NULL;
	point->node = NULL;
	point->next = NULL;
	return (point);
}

int		ln_push_chain(t_chain **cur, t_lst *data0, t_lst *data1)
{
	(*cur)->neighbor = data1->data;
	(*cur)->node = data0->data;
	if (!((*cur)->next = create_chain_lst()))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
