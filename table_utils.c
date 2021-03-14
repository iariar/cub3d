/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:40:52 by iariss            #+#    #+#             */
/*   Updated: 2021/01/18 17:08:11 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	print_table(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
		printf("%s\n", *tab++);
}

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i + 1);
}

void	tab_join(char ***oldtab, char *new)
{
	int		i;
	char	**tab;
	char	**newtab;
	int		len;

	tab = *oldtab;
	len = tab_len(tab);
	newtab = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (tab[i])
	{
		newtab[i] = tab[i];
		i++;
	}
	newtab[i++] = new;
	newtab[i] = NULL;
	*oldtab = newtab;
	free(tab);
}

char	**file_totab(char *cub)
{
	int		fd;
	int		ret;
	char	**tab;
	char	*tmp;

	tmp = NULL;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (0);
	tab = malloc(sizeof(char *) * 1);
	*tab = NULL;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &tmp);
		tab_join(&tab, tmp);
	}
	return (tab);
}

void	mapcheck(t_map *ss, t_vars *vars)
{
	t_ran	r;

	r.i = 0;
	if (player_pos(ss, vars) != 1)
		ft_string_put("error\nplayer\n");
	horizantal(ss, r);
	vertical(ss, r);
	set_angle(ss->nswe, vars);
}
