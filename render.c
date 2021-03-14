/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:27:17 by iariss            #+#    #+#             */
/*   Updated: 2021/01/18 17:01:20 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	renderfloorceil(t_vars *vars)
{
	vars->v = 0;
	while (vars->v < floor(vars->ss.h / 2))
	{
		vars->w = 0;
		while (vars->w < vars->ss.w)
		{
			vars->img.data[vars->v * vars->ss.w + vars->w] =
			vars->ss.rc * 65536 + vars->ss.gc * 256 + vars->ss.bc;
			vars->w++;
		}
		vars->v++;
	}
	vars->v = floor(vars->ss.h / 2);
	vars->w = 0;
	while (vars->v < vars->ss.h)
	{
		vars->w = 0;
		while (vars->w < vars->ss.w)
		{
			vars->img.data[vars->v * vars->ss.w + vars->w] =
			vars->ss.rf * 65536 + vars->ss.gf * 256 + vars->ss.bf;
			vars->w++;
		}
		vars->v++;
	}
}

int		destroy(int c)
{
	c = 0;
	exit(1);
}

int		rendering(t_vars *vars)
{
	mlx_hook(vars->win, 02, 1L << 0, presskey, vars);
	mlx_hook(vars->win, 03, 1L << 1, releasekey, vars);
	mlx_hook(vars->win, 17, 1L << 6, destroy, vars);
	return (1);
}

void	check_intrude(char **ma, t_map *ss)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (ma[i] && i < ss->m)
	{
		k = 0;
		if (ma[i][0] && ma[i][0] != 'R' && ma[i][0] != 'W' && ma[i][0] != 'N' &&
		ma[i][0] != 'S' && ma[i][0] != 'E' && ma[i][0] != 'C' && ma[i][0] != 'F'
		&& ma[i][0] != ' ' &&
		ma[i][0] != '0' && ma[i][0] != '1' && ma[i][0] != '\n')
			ft_string_put("error\nintruding chars\n");
		while (ma[i][k] == ' ')
			k++;
		if (ma[i][k] && ma[i][k] != 'R' && ma[i][k] != 'W' && ma[i][k] != 'N' &&
		ma[i][k] != 'S' && ma[i][k] != 'E' && ma[i][k] != 'C' && ma[i][k] != 'F'
		&& ma[i][k] != ' ' && ma[i][k] != '0' && ma[i][k] != '1'
		&& ma[i][k] != '\n')
			ft_string_put("error\nintruding chars\n");
		i++;
	}
}
