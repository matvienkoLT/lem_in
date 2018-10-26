/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:17:43 by lmatvien          #+#    #+#             */
/*   Updated: 2018/10/16 18:17:44 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

int	ln_parse_chain(t_taker_lst *lst)
{
	char	*line;
	int		status;

	status = COMMENT;
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp("", line))
			break ;
		if (ln_push_back_trush(&lst->input_curr, line) == EXIT_FAILURE)
			return (ERR_2);
		if (lst->input_curr->line != NULL)
			lst->input_curr = lst->input_curr->next;
		if (ln_analyzing_data_chain(line, lst) == EXIT_SUCCESS)
			status = CHAIN;
		else if ((status = ln_analyzing_hash_param(line)) == ERR ||
			status == ORDNR_P)
			return (ERR_2);
	}
	return (status);
}
