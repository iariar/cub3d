/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:42:39 by iariss            #+#    #+#             */
/*   Updated: 2021/01/17 15:11:05 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	pathtextcheck(t_map *ss)
{
	int	fd;

	fd = open(ss->northtext, O_RDONLY);
	if (fd == -1)
		ft_string_put("Error\ntexture path\n");
	fd = open(ss->southtext, O_RDONLY);
	if (fd == -1)
		ft_string_put("Error\ntexture path\n");
	fd = open(ss->westtext, O_RDONLY);
	if (fd == -1)
		ft_string_put("Error\ntexture path\n");
	fd = open(ss->easttext, O_RDONLY);
	if (fd == -1)
		ft_string_put("Error\ntexture path\n");
	fd = open(ss->sptext, O_RDONLY);
	if (fd == -1)
		ft_string_put("Error\ntexture path\n");
}

void	first(t_map *ss)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (ss->bp[0][i])
		i++;
	while (ss->bp[0][j])
	{
		if (ss->bp[0][0] == '0')
			ft_string_put("Error\nparcing\n");
		if (ss->bp[0][i] == '0')
			ft_string_put("Error\nparcing\n");
		if (ss->bp[0][j] == ' ')
			j++;
		while (ss)
			j++;
	}
}

void	in(char c)
{
	if (c && (c != '0' && c != '1' && c != '2' && c != 'N'
	&& c != 'E' && c != 'W' && c != 'S' && c != ' ' && c != '\n'))
		ft_string_put("Error\nbad character in map\n");
}

void	mapsave(char **mapi, t_map *ss, int *i)
{
	int a;
	int b;
	int j;

	a = *i;
	while (mapi[a])
		(a)++;
	ss->bp = (char **)malloc(sizeof(char *) * (a - *i + 1));
	a = 0;
	b = 0;
	while (mapi[*i])
	{
		j = 0;
		while (mapi[*i][j])
		{
			j++;
		}
		ss->bp[b] = ft_strndup(mapi[*i], j);
		b++;
		(*i)++;
	}
	ss->bp[b] = NULL;
	ss->map = 1;
}
