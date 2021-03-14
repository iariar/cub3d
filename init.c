/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:32:44 by iariss            #+#    #+#             */
/*   Updated: 2021/01/17 14:46:14 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void		init_imgs2(t_vars *vars)
{
	int		i;

	i = 64;
	vars->img.img = mlx_new_image(vars->mlx, vars->ss.w, vars->ss.h);
	vars->img.data = (int *)mlx_get_data_addr(vars->img.img,
	&vars->img.bpp, &vars->img.size, &vars->img.endian);
	vars->north = mlx_xpm_file_to_image(vars->mlx, vars->ss.northtext, &i, &i);
	vars->sp = mlx_xpm_file_to_image(vars->mlx, vars->ss.sptext, &i, &i);
	vars->east = mlx_xpm_file_to_image(vars->mlx, vars->ss.easttext, &i, &i);
	vars->west = mlx_xpm_file_to_image(vars->mlx, vars->ss.westtext, &i, &i);
	vars->south = mlx_xpm_file_to_image(vars->mlx, vars->ss.southtext, &i, &i);
}

void		init_imgs(t_vars *vars, char **v)
{
	t_ray	ray[vars->num_rays];

	vars->mlx = mlx_init();
	init_imgs2(vars);
	if (vars->c == 3 && !ft_strcmp(v[2], "--save"))
		save_opt(vars, &vars->ss, ray);
	if (!(vars->win = mlx_new_window(vars->mlx
	, vars->ss.w, vars->ss.h, "CUB3D")))
		ft_string_put("Error\ncreating window\n");
	if (vars->c == 3 && ft_strcmp(v[2], "--save"))
		ft_string_put("Error\nwrong argument\n");
	renderfloorceil(vars);
	castallrays(vars, ray);
	projection(vars, ray);
}

void		setup(t_vars *vars)
{
	vars->turndirection = 0;
	vars->walkdirection = 0;
	vars->moveside = 0;
	vars->walkspeed = 20;
	vars->turnspeed = (PI / 24.);
	vars->key = 0;
	vars->movestep = 0;
	vars->fov_ang = 60 * (PI / 180);
	vars->tis = 0;
}

void		set_angle(char c, t_vars *vars)
{
	if (c == 'N')
		vars->rotationangle = 3 * PI / 2;
	else if (c == 'S')
		vars->rotationangle = PI / 2;
	else if (c == 'E')
		vars->rotationangle = 0;
	else if (c == 'W')
		vars->rotationangle = PI;
}

int			player_pos(t_map *ss, t_vars *vars)
{
	int		x;
	int		y;
	int		k;

	x = 0;
	y = 0;
	k = 0;
	while (ss->bp[x])
	{
		y = 0;
		while (ss->bp[x][++y])
		{
			in(ss->bp[x][y]);
			if (ss->bp[x][y] == 'N' || ss->bp[x][y] == 'S'
			|| ss->bp[x][y] == 'W' || ss->bp[x][y] == 'E')
			{
				ss->nswe = ss->bp[x][y];
				k++;
				vars->x = ((y * TILE_SIZE) + (TILE_SIZE / 2));
				vars->y = ((x * TILE_SIZE) + (TILE_SIZE / 2));
			}
		}
		x++;
	}
	return (k);
}
