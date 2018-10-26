/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_mem_cl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:55:55 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/24 12:55:56 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

void	ln_lst_destroy(t_lst *lst)
{
	t_lst *temp;

	while (lst->next)
	{
		temp = lst;
		free(temp->data->name);
		free(temp->data);
		lst = lst->next;
		free(temp);
	}
	if (lst)
	{
		free(lst->data);
		free(lst);
	}
}

void	ln_chain_destroy(t_chain *chain)
{
	t_chain	*chain_temp;

	while (chain->next)
	{
		chain_temp = chain;
		chain = chain->next;
		free(chain_temp);
	}
	if (chain)
		free(chain);
}

int		ln_data_error(char *str)
{
	free(str);
	return (EXIT_FAILURE);
}

void	ln_trsh_destroy(t_trush *lst)
{
	t_trush	*temp;

	while (lst->next)
	{
		temp = lst;
		lst = lst->next;
		free(temp->line);
		free(temp);
	}
	if (lst)
		free(lst);
}

void	ln_queue_destroy(t_queue *lst)
{
	t_queue *temp;

	while (lst->next)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	if (lst)
		free(lst);
}
