/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:38:33 by iariss            #+#    #+#             */
/*   Updated: 2021/01/19 14:32:12 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void		playermove(t_vars *vars)
{
	int		side_step;
	float	newplayerx;
	float	newplayery;
	float	gg;

	newplayerx = 0;
	newplayery = 0;
	vars->rotationangle += vars->turndirection * vars->turnspeed;
	gg = vars->rotationangle;
	vars->movestep = vars->walkdirection * vars->walkspeed;
	side_step = vars->moveside * vars->walkspeed;
	newplayerx = vars->x + cos(gg) * vars->movestep
	+ cos(gg + 90 * (PI / 180)) * side_step;
	newplayery = vars->y + sin(gg) * vars->movestep
	+ sin(gg + 90 * (PI / 180)) * side_step;
	if (!thereiswall(newplayerx, newplayery, &vars->ss)
	&& !thereissp(newplayerx, newplayery, &vars->ss))
	{
		vars->y = newplayery;
		vars->x = newplayerx;
	}
}

int			thereiswall(float x, float y, t_map *ss)
{
	int		indexx;
	int		indexy;
	int		x2;
	int		y2;

	if (x < 0 || y < 0)
		return (1);
	indexx = (int)floor(x / TILE_SIZE);
	indexy = (int)floor(y / TILE_SIZE);
	x2 = 0;
	y2 = 0;
	while (ss->bp[y2])
		y2++;
	if (indexy >= y2)
		return (1);
	while (ss->bp[indexy][x2])
		x2++;
	if (indexx >= x2)
		return (1);
	if (ss->bp[indexy][indexx] == '1')
		return (2);
	return (0);
}

int			thereissp(float x, float y, t_map *ss)
{
	int		indexx;
	int		indexy;
	int		x2;
	int		y2;

	if (x < 0 || y < 0)
		return (1);
	indexx = (int)floor(x / TILE_SIZE);
	indexy = (int)floor(y / TILE_SIZE);
	x2 = 0;
	y2 = 0;
	while (ss->bp[y2])
		y2++;
	if (indexy >= y2)
		return (1);
	while (ss->bp[indexy][x2])
		x2++;
	if (indexx >= x2)
		return (1);
	if (ss->bp[indexy][indexx] == '2')
		return (1);
	return (0);
}

void		key_handle(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		free_vars(vars);
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 124)
		vars->turndirection = 1;
	if (keycode == 123)
		vars->turndirection = -1;
	if (keycode == 13)
		vars->walkdirection = 1;
	if (keycode == 1)
		vars->walkdirection = -1;
	else if (keycode == 0)
		vars->moveside = -1;
	else if (keycode == 2)
		vars->moveside = 1;
}

int			presskey(int keycode, t_vars *vars)
{
	t_ray	ray[vars->num_rays];

	vars->key = keycode;
	key_handle(keycode, vars);
	playermove(vars);
	renderfloorceil(vars);
	castallrays(vars, ray);
	projection(vars, ray);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
