/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:53:18 by aankote           #+#    #+#             */
/*   Updated: 2023/03/10 20:35:59 by aankote          ###   ########.fr       */
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
# define INFILE 3
# define OUTFILE 4
# define ARG 5
# define TRUNC 6
# define APPEND 7
# define INPUT 8
# define PIPE 9
# define HERDOC 10
# define LIMITER 11

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

typedef struct s_list
{
	char			*cmd;
	char			**args;
	int 			infile;
	int 			outfile;
	int 			append_in;
	struct s_list	*next;
}	t_list;

void		ft_skip_spaces(char *str, int *i);
void		ft_lstadd_back(t_token **lst, t_token *new);
t_token		*ft_lstnew(int type, char *val);
char		**ft_split_op(char const *s);
int			check_operators(char c);
int 		ft_handel_quotes(char *line);
char		**ft_split_2(char const *s, char c);
int 		check_single_quotes(char *str);
char 		*fill_str(char *str);
void	    type_arg(t_token *token);
void 		get_token(char *line, t_token **token);
char		*get_value(char **env, char *var);
void 		get_cmd(t_list **list, t_token **token);
void		add_command(t_list **lst, t_list *new);
void add_command_u(t_list **list, t_list **tmp_list);
void 		list_init(t_list *list);
char 		**ft_realloc(char **p, char *str);
void free_double(char **p);


/*******lexer*******/
void get_infile(t_list *list, char *val);
void get_outfile(t_list *list, char *val, int type);
# endif
// echo 'dhfhygnfhgynf'