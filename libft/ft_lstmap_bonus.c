/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:50:10 by iariss            #+#    #+#             */
/*   Updated: 2019/11/09 19:06:03 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*b;
	t_list	*d;
	t_list	*head;
	int		i;

	i = 0;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		b = ft_lstnew(f(lst->content));
		d = b;
		if (!b)
			ft_lstclear(&b, del);
		else
		{
			if (i == 0)
				head = b;
			ft_lstadd_back(&d, b);
		}
		lst = lst->next;
		b = (b)->next;
	}
	return (head);
}
