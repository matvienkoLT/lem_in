/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:27:11 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/25 22:27:12 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_header.h"

int		lem_in_error_name(char *n0, char *n1)
{
	char *ptr;

	ptr = "Incorrect input: vertex name not found or have forbidden symbol\n";
	if (n0 && n1)
		ft_printf("{yellow}CHAIN {cyan}%s-%s\n{eoc}", n0, n1);
	else if (n0 && !n1)
		ft_printf("{bold}{cyan}%s\n{eoc}", n0);
	else if (!n0 && n1)
		ft_printf("{yellow}{bold}%s{eoc}", n1);
	if (n0)
		free(n0);
	if (n1)
		free(n1);
	return (ERR);
}

char	*ln_undef_symbol(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str != '\0')
		return (str);
	return (NULL);
}

int		ant_err(void)
{
	ft_printf("{red}ANT QUANTITY ERROR\n");
	return (EXIT_FAILURE);
}

int		ln_hash(char *str)
{
	if (*str == '#')
	{
		if (!(ft_strcmp("start", str + 1)))
			return (START_P);
		else if (!(ft_strcmp("end", str + 1)))
			return (END_P);
		else
			return (ERR);
	}
	else
		return (COMMENT);
}

int		ln_point_stts(int status, int *p_stts)
{
	if (status == START_P)
	{
		p_stts[0] = 1;
		p_stts[1] += 1;
		if (p_stts[1] >= 2)
			return (EXIT_FAILURE);
	}
	else if (status == END_P)
	{
		p_stts[0] = 2;
		p_stts[2] += 1;
		if (p_stts[2] >= 2)
			return (EXIT_FAILURE);
	}
	if (status == ERR_2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
