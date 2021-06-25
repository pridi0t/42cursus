/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:55:46 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/26 16:23:26 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = *lst;
	while (tmp1 != 0)
	{
		tmp2 = tmp1->next;
		ft_lstdelone(tmp1, del);
		tmp1 = tmp2;
	}
	*lst = 0;
}
