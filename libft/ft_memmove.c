/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:53:04 by iariss            #+#    #+#             */
/*   Updated: 2019/11/06 14:39:24 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*c1;
	char	*c2;

	c1 = (char*)dst;
	c2 = (char*)src;
	if (c1 > c2)
	{
		while (len--)
		{
			c1[len] = c2[len];
		}
	}
	else if (c2 > c1)
	{
		i = 0;
		while (i < len && c1[i])
		{
			c1[i] = c2[i];
			i++;
		}
	}
	return (c1);
}
