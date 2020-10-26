/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:34:26 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/26 19:59:19 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newt;
	t_list *tmp;

	newt = 0;
	if (lst == 0 || f == 0)
		return (0);
	while (lst != 0)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == 0)
		{
			ft_lstclear(&newt, del);
			return (0);
		}
		ft_lstadd_back(&newt, tmp);
		lst = lst->next;
	}
	return (newt);
}
