/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:20:40 by iariss            #+#    #+#             */
/*   Updated: 2019/11/06 13:47:35 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*b;
	unsigned long		i;

	i = 0;
	if (!(b = malloc(size * count)))
		return (NULL);
	while (i < count * size)
	{
		((char*)b)[i] = 0;
		i++;
	}
	return (b);
}
