/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:12:59 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/19 17:26:49 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;

	start = 0;
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, *(s1 + start)) != 0\
			&& *(s1 + start) != 0)
		start++;
	while (ft_strchr(set, *(s1 + end)) != 0 && end >= start)
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
