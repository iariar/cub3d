/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:34:52 by iariss            #+#    #+#             */
/*   Updated: 2020/12/10 18:34:53 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

t_ray	castallrays(t_vars *vars, t_ray *ray)
{
	float	rayangle;
	int		stripid;

	stripid = 0;
	vars->tis = 0;
	rayangle = vars->rotationangle - (vars->fov_ang / 2);
	while (stripid < vars->num_rays)
	{
		castray(rayangle, vars, &ray[stripid], &vars->ss);
		rayangle += vars->fov_ang / vars->num_rays;
		stripid++;
	}
	return (*ray);
}

void	castray(float rayangle, t_vars *vars, t_ray *ray, t_map *ss)
{
	t_too to;

	init_vars(&to, &rayangle, vars);
	horizantal_raycasting(&to, ss);
	init_vars2(&to, &rayangle, vars);
	vertical_raycasting(&to, ss);
	order(vars, &to);
	order2(&to, rayangle, ray);
}

void	ray_vars(t_too *to, t_ray *ray, int rayangle)
{
	if (to->vertwallhitdistance < to->horizwallhitdistance)
	{
		ray->distance = to->vertwallhitdistance;
		ray->wallhitx = to->verticalwallhitx;
		ray->wallhity = to->verticalwallhity;
		if (to->verticalwallcontent != '\0')
			ray->wallhitcontent = to->verticalwallcontent;
		ray->washitvertival = 1;
	}
	else
	{
		ray->distance = to->horizwallhitdistance;
		ray->wallhitx = to->horizantalwallhitx;
		ray->wallhity = to->horizantalwallhity;
		if (to->horizantalwallcontent != '\0')
			ray->wallhitcontent = to->horizantalwallcontent;
		else
			ray->wallhitcontent = '1';
		ray->washitvertival = 0;
	}
	ray->ra = rayangle;
	ray->isfacingdown = to->raydown;
	ray->isfacingup = to->rayup;
	ray->isfacingleft = to->rayleft;
	ray->isfacingright = to->rayright;
}

void	order(t_vars *vars, t_too *to)
{
	to->horizwallhitdistance = to->foundhwh
	? distance(vars->x, vars->y, to->horizantalwallhitx, to->horizantalwallhity)
	: INT_MAX;
	to->vertwallhitdistance = to->foundvwh
	? distance(vars->x, vars->y, to->verticalwallhitx, to->verticalwallhity)
	: INT_MAX;
}

void	order2(t_too *to, float rayangle, t_ray *ray)
{
	if (to->vertwallhitdistance < to->horizwallhitdistance)
	{
		ray->distance = to->vertwallhitdistance;
		ray->wallhitx = to->verticalwallhitx;
		ray->wallhity = to->verticalwallhity;
		if (to->verticalwallcontent != '\0')
			ray->wallhitcontent = to->verticalwallcontent;
		ray->washitvertival = 1;
	}
	else
	{
		ray->distance = to->horizwallhitdistance;
		ray->wallhitx = to->horizantalwallhitx;
		ray->wallhity = to->horizantalwallhity;
		if (to->horizantalwallcontent != '\0')
			ray->wallhitcontent = to->horizantalwallcontent;
		else
			ray->wallhitcontent = '1';
		ray->washitvertival = 0;
	}
	ray->ra = rayangle;
	ray->isfacingdown = to->raydown;
	ray->isfacingup = to->rayup;
	ray->isfacingleft = to->rayleft;
	ray->isfacingright = to->rayright;
}
