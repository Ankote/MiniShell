/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:53:18 by aankote           #+#    #+#             */
/*   Updated: 2023/03/04 21:35:43 by aankote          ###   ########.fr       */
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

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

// typedef struct mystruct
// {
// 	char *inpt;
// 	char *outputa;
// 	struct mystruct *next;
// } t_my;

typedef struct	s_token
{
	int				type;
	char			*val;
	struct s_token	*prev;
	struct s_token	*next;
}   t_token;

void		ft_skip_spaces(char *str, int *i);
void		ft_lstadd_back(t_token **lst, t_token *new);
t_token		*ft_lstnew(int type, char *val);
char		**ft_split_op(char const *s);
int			check_operators(char c);
int 		ft_handel_quotes(char *line);
char		**ft_split_2(char const *s, char c);
int 		check_single_quotes(char *str);
char 		*fill_str(char *str);

void get_token(char *line, t_token **token);
# endif
