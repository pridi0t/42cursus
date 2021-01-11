/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:22:57 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/11 23:43:18 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct {
	char	flag;
	int		width;
	int		dot;
	int		precision;
	char	specifier;
}			t_format;
typedef struct {
	int		read;
	int		result;
}			t_status;
// etc
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
// ft_printf
int			ft_printf(const char *str, ...);
// ft_printf_parsing
int			set_format(t_format *t, char *str, int *i, va_list p);
// ft_printf_parsing_utils
void		*ft_memset(void *b, int c, size_t len);
int			ft_isdigit(int c);
int			catoi(char *str, int *i);
int			isspecifier(char c);
// ft_printf_utils
size_t		ft_strlen(const char *s);
// ft_printf_c
int			print_c(t_format *t, va_list p);
// ft_printf_s
//int			print_s(t_format *t, va_list p);
// ft_printf_d
//int			print_d(t_format *t, va_list p);
#endif
