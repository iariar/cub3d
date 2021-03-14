/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:48:14 by iariss            #+#    #+#             */
/*   Updated: 2019/11/09 17:38:28 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (del && *lst)
	{
		while (*lst)
		{
			del((*lst)->content);
			free(*lst);
			*lst = (*lst)->next;
		}
	}
	*lst = NULL;
}
