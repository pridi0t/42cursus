/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:29:27 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/10 19:58:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "linkedlist.h"

# define BUFFER_SIZE 512
# define NO_MODE 0
# define DQ_MODE 1
# define SQ_MODE 2

typedef struct s_env {
	char			*key;
	char			*val;
	struct s_env	*next;
}	t_env;

typedef struct s_parse {
	char	*str;
	char	*pstr;
	int		i;
	int		j;
	int		cur;
	int		inc;
	int		cnt;
}	t_parse;

int			chk_builtins(char **args, t_listnode **env);
t_listnode	*copy_envp(t_listnode *env, char **envp);
t_listnode	*insert_env(t_listnode *env, char *str);
char		*ft_partstrdup(char *s1, int start, int end);
char		*ft_cstrjoin(char *s1, char *s2);
char		**free_arr(char **arr);
char		**ft_csplit(char *str, char *charset);
void		ft_unset(char **args, t_listnode **env);
void		ft_env(t_listnode *env);
void		ft_pwd(void);
void		ft_exit(char **args);
void		ft_export(char **args, t_listnode **env);
void		ft_echo(char **args);
void		ft_cd(char **args, t_listnode **env);
char		*parsing_str(t_listnode **env, char *str);
char		*increase_malloc(char *pstr, int cnt);
int			exec_external(char **args, t_listnode *env);

#endif
