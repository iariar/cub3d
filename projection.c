/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:36:59 by iariss            #+#    #+#             */
/*   Updated: 2021/01/17 16:41:47 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	pro_vars(t_temp *b, t_ray *ray, t_map *ss, t_vars *vars)
{
	b->cordis = (ray[b->i].distance) * cos(ray[b->i].ra - vars->rotationangle);
	b->cordis = b->cordis == 0 ? 1 : b->cordis;
	b->distance = (ss->w / 2) / tan(vars->fov_ang / 2);
	b->prowallh = (TILE_SIZE / b->cordis) * b->distance;
	b->wallstriph = (int)b->prowallh;
	b->walltop = (ss->h / 2) - (b->wallstriph / 2);
	b->walltop = b->walltop < 0 ? 0 : b->walltop;
	b->wallend = (ss->h / 2) + (b->wallstriph / 2);
	b->wallend = b->wallend > ss->h ? ss->h : b->wallend;
	b->y = b->walltop;
}

void	find_texture(t_ray *ray, int i, t_vars *vars)
{
	if (ray[i].isfacingup && !ray[i].washitvertival)
		vars->b = (int *)mlx_get_data_addr(vars->south,
		&vars->img.bpp, &vars->img.size, &vars->img.endian);
	else if (ray[i].isfacingdown && !ray[i].washitvertival)
		vars->b = (int *)mlx_get_data_addr(vars->north,
		&vars->img.bpp, &vars->img.size, &vars->img.endian);
	else if (ray[i].isfacingright && ray[i].washitvertival)
		vars->b = (int *)mlx_get_data_addr(vars->west,
		&vars->img.bpp, &vars->img.size, &vars->img.endian);
	else if (ray[i].isfacingleft && ray[i].washitvertival)
		vars->b = (int *)mlx_get_data_addr(vars->east,
		&vars->img.bpp, &vars->img.size, &vars->img.endian);
}

void	projection(t_vars *vars, t_ray *ray)
{
	t_temp	b;
	float	distance[vars->num_rays];

	b.i = 0;
	b.x = 0;
	b.l = 0;
	while (b.i++ < vars->num_rays)
	{
		pro_vars(&b, ray, &vars->ss, vars);
		if (ray[b.i].washitvertival)
			b.x = (int)ray[b.i].wallhity % TILE_SIZE;
		else
			b.x = (int)ray[b.i].wallhitx % TILE_SIZE;
		distance[b.i] = ray[b.i].distance;
		find_texture(ray, b.i, vars);
		while (b.y++ <= b.wallend)
		{
			b.distancefromtop = b.y + (b.wallstriph / 2) - (vars->ss.h / 2);
			b.l = b.distancefromtop * ((float)TEXTURE_HEIGHT / b.wallstriph);
			b.color = vars->b[(b.l * TEXTURE_WIDTH) + b.x];
			if ((b.y * vars->ss.w) + b.i < vars->ss.w * vars->ss.h)
				vars->img.data[(b.y * vars->ss.w) + b.i] = b.color;
		}
	}
	sp_v2(vars, distance);
}

int		releasekey(int keycode, t_vars *vars)
{
	if (keycode == 124)
		vars->turndirection = 0;
	if (keycode == 123)
		vars->turndirection = 0;
	if (keycode == 13)
		vars->walkdirection = 0;
	if (keycode == 1)
		vars->walkdirection = 0;
	if (keycode == 0)
		vars->moveside = 0;
	if (keycode == 2)
		vars->moveside = 0;
	return (0);
}
