/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:39:37 by iariss            #+#    #+#             */
/*   Updated: 2019/12/21 16:31:39 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(const char *str, char c)
{
	int		i;
	int		count;
	int		len;

	i = 0;
	count = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			len = 0;
		if (++len == 1)
			count++;
		i++;
	}
	return (count + 1);
}

static	char	*ft_strndup(const char *str, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (str[i] != '\0' && i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char			**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	int		start;
	char	**ptr;

	i = 0;
	j = 0;
	start = 0;
	if (str == NULL)
		return (NULL);
	if (!(ptr = (char**)malloc(sizeof(char*) * count_words(str, c) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (start < i)
			ptr[j++] = ft_strndup((str + start), i - start);
	}
	ptr[j] = NULL;
	return (ptr);
}
