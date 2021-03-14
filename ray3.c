/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:44:41 by iariss            #+#    #+#             */
/*   Updated: 2021/01/18 16:56:58 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	horizantal_raycasting(t_too *to, t_map *ss)
{
	while ((!thereiswall(to->xcheck, to->ycheck, ss) || to->k == 0) &&
	to->nexthorizx >= 0 && to->nexthorizy >= 0)
	{
		checkingh(to);
		if (thereiswall(to->xcheck, to->ycheck, ss))
		{
			horizantal_if(to, ss);
			break ;
		}
		else
		{
			to->nexthorizx += to->xstep;
			to->nexthorizy += to->ystep;
		}
	}
}

void	vertical_if(t_too *to, t_map *ss)
{
	int x;
	int y;

	while (ss->bp[to->ya])
	{
		to->ya++;
	}
	if (to->ycheck >= (to->ya * TILE_SIZE))
		to->ycheck = (to->ya - 1) * TILE_SIZE;
	while (ss->bp[(int)floor(to->ycheck / TILE_SIZE)][to->xa])
		to->xa++;
	if (to->xcheck >= (to->xa * TILE_SIZE))
		to->xcheck = (to->xa - 1) * TILE_SIZE;
	to->s = thereiswall(to->xcheck, to->ycheck, ss);
	to->verticalwallhitx = to->nextvertx;
	to->verticalwallhity = to->nextverty;
	y = (int)floor(to->ycheck / TILE_SIZE);
	x = (int)floor(to->xcheck / TILE_SIZE);
	if (x >= 0 && y >= 0)
		to->verticalwallcontent = ss->bp[y][x];
	to->foundvwh = 1;
	to->k = 1;
}

void	checkingv(t_too *to)
{
	to->xcheck = to->nextvertx + (to->rayleft ? -1 : 0);
	to->ycheck = to->nextverty;
}

void	checkingh(t_too *to)
{
	to->xcheck = to->nexthorizx;
	if (to->nexthorizy > 0)
		to->ycheck = to->nexthorizy + (to->rayup ? -1 : 0);
}

void	vertical_raycasting(t_too *to, t_map *ss)
{
	while ((!thereiswall(to->xcheck, to->ycheck, ss) || to->s == 0)
	&& to->nextvertx >= 0 && to->nextverty >= 0)
	{
		checkingv(to);
		if (thereiswall(to->xcheck, to->ycheck, ss))
		{
			vertical_if(to, ss);
			break ;
		}
		else
		{
			to->nextvertx += to->xstep;
			to->nextverty += to->ystep;
		}
	}
}
