/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:29:57 by iariss            #+#    #+#             */
/*   Updated: 2021/01/18 16:37:27 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	skip_car(char c, char *mapi, int *i)
{
	while (mapi[*i] && mapi[*i] == c)
	{
		(*i)++;
	}
}

void	ccolor_check(t_map *ss, int i, char *mapi)
{
	if (ss->rc > 255 || ss->rc < 0 || ss->gc > 255 ||
	ss->gc < 0 || ss->bc > 255 || ss->bc < 0)
	{
		ft_string_put("error\nceiling color\n");
	}
	while (mapi[i])
	{
		if (mapi[i] != ' ')
			ft_string_put("error\nceiling color\n");
		i++;
	}
}

int		ceilcolor(char *mapi, t_map *ss)
{
	int i;

	i = 2;
	skip_car(' ', mapi, &i);
	ss->rc = ft_atoi(&mapi[i]);
	!number(mapi, &i) ? ft_string_put("Error\nceiling color\n") : 0;
	skip_car(' ', mapi, &i);
	mapi[i] != ',' ? ft_string_put("Error\nceiling color\n") : 0;
	handle_comma(mapi, &i);
	skip_car(' ', mapi, &i);
	ss->gc = ft_atoi(&mapi[i]);
	!number(mapi, &i) ? ft_string_put("Error\nceiling color\n") : 0;
	skip_car(' ', mapi, &i);
	if (mapi[i] != ',')
		return (4);
	handle_comma(mapi, &i);
	skip_car(' ', mapi, &i);
	ss->bc = ft_atoi(&mapi[i]);
	!number(mapi, &i) ? ft_string_put("Error\nceiling color\n") : 0;
	ss->count++;
	ccolor_check(ss, i, mapi);
	return (0);
}

void	fcolor_check(t_map *ss, int i, char *mapi)
{
	if (ss->rf > 255 || ss->rf < 0 || ss->gf > 255 ||
	ss->gf < 0 || ss->bf > 255 || ss->bf < 0)
		ft_string_put("error\nfloor color");
	while (mapi[i])
	{
		if (mapi[i] != ' ')
			ft_string_put("error\nfloor color");
		i++;
	}
}

int		floorcolor(char *mapi, t_map *ss)
{
	int i;

	i = 2;
	skip_car(' ', mapi, &i);
	ss->rf = ft_atoi(&mapi[i]);
	!number(mapi, &i) ? ft_string_put("Error\nfloor color\n") : 0;
	skip_car(' ', mapi, &i);
	mapi[i] != ',' ? ft_string_put("Error\nfloor color\n") : 0;
	handle_comma(mapi, &i);
	skip_car(' ', mapi, &i);
	ss->gf = ft_atoi(&mapi[i]);
	!number(mapi, &i) ? ft_string_put("Error\nfloor color\n") : 0;
	skip_car(' ', mapi, &i);
	if (mapi[i] != ',')
		return (4);
	handle_comma(mapi, &i);
	skip_car(' ', mapi, &i);
	ss->bf = ft_atoi(&mapi[i]);
	!number(mapi, &i) ? ft_string_put("Error\nfloor color\n") : 0;
	ss->count++;
	fcolor_check(ss, i, mapi);
	return (0);
}
