/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_reader_hlp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:07:23 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/28 00:07:24 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

static int	ln_str_correct(char *str)
{
	char	*line;
	int		qntt;

	qntt = 0;
	line = str;
	while (*line != '\0')
	{
		if (!ft_isdigit(*line))
		{
			free(str);
			return (ERR);
		}
		line++;
	}
	if ((qntt = ft_atoi(str)) <= 0)
	{
		free(str);
		return (ERR);
	}
	return (qntt);
}

int			ln_alive_ant(t_taker_lst *lst)
{
	char	*line;
	int		ant;

	ant = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp("", line))
			break ;
		if (ln_push_back_trush(&lst->input_curr, line) == ERR)
			return (ERR_2);
		if (lst->input_curr->line != NULL)
			lst->input_curr = lst->input_curr->next;
		if ((ln_analyzing_hash_param(line) == COMMENT))
			continue ;
		if ((ant = ln_str_correct(line)) != ERR)
		{
			lst->ants = ant;
			return (EXIT_SUCCESS);
		}
		else
			break ;
	}
	return (ERR);
}
