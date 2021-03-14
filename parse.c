/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:27:37 by iariss            #+#    #+#             */
/*   Updated: 2021/01/17 16:36:07 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	parse(char **mapi, t_map *ss)
{
	ss->i = 0;
	ss->m = 0;
	ss->map = 0;
	ss->count = 0;
	while (mapi[ss->m])
		ss->m++;
	check_intrude(mapi, ss);
	while (mapi[ss->i] && ss->i < ss->m)
	{
		ss->r = ss->count;
		ifelse(mapi, ss->i, ss);
		ss->k = 0;
		while (mapi[ss->i][ss->k] == ' ' && mapi[ss->i][ss->k])
			ss->k++;
		if (ss->count == 8 && ss->r == ss->count && mapi[ss->i][ss->k]
		&& mapi[ss->i][ss->k] != ' ' && mapi[ss->i][ss->k] != '1' &&
		mapi[ss->i][ss->k] != '0' && mapi[ss->i][ss->k] != '\n')
			ft_string_put("Error\nparse error\n");
		if (mapi[ss->i][ss->k] == '1' || mapi[ss->i][ss->k] == '0'
		|| mapi[ss->i][ss->k] == '2')
			mapsave(mapi, ss, &ss->i);
		ss->i++;
	}
	if (ss->count != 8 || !ss->map)
		ft_string_put("Error\nparse error\n");
}

void	ifelse(char **mapi, int i, t_map *ss)
{
	int k;

	k = 0;
	while (mapi[i][k] == ' ')
		k++;
	if (ft_strncmp(mapi[i] + k, "R ", 2) == 0)
		window_res(mapi[i] + k, ss);
	else if (ft_strncmp(mapi[i] + k, "NO ", 3) == 0)
		northtext(mapi[i] + k, ss);
	else if (ft_strncmp(mapi[i] + k, "SO ", 3) == 0)
		southtext(mapi[i] + k, ss);
	else if (ft_strncmp(mapi[i] + k, "WE ", 3) == 0)
		westtext(mapi[i] + k, ss);
	else if (ft_strncmp(mapi[i] + k, "EA ", 3) == 0)
		easttext(mapi[i] + k, ss);
	else if (ft_strncmp(mapi[i] + k, "S ", 2) == 0)
		sptext(mapi[i] + k, ss);
	else if (ft_strncmp(mapi[i] + k, "F ", 2) == 0)
		floorcolor(mapi[i] + k, ss);
	else if (ft_strncmp(mapi[i] + k, "C ", 2) == 0)
		ceilcolor(mapi[i] + k, ss);
}

void	window_res(char *mapi, t_map *ss)
{
	int i;

	i = 2;
	while (mapi[i] == ' ' && mapi[i])
		i++;
	ss->w = ft_atoi(&mapi[i]);
	while (ft_isdigit(mapi[i]))
		i++;
	if (mapi[i] != ' ' || ss->w <= 0)
		ft_string_put("Error\nwindow resolution\n");
	while (mapi[i] == ' ' && mapi[i])
		i++;
	ss->h = ft_atoi(&mapi[i]);
	while (ft_isdigit(mapi[i]))
		i++;
	while (mapi[i] == ' ')
		i++;
	if (mapi[i] || ss->h <= 0 || ss->w <= 0)
		ft_string_put("Error\nwindow resolution\n");
	if (ss->h > 1440 || ss->w > 2560)
	{
		ss->h = 1440;
		ss->w = 2560;
	}
	ss->count++;
}

int		northtext(char *mapi, t_map *ss)
{
	int i;
	int l;

	i = 3;
	l = 0;
	while (mapi[i] == ' ' && mapi[i])
		i++;
	l = i;
	while (mapi[i])
	{
		i++;
	}
	ss->northtext = ft_substr((const char *)mapi, l, i - l + 1);
	ss->count++;
	return (0);
}

int		southtext(char *mapi, t_map *ss)
{
	int i;
	int l;

	i = 3;
	l = 0;
	while (mapi[i] == ' ' && mapi[i])
		i++;
	l = i;
	while (mapi[i])
	{
		i++;
	}
	ss->southtext = ft_substr((const char *)mapi, l, i - l + 1);
	ss->count++;
	return (0);
}
