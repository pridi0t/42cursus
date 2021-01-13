/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:22:57 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/13 19:11:39 by hyojang          ###   ########.fr       */
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
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_itox(unsigned int n, char c);
char		*ft_ltox(long long n);
char		*ft_uitoa(unsigned int n);
int			ft_printf(const char *str, ...);
int			set_format(t_format *t, char *str, int *i, va_list p);
void		*ft_memset(void *b, int c, size_t len);
int			ft_isdigit(int c);
int			catoi(char *str, int *i);
int			isspecifier(char c);
size_t		ft_strlen(const char *s);
int			rc(int n, char c);
int			print_percent(t_format *t);
int			print_p(t_format *t, va_list p);
int			print_c(t_format *t, va_list p);
int			print_s(t_format *t, va_list p);
int			print_int(t_format *t, char *str);
#endif
