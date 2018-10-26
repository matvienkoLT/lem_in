/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:34:06 by lmatvien          #+#    #+#             */
/*   Updated: 2018/03/27 18:34:45 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*cp_src;

	cp_src = malloc(ft_strlen(src) + 1);
	if (cp_src == 0)
		return (0);
	cp_src = ft_strcpy(cp_src, src);
	return (cp_src);
}
