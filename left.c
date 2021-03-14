/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:49:55 by iariss            #+#    #+#             */
/*   Updated: 2021/01/18 16:50:14 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int		sptext(char *mapi, t_map *ss)
{
	int i;
	int l;

	i = 2;
	l = 0;
	while (mapi[i] == ' ' && mapi[i])
		i++;
	l = i;
	while (mapi[i])
	{
		i++;
	}
	ss->sptext = ft_substr((const char *)mapi, l, i - l + 1);
	ss->count++;
	return (0);
}

int		easttext(char *mapi, t_map *ss)
{
	int i;
	int l;

	i = 3;
	l = 0;
	while (mapi[i] == ' ' && mapi[i])
		i++;
	l = i;
	while (mapi[i])
	{
		i++;
	}
	ss->easttext = ft_substr((const char *)mapi, l, i - l + 1);
	ss->count++;
	return (0);
}

int		westtext(char *mapi, t_map *ss)
{
	int i;
	int l;

	i = 3;
	l = 0;
	while (mapi[i] == ' ' && mapi[i])
		i++;
	l = i;
	while (mapi[i])
	{
		i++;
	}
	ss->westtext = ft_substr((const char *)mapi, l, i - l + 1);
	ss->count++;
	return (0);
}

void	ft_norm(t_ran *r, t_map *ss)
{
	r->i = 0;
	while (ss->bp[r->i] && ss->bp[r->i][r->j] == ' ')
		r->i++;
	r->start = r->i;
	r->y = 0;
	while (r->i < r->k && ss->bp[r->i] && ss->bp[r->i][r->j]
	&& ft_strlen(ss->bp[r->i]) && ss->bp[r->i][r->j] != '\n')
	{
		r->y = 1;
		r->x = 0;
		ss->bp[r->i][r->j] == ' ' ? bv(ss, r) : 0;
		if (!r->x)
		{
			r->m = 1;
			r->i++;
		}
	}
	r->start < r->k ? r->len = ft_strlen(ss->bp[r->start]) : 0;
	if (r->j < r->len && r->len > 1 && ss->bp[r->start]
	&& r->y == 1 && ss->bp[r->start][r->j] && ss->bp[r->start][r->j] != '1')
		ft_string_put("Error\nopen map v\n");
	if (r->start + 1 < r->k && !ss->bp[r->start][r->j + 1] &&
	ss->bp[r->start + 1] && r->y == 1 && ss->bp[r->start + 1][r->j + 1]
	&& ss->bp[r->start + 1][r->j + 1] != '1')
		ft_string_put("Error\nopen map v!\n");
}

void	handle_comma(char *s, int *i)
{
	int k;

	k = *i;
	while (s[*i] && s[*i] == ',')
		(*i)++;
	k = *i - k;
	if (k != 1)
		ft_string_put("error\ncolor");
}
