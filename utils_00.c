/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:51:50 by aankote           #+#    #+#             */
/*   Updated: 2023/03/04 21:52:26 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

void ft_skip_white_spaces(char *str, int *i)
{
    while (str[*i] == ' ')
    	(*i) ++;
}

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		new->prev = NULL;
		*lst = new;
	}
	else
	{
		if(!temp->next)
		{
			temp->prev = NULL;
			temp->next = new;
			return;
		}
		while (temp->next)
			temp = temp->next;
		temp->prev = temp;
		
		temp->next = new;
	}
}

void ft_free(char **p)
{
	int i;

	i = 0;
	while(p[i])
		free(p[i++]);
	free(p);
}

t_token	*ft_lstnew(int type, char *val)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (0);
    new->type = type;
    new->val = val;
	new->next = NULL;
	return (new);
}

// cat "<" Makefile  | grep m > out
