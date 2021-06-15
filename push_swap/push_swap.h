/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 07:34:30 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 12:35:09 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include <stdio.h>
# define SS 0
# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RR 5
# define RA 6
# define RB 7
# define RRR 8
# define RRA 9
# define RRB 10

typedef struct t_dllist{
	int				data;
	struct t_dllist	*llink;
	struct t_dllist	*rlink;
} t_dllist;

typedef struct {
	int cnt;
	int ra_cnt;
	int rb_cnt;
	int pa_cnt;
	int pb_cnt;
	int p1;
	int p2;
} t_info;

// linked_list
void    init(t_dllist **head);
void    insert_first(t_dllist **head, int data);
void	insert_last(t_dllist **head, int data);
void	delete_first(t_dllist **head);
// Quick_Sort
void    quick_sort(int *arr, int start, int end);
// operations1
void	s(t_dllist **head, char c, t_dllist **com);
void	p(t_dllist **src, t_dllist **dst, char dc, t_dllist **com);
void	r(t_dllist **head, char c, t_dllist **com);
void	rr(t_dllist **head, char c, t_dllist **com);
void	rrr2(t_dllist **a, t_dllist **b, t_dllist **com);
// operations2
void	optimization_command(t_dllist **com);
void	print_command2(t_dllist **com);
// move_utils
void	find_pivot(t_dllist *head, int *p1, int *p2, int cnt);
void    rotation_value(t_dllist **a, t_dllist **b, info *info, t_dllist **com);
// move_a
int		check_sort_a(t_dllist *s, int cnt);
void	a_to_b(t_dllist **a, t_dllist **b, int cnt, t_dllist **com);
// move_b
void	b_to_a(t_dllist **a, t_dllist **b, int cnt, t_dllist **com);
// sort3
void    sort3_a(t_dllist **a, t_dllist **com);
void	sort5_a(t_dllist **a, t_dllist **b, int cnt, t_dllist **com);
// main_exception
void	exception_arg(char ***str, int *cnt, int argc, char *argv[]);
int		exception_cnt(int cnt, t_dllist **a, t_dllist **b, t_dllist **com);
// main
int		check_int(char *str);
int		check_input(int argc, char *argv[]);
#endif