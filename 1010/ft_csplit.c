/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:56:53 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/06 19:27:54 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_ccharset(char ch, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (ch == charset[i])
			return (1);
	return (0);
}

char	*ft_cstrdup(char *str, int start, int end)
{
	char	*result;
	int		len;
	int		i;
	int		index;

	index = 0;
	len = end - start + 2;
	result = (char *)malloc(len);
	if (!result)
		return (0);
	i = start;
	while (i <= end)
	{
		if (str[i] != -1)
			result[index++] = str[i];
		i++;
	}
	result[index] = 0;
	return (result);
}

char	*ft_cstrdup2(char *str)
{
	char	*result;
	int		len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

void	make_result(char *str, char *charset, char **result, int cnt)
{
	int	i;
	int	index;
	int	start;

	i = 0;
	index = 0;
	while (index < cnt)
	{
		start = -1;
		while (is_ccharset(str[i], charset) && str[i])
			i++;
		if (str[i])
			start = i;
		while (!is_ccharset(str[i], charset) && str[i])
			i++;
		if (start != -1)
			result[index] = ft_cstrdup(str, start, i - 1);
		index++;
	}
	result[index] = 0;
}

char	**ft_csplit(char *str, char *charset)
{
	int		i;
	int		cnt;
	char	**result;

	cnt = 0;
	i = 0;
	if (charset[0] == 0)
	{
		result = (char **)malloc(sizeof(char *) * 2);
		result[0] = ft_cstrdup2(str);
		result[1] = 0;
		return (result);
	}
	while (str[i])
	{
		while (is_ccharset(str[i], charset) && str[i])
			i++;
		if (str[i])
			cnt++;
		while (!is_ccharset(str[i], charset) && str[i])
			i++;
	}
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	make_result(str, charset, result, cnt);
	return (result);
}
