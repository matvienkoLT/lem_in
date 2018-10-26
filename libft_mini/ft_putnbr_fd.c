/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:01:16 by lmatvien          #+#    #+#             */
/*   Updated: 2018/04/02 15:44:54 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num_fd(unsigned int n, int fd)
{
	char	val;

	if (n / 10)
	{
		print_num_fd(n / 10, fd);
		val = (n % 10) + '0';
		write(fd, &val, 1);
	}
	else
	{
		val = n + '0';
		write(fd, &val, 1);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		print_num_fd(n, fd);
	else
	{
		write(fd, "-", 1);
		print_num_fd(-n, fd);
	}
}
