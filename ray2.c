/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:44:31 by iariss            #+#    #+#             */
/*   Updated: 2021/01/18 16:54:25 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

float	normalizeangle(float angle)
{
	angle = remainder(angle, (2. * PI));
	if (angle < 0)
	{
		angle = (PI * 2.) + angle;
	}
	return (angle);
}

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	init_vars(t_too *to, float *ra, t_vars *vars)
{
	to->vertwallhitdistance = 0;
	to->horizantalwallhitx = 0;
	to->foundhwh = 0;
	to->horizantalwallhity = 0;
	to->horizantalwallcontent = 0;
	(*ra) = normalizeangle((*ra));
	to->raydown = (*ra) > 0 && (*ra) < PI;
	to->rayup = !to->raydown;
	to->rayright = (*ra) < PI / 2 || (*ra) > 3 * PI / 2;
	to->rayleft = !to->rayright;
	to->yintercept = floor(vars->y / TILE_SIZE) * TILE_SIZE;
	to->yintercept += to->raydown ? TILE_SIZE : 0;
	to->xintercept = vars->x + (to->yintercept - vars->y) / tan(*ra);
	to->xa = 0;
	to->ya = 0;
	to->ystep = TILE_SIZE;
	to->ystep *= to->rayup ? -1 : 1;
	to->xstep = TILE_SIZE / tan(*ra);
	to->xstep *= (to->rayleft && to->xstep > 0) ? -1 : 1;
	to->xstep *= (to->rayright && to->xstep < 0) ? -1 : 1;
	to->nexthorizx = to->xintercept;
	to->nexthorizy = to->yintercept;
	to->k = 0;
	to->xcheck = to->nexthorizx;
	to->ycheck = to->nexthorizy + (to->rayup ? -1 : 0);
}

void	init_vars2(t_too *to, float *ra, t_vars *vars)
{
	to->foundvwh = 0;
	to->verticalwallhitx = 0;
	to->verticalwallhity = 0;
	to->verticalwallcontent = 0;
	to->s = 0;
	to->xintercept = floor(vars->x / TILE_SIZE) * TILE_SIZE;
	to->xintercept += to->rayright ? TILE_SIZE : 0;
	to->yintercept = vars->y + (to->xintercept - vars->x) * tan(*(ra));
	to->xstep = TILE_SIZE;
	to->xstep *= to->rayleft ? -1 : 1;
	to->ystep = TILE_SIZE * tan(*(ra));
	to->ystep *= (to->rayup && to->ystep > 0) ? -1 : 1;
	to->ystep *= (to->raydown && to->ystep < 0) ? -1 : 1;
	to->nextvertx = to->xintercept;
	to->nextverty = to->yintercept;
	to->xa = 0;
	to->ya = 0;
	to->xcheck = to->nextvertx + (to->rayleft ? -1 : 0);
	to->ycheck = to->nextverty;
}

void	horizantal_if(t_too *to, t_map *ss)
{
	int x;
	int y;

	while (ss->bp[to->ya])
	{
		to->ya++;
	}
	if (to->ycheck >= (to->ya * TILE_SIZE))
		to->ycheck = (to->ya - 1) * TILE_SIZE;
	while (to->ycheck >= 0 &&
		ss->bp[(int)floor(to->ycheck / TILE_SIZE)][to->xa])
		to->xa++;
	if (to->xcheck >= (to->xa * TILE_SIZE))
		to->xcheck = (to->xa - 1) * TILE_SIZE;
	to->k = thereiswall(to->xcheck, to->ycheck, ss);
	to->horizantalwallhitx = to->nexthorizx;
	to->horizantalwallhity = to->nexthorizy;
	y = (int)floor(to->ycheck / TILE_SIZE);
	x = (int)floor(to->xcheck / TILE_SIZE);
	if (x >= 0 && y >= 0)
		to->horizantalwallcontent = ss->bp[y][x];
	to->foundhwh = 1;
	to->k = 1;
}
