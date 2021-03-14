/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:28:15 by iariss            #+#    #+#             */
/*   Updated: 2021/01/18 16:31:47 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void		draw_sp(t_sp *s, t_vars *vars, float *distance)
{
	s->k = 0;
	while (vars->sp_x < s->w
	&& vars->sp_x + s->topx <= vars->ss.w && s->topx >= 0)
	{
		vars->sp_y = 0;
		s->q = 0;
		while (vars->sp_y < s->height && vars->sp_y + s->topy < vars->ss.h)
		{
			s->s_i = (int)(64 * floor(64 * vars->sp_y / s->height)
			+ floor(64 * vars->sp_x / s->w));
			s->i_i = ((s->topy + s->q) * vars->ss.w + (s->topx + s->k));
			s->c = vars->b[s->s_i];
			s->rm = distance[s->topx + s->k];
			if (s->i_i >= 0
			&& s->i_i <= vars->ss.h * vars->ss.w && (s->rm > s->dis))
				vars->img.data[s->i_i] =
					s->c == R ? vars->img.data[s->i_i] : s->c;
			vars->sp_y++;
			s->q++;
		}
		vars->sp_x++;
		s->k++;
	}
}

void		render_sps(t_vars *vars, t_sp *sp, float *distance)
{
	sp->a = acos((sp->x - vars->x) / sp->dis);
	if (sp->y < vars->y)
	{
		sp->a *= -1.;
	}
	sp->a = normalizeangle(sp->a);
	vars->rotationangle = normalizeangle(vars->rotationangle);
	sp->a = vars->rotationangle - sp->a;
	sp->height = (vars->ss.h * 124 / sp->dis);
	sp->w = (vars->ss.w * 35 / sp->dis);
	sp->topy = (int)(vars->ss.h / 2) - (sp->height / 2);
	sp->topx = -(((double)vars->ss.w / vars->fov_ang
	* remainder(sp->a, 2. * PI)) - ((double)vars->ss.w / 2.)) - (sp->w / 2);
	vars->sp_x = 0;
	if (sp->topx < 0)
	{
		vars->sp_x = -sp->topx;
		sp->topx = 0;
	}
	draw_sp(sp, vars, distance);
}

void		sp_stuff(t_vars *vars, t_sp *sps, float *distance)
{
	int		z;

	z = 0;
	while (z <= vars->num_sps - 1)
	{
		render_sps(vars, &sps[z], distance);
		z++;
	}
}

void		sp_set(t_vars *vars, float *disto)
{
	t_sp	sp[vars->num_sps];
	int		x;
	int		y;
	int		z;

	y = 0;
	z = 0;
	while (vars->ss.bp[y])
	{
		x = 0;
		while (vars->ss.bp[y][x])
		{
			if (vars->ss.bp[y][x] == '2' && z <= vars->num_sps - 1)
			{
				sp[z].x = (x * TILE_SIZE) + (TILE_SIZE / 2);
				sp[z].y = (y * TILE_SIZE) + (TILE_SIZE / 2);
				sp[z].dis = distance(vars->x, vars->y, sp[z].x, sp[z].y);
				z++;
			}
			x++;
		}
		y++;
	}
	sp_order(vars, sp, disto);
}

void		sp_v2(t_vars *vars, float *distance)
{
	vars->b = (int *)mlx_get_data_addr(vars->sp,
	&vars->img.bpp, &vars->img.size, &vars->img.endian);
	sp_count(vars);
	if (vars->num_sps == 0)
		return ;
	sp_set(vars, distance);
}
