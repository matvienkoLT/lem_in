/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_data_analyzing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:24:43 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/21 14:24:44 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

static int	ln_cord_detection(char *str, int *x, int *y)
{
	if (*str != '\0' && (ft_isdigit(*str) ||
		(*str == '-' && ft_isdigit(*(str + 1)))))
	{
		*x = ft_atoi(str);
		str += ft_dgt_quntt_i(*x) + 1;
	}
	else
		return (EXIT_FAILURE);
	if (*str != '\0' && (ft_isdigit(*str) ||
		(*str == '-' && ft_isdigit(*(str + 1)))))
	{
		*y = ft_atoi(str);
		str += ft_dgt_quntt_i(*y);
		if (*str != '\0')
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ln_name_correction(char *name)
{
	if (*name == 'L')
		return (EXIT_FAILURE);
	while (*name)
	{
		if (*name == '-')
			return (EXIT_FAILURE);
		name++;
	}
	return (EXIT_SUCCESS);
}

static int	ln_vertex_name(t_data *data, char *str)
{
	int name_len;

	str = ln_undef_symbol(str);
	name_len = ft_strnlen(str, ' ');
	if (!name_len)
		return (ERR);
	else
	{
		if (!(data->name = ft_strnew(name_len)))
			return (ERR);
		data->name = ft_strncpy(data->name, str, name_len);
		if (ln_name_correction(data->name) == EXIT_FAILURE)
		{
			free(data->name);
			return (ERR);
		}
	}
	return (name_len);
}

int			ln_vertex(char *str, t_lst **lst, t_lst *begin, int *p_tts)
{
	t_data		data;
	int			name_len;

	data.p_stts = p_tts[0];
	data.id = p_tts[1];
	if ((name_len = ln_vertex_name(&data, str)) == ERR)
		return (EXIT_FAILURE);
	if (ln_cord_detection(str + name_len + 1, &data.x, &data.y))
		return (ln_data_error(data.name));
	else
	{
		if (ln_cmp_lst_data(begin, &data) == SMLR_DATA)
			return (ln_data_error(data.name));
		if (ln_push_back(&(*lst), &data) == EXIT_FAILURE)
			return (ln_data_error(data.name));
	}
	return (EXIT_SUCCESS);
}
