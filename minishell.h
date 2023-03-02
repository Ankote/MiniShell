/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:53:18 by aankote           #+#    #+#             */
/*   Updated: 2023/03/02 18:29:08 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
#include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>

# define WRD 0
# define FILE 1
# define PIPE 2
# define LESS 3
# define GREAT 4
# define HERDOC 5

// typedef struct mystruct
// {
// 	char *inpt;
// 	char *outputa;
// 	struct mystruct *next;
// } t_my;

typedef struct	s_token
{
	int				type;
	struct s_token	*next;
}   t_token;
void		ft_skip_spaces(char *str, int *i);
void		ft_lstadd_back(t_token **lst, t_token *new, int *i);
t_token		*ft_lstnew(int type);
char		**ft_split_op(char const *s);
int			check_operators(char c);
char 		*ft_h(char *str, int c);
int 		ft_handel_quotes(char *line);
char		**ft_split_2(char const *s, char c);
int 		check_single_quotes(char *str);
char 		*fill_str(char *str);
# endif
