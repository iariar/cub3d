/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:28:54 by iariss            #+#    #+#             */
/*   Updated: 2021/01/14 19:28:55 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void		init_bmp_vars(t_bmp *r, t_vars *vars, t_ray *ray)
{
	renderfloorceil(vars);
	castallrays(vars, ray);
	projection(vars, ray);
	r->sizeofbitmapfile = 54 + (4 * vars->ss.w * vars->ss.h);
	r->reservedbytes = 0;
	r->pixeldataoffset = 54;
	r->sizeofthisheader = 40;
	r->numberofcolorplanes = 1;
}

void		write_header(t_bmp *r, t_map *ss, int fd, t_vars *vars)
{
	write(fd, "BM", 2);
	write(fd, &r->sizeofbitmapfile, 4);
	write(fd, &r->reservedbytes, 4);
	write(fd, &r->pixeldataoffset, 4);
	write(fd, &r->sizeofthisheader, 4);
	write(fd, &ss->w, 4);
	write(fd, &ss->h, 4);
	write(fd, &r->numberofcolorplanes, 2);
	write(fd, &vars->img.bpp, 2);
}

void		save_opt(t_vars *vars, t_map *ss, t_ray *ray)
{
	int		fd;
	int		i;
	int		j;
	t_bmp	r;
	int		plus;

	plus = ss->w * ss->h;
	init_bmp_vars(&r, vars, ray);
	fd = open("sample.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0640);
	if (fd == -1)
		ft_string_put("Error\ncreating bmp file\n");
	write_header(&r, ss, fd, vars);
	i = 0;
	while (i++ < 32)
		write(fd, "", 1);
	i = 0;
	while (i++ < ss->h)
	{
		j = 0;
		while (j++ < ss->w)
			write(fd,
			&vars->img.data[plus - (i * ss->w + ss->w - j)], 4);
	}
	exit(1);
}

void		closest(t_sp *s1, t_sp *s2)
{
	double	tmp;

	tmp = s2->dis;
	s2->dis = s1->dis;
	s1->dis = tmp;
	tmp = s2->x;
	s2->x = s1->x;
	s1->x = tmp;
	tmp = s2->y;
	s2->y = s1->y;
	s1->y = tmp;
}

void		sp_order(t_vars *vars, t_sp *sp, float *disto)
{
	int		i;
	int		j;

	i = 1;
	while (i < vars->num_sps)
	{
		j = i;
		while (j > 0)
		{
			if (sp[j - 1].dis < sp[j].dis)
				closest(&sp[j], &sp[j - 1]);
			j--;
		}
		i++;
	}
	sp_stuff(vars, sp, disto);
}
