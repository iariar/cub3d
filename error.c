/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:13:45 by iariss            #+#    #+#             */
/*   Updated: 2021/01/17 16:37:27 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	ft_string_put(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(0);
}

int		number(char *mapi, int *i)
{
	int	k;

	k = *i;
	while (ft_isdigit(mapi[*i]))
		(*i)++;
	if (*i == k)
		return (0);
	return (1);
}

void	sp_count(t_vars *vars)
{
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
			if (vars->ss.bp[y][x] == '2')
			{
				z++;
			}
			x++;
		}
		y++;
	}
	vars->num_sps = z;
}
