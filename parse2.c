/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:38:54 by iariss            #+#    #+#             */
/*   Updated: 2021/01/19 18:37:58 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	skip_line(t_map *ss, int *i, int *j)
{
	(*i)++;
	while (ss->bp[*i][*j])
	{
		while (ss->bp[*i] && ss->bp[*i][*j] == ' ')
			(*i)++;
		(*j)++;
	}
}

void	bh(t_map *ss, int i, int *start, int *x)
{
	if (ss->bp[i][*start - 1] != '1')
		ft_string_put("error\nhorizantal space management\n");
	while (ss->bp[i][*start] == ' ')
		(*start)++;
	if (ss->bp[i][*start] != '1' && ss->bp[i][*start] != '\0')
		ft_string_put("error\nhorizantal space management\n");
	*x = 1;
}

void	horizantal(t_map *ss, t_ran r)
{
	r.i = 0;
	r.start = 0;
	while (ss->bp[r.i])
	{
		r.y = 0;
		r.j = 0;
		while (ss->bp[r.i][r.j] == ' ')
			r.j++;
		r.start = r.j;
		while (ss->bp[r.i][r.start] != '\n' && ss->bp[r.i][r.start])
		{
			r.x = 0;
			ss->bp[r.i][r.start] == ' ' ? bh(ss, r.i, &r.start, &r.x) : 0;
			r.y = 1;
			!r.x ? r.start++ : 0;
		}
		if ((ft_strncmp(&ss->bp[r.i][r.j], "1", 1) != 0) && r.y)
			ft_string_put("Error\nopen map h\n");
		if ((ft_strncmp(&ss->bp[r.i][r.start - 1], " ", 1) != 0
		&& (ft_strncmp(&ss->bp[r.i][r.start - 1], "1", 1) != 0) && r.y))
			ft_string_put("Error\nopen map h\n");
		r.i++;
	}
}

void	bv(t_map *ss, t_ran *r)
{
	int len;

	len = 0;
	r->i < r->k ? len = ft_strlen(ss->bp[r->i - 1]) : 0;
	if (len > 0 && r->j < len && ss->bp[r->i - 1][r->j] && ss->bp[r->i - 1]
	&& (ss->bp[r->i - 1][r->j] == '2' || ss->bp[r->i - 1][r->j] == '0'))
		ft_string_put("Error\nvertical space management\n");
	while (r->i < r->k && ss->bp[r->i][r->j] && ss->bp[r->i][r->j] == ' ')
		(r->i)++;
	r->i < r->k ? len = ft_strlen(ss->bp[r->i]) : 0;
	if ((ss->bp[r->i] && ss->bp[r->i][r->j] && ss->bp[r->i][r->j] != '1')
	&& len > r->j && len > 0)
		ft_string_put("Error\nvertical space management\n");
	r->x = 1;
}

void	vertical(t_map *ss, t_ran r)
{
	r.i = 0;
	r.j = 0;
	r.k = 0;
	r.y = 0;
	r.x = 0;
	r.len = 0;
	while (ss->bp[r.k])
		r.k += 1;
	while (ss->bp[r.i][r.j] && ft_strlen(ss->bp[r.i]))
	{
		r.m = 0;
		ft_norm(&r, ss);
		r.len = 0;
		if (r.i > 0 && r.i <= r.k)
			r.len = ft_strlen(ss->bp[r.i - 1]);
		if (r.len == 0 && r.y && r.k == r.i && ss->bp[r.i - 1]
		&& ss->bp[r.i - 1][r.j] && ss->bp[r.i - 1][r.j] != '1')
			r.len = 0;
		if (r.y == 1 && ss->bp[r.i - 1] && ss->bp[r.i - 1][r.j]
		&& (ss->bp[r.i - 1][r.j] == '2' || ss->bp[r.i - 1][r.j] == '0')
		&& ss->bp[r.i - 1][r.j] != ' ' && r.len && r.j <= r.len)
			ft_string_put("Error\nopen map v\n");
		r.i = 0;
		r.j++;
	}
}
