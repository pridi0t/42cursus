/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:22:57 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/13 17:13:55 by hyojang          ###   ########.fr       */
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
// etc
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_itox(unsigned int n, char c);
char		*ft_ltox(long long n);
char		*ft_uitoa(unsigned int n);
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
int			rc(int n, char c);
// ft_printf_percent
int			print_percent(t_format *t);
// ft_printf_p
int			print_p(t_format *t, va_list p);
// ft_printf_c
int			print_c(t_format *t, va_list p);
// ft_printf_s
int			print_s(t_format *t, va_list p);
// ft_printf_d
int			print_int(t_format *t, char *str);
#endif
