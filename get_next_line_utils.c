/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:31:45 by iariss            #+#    #+#             */
/*   Updated: 2021/01/19 14:31:45 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*b;
	size_t			i;
	unsigned int	k;

	k = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start > k)
		return (ft_strdup(""));
	if (!(b = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len && start < k)
	{
		b[i] = s[start];
		i++;
		start++;
	}
	b[i] = '\0';
	return (b);
}

char			*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	if (!s1)
	{
		return (NULL);
	}
	while (s1[j])
		++j;
	if (!(p = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void			ft_putendl_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void			ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
