/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:53:18 by aankote           #+#    #+#             */
/*   Updated: 2023/02/24 17:50:24 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
#include <readline/history.h>


# define WRD 0
# define PIPE 1
# define LESS 2
# define GREAT 3




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
void		ft_lstadd_back(t_token **lst, t_token *new);
t_token		*ft_lstnew(int type);
char		**ft_split_op(char const *s);
int			check_operators(char c);

// typedef struct {
//     char* cmd;         // The command name
//     char** args;      // The command arguments
//     int num_args;     // The number of command arguments
//     char* input_file;      // The input file name (if any)
//     char* output_file;     // The output file name (if any)
//     int append_output;     // Whether to append to the output file instead of overwriting it
//     int pipe_to;           // The index of the command to pipe to (if any)
// } CommandInfo;


# include <stdlib.h>
# include <fcntl.h>
# endif
