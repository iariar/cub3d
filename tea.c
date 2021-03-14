/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tea.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:43:38 by iariss            #+#    #+#             */
/*   Updated: 2020/11/13 13:20:43 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

char	*ft_strndup(const char *str, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (str[i] != '\0' && i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_name(char *s)
{
	int		i;

	i = 0;
	i = ft_strlen(s);
	if ((ft_strncmp(s + (i - 4), ".cub", 4)))
		ft_string_put("error\nmap name\n");
}

void	free_vars(t_vars *vars)
{
	free(vars->mapi);
	free(vars->ss.northtext);
	free(vars->ss.southtext);
	free(vars->ss.bp);
	free(vars->ss.easttext);
	free(vars->ss.sptext);
	free(vars->ss.westtext);
}

int		main(int c, char **v)
{
	t_vars	vars;

	if (c > 1 && c < 4)
	{
		vars.c = c;
		check_name(v[1]);
		vars.map_name = v[1];
		if (!(vars.mapi = file_totab(v[1])))
			ft_string_put("Error\nfailed to open map\n");
		parse(vars.mapi, &vars.ss);
		pathtextcheck(&vars.ss);
		mapcheck(&vars.ss, &vars);
		setup(&vars);
		vars.num_rays = vars.ss.w;
		init_imgs(&vars, v);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
		mlx_hook(vars.win, 02, 1L << 0, presskey, &vars);
		mlx_hook(vars.win, 03, 1L << 1, releasekey, &vars);
		mlx_hook(vars.win, 17, 1L << 6, destroy, &vars);
		mlx_loop(vars.mlx);
		return (0);
	}
	ft_string_put("Error\nnum arg\n");
	return (0);
}
