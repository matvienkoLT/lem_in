/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:43:46 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/21 11:43:47 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

#define CR_ELS	lst->begin = create_list()
#define CR_CHLS	lst->chain_begin = create_chain_lst()
#define CR_TRLS	lst->input_begin = crt_list_trush()
#define INIT_C	lst->curr = lst->begin
#define INIT_CH lst->chain = lst->chain_begin;
#define INIT_TR	lst->input_curr = lst->input_begin
#define INIT_ALL INIT_C; INIT_CH; INIT_TR;

int			ln_analyzing_hash_param(char *str)
{
	int	status;

	status = COMMENT;
	if (*str == '#')
	{
		if ((status = ln_hash(str + 1)) == COMMENT)
			return (COMMENT);
		else if (status == START_P)
			return (START_P);
		else if (status == END_P)
			return (END_P);
		else if (status == ERR)
			return (ERR);
	}
	return (ORDNR_P);
}

static int	ln_check_v(char *line, t_taker_lst *lst, int *p_tts, int p_id)
{
	int	par[2];

	par[0] = *p_tts;
	par[1] = p_id;
	if (ln_vertex(line, &lst->curr, lst->begin, &(par[0])) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else
		lst->curr = lst->curr->next;
	if (p_tts > 0)
		*p_tts = 0;
	return (EXIT_SUCCESS);
}

static int	ln_r_helper(char *line, t_taker_lst *lst, int *p_stts, int *p_id)
{
	int	status;

	if (!ft_strcmp("", line))
		return (ERR_2);
	if ((status = ln_analyzing_hash_param(line)) == ORDNR_P)
	{
		if (ln_check_v(line, lst, p_stts, *p_id))
		{
			if (ln_analyzing_data_chain(line, lst) == EXIT_SUCCESS)
				status = ln_parse_chain(lst);
			else
				status = ERR_2;
		}
		else
			(*p_id)++;
	}
	return (status);
}

static void	ln_input(t_taker_lst *lst)
{
	if (ln_wave_node(lst) == EXIT_SUCCESS)
	{
		if (g_fl == MOD_ORDNR)
			lem_in_trush_prnt(lst->input_begin);
		else if (g_fl == MOD_INFO || g_fl == MOD_TOGTHR)
		{
			lem_in_test_print(lst->begin);
			lem_in_ls_chain_print(lst->chain_begin);
		}
		if (ln_print_ways(lst) == EXIT_FAILURE)
			ft_printf("NO WAYS\n");
		ln_now_ants_will_go(lst);
	}
	else
		ft_printf("{bold}{red}Data corrupted or not entered correctly{eoc}\n");
}

int			ln_reader(t_taker_lst *lst)
{
	char	*line;
	int		status;
	int		p_stts[3];
	int		p_id;

	ft_memset(p_stts, 0, (sizeof(int) * 3));
	p_id = 0;
	if (!(CR_ELS) || !(CR_CHLS) || !(CR_TRLS))
		return (EXIT_FAILURE);
	INIT_ALL;
	if (ln_alive_ant(lst) == ERR)
		return (ant_err());
	while (get_next_line(0, &line) == 1)
	{
		if (ln_push_back_trush(&lst->input_curr, line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (lst->input_curr->line != NULL)
			lst->input_curr = lst->input_curr->next;
		if ((status = ln_r_helper(line, lst, &p_stts[0], &p_id)) == ERR_2)
			break ;
		if (ln_point_stts(status, &p_stts[0]) == EXIT_FAILURE)
			break ;
	}
	ln_input(lst);
	return (EXIT_SUCCESS);
}
