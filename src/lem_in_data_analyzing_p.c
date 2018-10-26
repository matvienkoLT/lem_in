/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_data_analyzing_p.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:52:06 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/24 17:52:07 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

#define T_NAME0 t.s_name_0 = 1; t.point0 = t.lst_begin;
#define T_NAME1 t.s_name_1 = 1; t.point1 = t.lst_begin;
#define PUSH	ln_push_chain(&lst->chain, t.point0, t.point1)
#define NT_C	lst->chain = lst->chain->next;
#define IFF		if ((PUSH)) return (EXIT_FAILURE); else NT_C;

int			ln_cmp_lst_data(t_lst *lst, t_data *new_data)
{
	while (lst->next)
	{
		if (!(ft_strcmp(lst->data->name, new_data->name)))
			return (SMLR_DATA);
		else
		{
			if (lst->data->x == new_data->x &&
				lst->data->y == new_data->y)
				return (SMLR_DATA);
		}
		lst = lst->next;
	}
	return (EXIT_SUCCESS);
}

static char	*ln_data_name(char *str, int name_len)
{
	char	*name;

	if (!(name = ft_strnew(name_len)))
		return (NULL);
	name = ft_strncpy(name, str, name_len);
	return (name);
}

static void	ln_initialization(t_tools *t, t_taker_lst *lst)
{
	t->s_name_0 = 0;
	t->s_name_1 = 0;
	t->point0 = NULL;
	t->point1 = NULL;
	t->lst_begin = lst->begin;
}

static int	ln_cmp_with_exist(char *n0, char *n1, t_taker_lst *lst)
{
	t_tools t;

	ln_initialization(&t, lst);
	while (t.lst_begin->next)
	{
		if (!(ft_strcmp(t.lst_begin->data->name, n0)))
		{
			T_NAME0;
		}
		else if (!(ft_strcmp(t.lst_begin->data->name, n1)))
		{
			T_NAME1;
		}
		if (t.s_name_0 && t.s_name_1)
		{
			IFF;
			if ((ln_push_chain(&lst->chain, t.point1, t.point0)))
				return (EXIT_FAILURE);
			else
				lst->chain = lst->chain->next;
			return (EXIT_SUCCESS);
		}
		t.lst_begin = t.lst_begin->next;
	}
	return (EXIT_FAILURE);
}

int			ln_analyzing_data_chain(char *str, t_taker_lst *lst)
{
	int		name_len0;
	int		name_len1;
	char	*name_0;
	char	*name_1;

	name_0 = NULL;
	name_1 = NULL;
	if (!(str = ln_undef_symbol(str)))
		return (ERR);
	name_len0 = ft_strnlen(str, '-');
	if (!name_len0 || *(str + name_len0 + 1) == '\0')
		return (lem_in_error_name(name_0, name_1));
	name_len1 = ft_strlen(str + name_len0 + 1);
	if (!name_len1)
		return (lem_in_error_name(name_0, name_1));
	if (!(name_0 = ln_data_name(str, name_len0)))
		return (lem_in_error_name(name_0, name_1));
	if (!(name_1 = ln_data_name(str + +name_len0 + 1, name_len1)))
		return (lem_in_error_name(name_0, name_1));
	if (ln_cmp_with_exist(name_0, name_1, lst) == EXIT_FAILURE)
		return (lem_in_error_name(name_0, name_1));
	free(name_0);
	free(name_1);
	return (EXIT_SUCCESS);
}
