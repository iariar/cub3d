/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:11:24 by iariss            #+#    #+#             */
/*   Updated: 2019/12/23 18:33:58 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_numberlen(long int nbr)
{
	long int i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr >= 10)
	{
		i++;
		nbr = nbr / 10;
	}
	if (nbr > 0)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*b;
	int			sign;
	long int	r;

	sign = 0;
	r = (long int)n;
	if (r < 0)
	{
		sign = 1;
		r = -r;
	}
	len = ft_numberlen(r) + sign;
	if (!(b = malloc(sizeof(char) * len + 1)))
		return (NULL);
	b[len--] = '\0';
	if (r == 0)
		b[len] = '0';
	while (r > 0)
	{
		b[len--] = (r % 10) + 48;
		r = r / 10;
	}
	(sign == 1) ? b[0] = '-' : 0;
	return (b);
}
