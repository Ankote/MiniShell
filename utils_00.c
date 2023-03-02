/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:51:50 by aankote           #+#    #+#             */
/*   Updated: 2023/03/02 08:51:51 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

void ft_skip_white_spaces(char *str, int *i)
{
    while (str[*i] == ' ')
    	(*i) ++;
}

void	ft_lstadd_back(t_token **lst, t_token *new, int *i)
{
	t_token	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		*i = -1;
	}
}

t_token	*ft_lstnew(int type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (0);
    new->type = type;
	new->next = NULL;
	return (new);
}
