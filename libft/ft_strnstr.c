/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:55:29 by iariss            #+#    #+#             */
/*   Updated: 2019/11/06 16:48:12 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		t;

	i = 0;
	t = 0;
	if (*needle == '\0' || haystack == NULL)
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			t = i;
			while (haystack[t] == needle[j] && needle[j] && t < len)
			{
				t++;
				j++;
			}
			if (j == ft_strlen(needle))
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
