/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:22:57 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/23 14:42:45 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct {
	char	flag1;
	char	flag2;
	int		width;
	int		dot;
	int		precision;
	char	specifier;
}			t_format;
// etc
int			ft_atoi(const char *str);
// ft_printf
int			ft_printf(const char *str, ...);
// ft_printf_parsing
void		init_format(t_format *t);
int			set_flag(t_format *t, char *str, int *i);
int			set_other(t_format *t, char *str, int *i);
int			set_format(t_format *t, char *str, int *i);
// ft_printf_parsing_utils
void		*ft_memset(void *b, int c, size_t len);
int			ft_isdigit(int c);
int			catoi(char *str, int *i);
int			char_categorize(char c);
#endif
