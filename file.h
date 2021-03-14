/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:48:28 by iariss            #+#    #+#             */
/*   Updated: 2021/01/21 17:09:18 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <stdint.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_opengl_20191021/mlx.h"
# include <unistd.h>
# include <limits.h>

# define PI 3.14159265358979323846
# define PII 6.28318530
# define TILE_SIZE 64
# define MAP_NUM_ROWS 8
# define MAP_NUM_COLS 24
# define TEXTURE_HEIGHT 64
# define TEXTURE_WIDTH 64
# define R 0xFF0000

typedef	struct	s_bmp {
	uint32_t	sizeofbitmapfile;
	uint32_t	reservedbytes;
	uint32_t	pixeldataoffset;
	uint32_t	sizeofthisheader;
	uint16_t	numberofcolorplanes;
}				t_bmp;

typedef	struct	s_sp
{
	double		i;
	double		x;
	double		y;
	double		dis;
	double		a;
	int			topy;
	double		endy;
	int			topx;
	double		endx;
	double		height;
	double		cordis;
	double		distance;
	double		w;
	int			drowned;
	int			s_i;
	int			i_i;
	int			c;
	int			rm;
	int			q;
	int			k;
}				t_sp;

typedef	struct	s_ran
{
	int			i;
	int			j;
	int			start;
	int			y;
	int			x;
	int			k;
	int			len;
	int			m;
}				t_ran;

typedef struct	s_map
{
	int			w;
	int			h;
	char		*northtext;
	char		*southtext;
	char		*westtext;
	char		*easttext;
	char		*sptext;
	int			rf;
	int			gf;
	int			bf;
	int			rc;
	int			gc;
	int			bc;
	char		**bp;
	char		nswe;
	int			count;
	int			map;
	int			k;
	int			i;
	int			m;
	int			r;
}				t_map;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_vars
{
	t_map		ss;
	char		*save;
	char		*map_name;
	float		fov_ang;
	void		*north;
	void		*south;
	void		*east;
	void		*west;
	void		*sp;
	int			num_rays;
	char		**tab;
	void		*mlx;
	int			c;
	int			tis;
	void		*win;
	int			num_sps;
	int			endian;
	int			size;
	int			sp_x;
	int			sp_y;
	t_img		img;
	int			*b;
	int			v;
	int			w;
	int			d;
	int			xa;
	int			line_length;
	int			bpp;
	int			addr;
	int			tur;
	float		x;
	float		y;
	float		width;
	float		height;
	int			turndirection;
	int			walkdirection;
	float		rotationangle;
	float		walkspeed;
	float		turnspeed;
	float		moveside;
	int			key;
	float		movestep;
	int			color;
	char		**mapi;
	float		scale_w;
	float		scale_h;
}				t_vars;

typedef struct	s_temp
{
	int			x;
	int			color;
	int			l;
	int			i;
	int			y;
	int			wallstriph;
	float		distance;
	float		prowallh;
	int			walltop;
	int			wallend;
	float		cordis;
	int			distancefromtop;
}				t_temp;

typedef struct	s_rays
{
	int			ignore;
	float		ra;
	float		wallhitx;
	float		wallhity;
	float		distance;
	int			washitvertival;
	int			isfacingright;
	int			isfacingleft;
	int			isfacingup;
	int			isfacingdown;
	char		wallhitcontent;
}				t_ray;

typedef	struct	s_too
{
	int			s;
	int			k;
	int			xa;
	int			ya;
	int			raydown;
	int			rayup;
	int			rayright;
	int			rayleft;
	float		xintercept;
	float		yintercept;
	float		xstep;
	float		ystep;
	int			foundhwh;
	int			foundvwh;
	float		verticalwallhitx;
	float		verticalwallhity;
	float		horizantalwallhitx;
	float		horizantalwallhity;
	char		horizantalwallcontent;
	char		verticalwallcontent;
	float		nexthorizx;
	float		nexthorizy;
	float		nextvertx;
	float		nextverty;
	float		wallgrindcontent;
	float		xcheck;
	float		ycheck;
	float		horizwallhitdistance;
	float		vertwallhitdistance;
}				t_too;

t_ray			castallrays(t_vars *vars, t_ray *ray);
void			castray(float ra, t_vars *vars, t_ray *ray, t_map *ss);
void			playermove(t_vars *vars);
void			projection(t_vars *vars, t_ray *ray);
int				thereiswall(float x, float y, t_map *ss);
char			**file_totab(char *cub);
int				enderfloorceil(t_vars *vars, t_map *ss);
void			parse(char **mapi, t_map *ss);
void			ifelse(char **mapi, int i, t_map *ss);
void			window_res(char *mapi, t_map *ss);
int				northtext(char *mapi, t_map *ss);
int				southtext(char *mapi, t_map *ss);
void			setup(t_vars *vars);
void			set_angle(char c, t_vars *vars);
void			mapcheck(t_map *ss, t_vars *vars);
void			skip_line(t_map *ss, int *i, int *j);
void			bh(t_map *ss, int i, int *start, int *x);
void			horizantal(t_map *ss, t_ran r);
void			bv(t_map *ss, t_ran *r);
void			vertical(t_map *ss, t_ran r);
void			pathtextcheck(t_map *ss);
void			first(t_map *ss);
void			in(char c);
char			*ft_strndup(const char *str, int n);
void			renderfloorceil(t_vars *vars);
void			mapsave(char **mapi, t_map *ss, int *i);
int				easttext(char *mapi, t_map *ss);
int				sptext(char *mapi, t_map *ss);
int				westtext(char *mapi, t_map *ss);
int				ceilcolor(char *mapi, t_map *ss);
int				floorcolor(char *mapi, t_map *ss);
int				rendering(t_vars *vars);
float			normalizeangle(float angle);
float			distance(float x1, float y1, float x2, float y2);
int				presskey(int keycode, t_vars *vars);
int				releasekey(int keycode, t_vars *vars);
int				thereiswall2(float x, float y, t_map *ss);
void			sp_all(t_vars *vars, t_map *ss);
int				ft_strcmp(const char *s1, const char *s2);
void			check_name(char *s);
void			init_imgs(t_vars *vars, char **v);
void			save_opt(t_vars *vars, t_map *ss, t_ray *ray);
void			sp_v2(t_vars *vars, float *distance);
void			sp_count(t_vars *vars);
void			ft_closest(t_sp *s1, t_sp *s2);
void			sp_set(t_vars *vars, float *disto);
void			render_sps(t_vars *vars, t_sp *sp, float *distance);
void			find_texture(t_ray *ray, int i, t_vars *vars);
void			vertical_if(t_too *to, t_map *ss);
void			checkingh(t_too *to);
void			checkingv(t_too *to);
void			six_to_ten(int i);
void			err(int i);
void			vertical_raycasting(t_too *to, t_map *ss);
void			init_vars2(t_too *to, float *angle, t_vars *vars);
void			order2(t_too *to, float ra, t_ray *ray);
void			sp_stuff(t_vars *vars, t_sp *sps, float *distance);
void			init_bmp_vars(t_bmp *r, t_vars *vars, t_ray *ray);
void			write_header(t_bmp *r, t_map *ss, int fd, t_vars *vars);
void			pro_vars(t_temp *b, t_ray *ray, t_map *ss, t_vars *vars);
int				thereissp(float x, float y, t_map *ss);
void			ft_string_put(char *s);
void			zero_to_five(int i);
void			init_vars(t_too *to, float *ra, t_vars *vars);
void			horizantal_raycasting(t_too *to, t_map *ss);
void			order(t_vars *vars, t_too *to);
void			horizantal_if(t_too *to, t_map *ss);
void			render_sps(t_vars *vars, t_sp *sp, float *distance);
void			sp_order(t_vars *vars, t_sp *sp, float *disto);
int				try(t_vars *vars, t_ray *ray, t_map *ss, t_sp *sp);
void			draw_sp(t_sp *sp, t_vars *vars, float *distance);
void			free_vars(t_vars *vars);
int				player_pos(t_map *ss, t_vars *vars);
void			ft_norm(t_ran *r, t_map *ss);
void			handle_comma(char *s, int *i);
void			check_intrude(char **ma, t_map *ss);
int				number(char *mapi, int *i);
int				destroy(int c);

#endif
