/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:12:59 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/18 23:46:13 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (*(s1 + start) == *set && *(s1 + start) != 0)
		start++;
	while (*(s1 + end) == *set && end >= start)
		end--;
	return (ft_substr(s1, start, (start - end + 2)));
}
