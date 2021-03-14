/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:08:02 by iariss            #+#    #+#             */
/*   Updated: 2020/01/22 16:29:23 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = ((char*)s);
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (0);
		}
		str++;
	}
	return (str);
}
