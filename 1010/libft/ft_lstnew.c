/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 23:49:07 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/23 00:09:53 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nl;

	nl = malloc(sizeof(t_list) * 1);
	if (nl == 0)
		return (0);
	nl->content = content;
	nl->next = 0;
	return (nl);
}
