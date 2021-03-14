/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:54:15 by iariss            #+#    #+#             */
/*   Updated: 2019/12/21 16:32:16 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*b;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(b = (char*)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	k = 0;
	while (s1[k] && k < i)
	{
		b[k] = s1[k];
		k++;
	}
	k = 0;
	while (s2[k] && k < j)
	{
		b[i + k] = s2[k];
		k++;
	}
	b[i + k] = '\0';
	return (b);
}
