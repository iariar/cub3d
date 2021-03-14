/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:11:48 by iariss            #+#    #+#             */
/*   Updated: 2019/11/04 12:56:23 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*c1;
	char	*c2;
	size_t	i;

	c1 = (char*)dst;
	c2 = (char*)src;
	i = 0;
	while (i < n)
	{
		c1[i] = c2[i];
		if (c2[i] == (char)c)
			return (c1 + i + 1);
		i++;
	}
	return (NULL);
}
