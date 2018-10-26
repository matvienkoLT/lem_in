/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:35:45 by lmatvien          #+#    #+#             */
/*   Updated: 2018/04/04 10:33:07 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*dest;
	const char	*src;

	if (n == 0)
		return (str1);
	if (!str1 && !str2)
		return (NULL);
	dest = (char*)str1;
	src = (char*)str2;
	while (n--)
	{
		*dest++ = *src++;
	}
	return (str1);
}
