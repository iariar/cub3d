/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:40:57 by iariss            #+#    #+#             */
/*   Updated: 2019/12/21 16:32:00 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		get_start(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		start;
	int		c;

	i = 0;
	j = 0;
	start = 0;
	c = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				c = 1;
			j++;
		}
		start += c;
		if (c == 0)
			return (start);
		c = 0;
		i++;
	}
	return (start);
}

static	int		get_end(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		c;
	int		end;

	i = ft_strlen(s1) - 1;
	j = 0;
	c = 0;
	end = 0;
	while (i > 0)
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				c = 1;
			j++;
		}
		end += c;
		if (c == 0)
			return (end);
		c = 0;
		i--;
	}
	return (end);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		k;
	char	*b;

	b = NULL;
	if (s1 && set)
	{
		i = get_start(s1, set);
		k = get_end(s1, set);
		if (i == (int)ft_strlen(s1))
			return (ft_strdup(""));
		b = ft_substr(s1, i, ft_strlen(s1) - (k + i));
	}
	return (b);
}
