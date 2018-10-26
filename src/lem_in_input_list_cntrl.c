/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_input_list_cntrl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:19:44 by lmatvien          #+#    #+#             */
/*   Updated: 2018/10/16 18:19:47 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

t_trush	*crt_list_trush(void)
{
	t_trush *point;

	if (!(point = (t_trush *)malloc(sizeof(t_trush))))
		return (NULL);
	point->line = NULL;
	point->next = NULL;
	return (point);
}

int		ln_push_back_trush(t_trush **lst, char *line)
{
	(*lst)->line = line;
	if (!((*lst)->next = crt_list_trush()))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	lem_in_trush_prnt(t_trush *list)
{
	t_trush *lst;

	lst = list;
	while (lst->next)
	{
		ft_printf("%s\n", lst->line);
		lst = lst->next;
	}
	ft_printf("\n");
}
