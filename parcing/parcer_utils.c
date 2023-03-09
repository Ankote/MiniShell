/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:18:35 by aankote           #+#    #+#             */
/*   Updated: 2023/03/09 17:36:38 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void list_init(t_list *list)
{
    list->args = NULL;
    list->cmd = NULL;
    list->infile = 0;
    list->outfile = 0;
    list->next = NULL;
}
void get_cmd(t_list **list, t_token **token)
{
    int i;
    t_token *tmp;

    tmp = *token;
    i = 0;
    while (tmp)
    {
        type_arg(tmp);
        (*list)->infile = 0;
        (*list)->outfile = 1;
        (*list)->args = malloc(4);
        if(tmp->type == CMD)
             (*list)->cmd = tmp->val;
        else if(tmp->type == ARG)
            (*list)->args[i++] = tmp->val;
        else if(tmp->type == INFILE)
        {
            (*list)->infile = open(tmp->val, O_RDONLY);
            if((*list)->infile == -1)
                perror(tmp->val);
        }
        else if(tmp->type == OUTFILE)
        {
            (*list)->outfile = open(tmp->val, O_CREAT | O_TRUNC | O_RDWR, 0777);
            if((*list)->outfile == -1)
            perror(tmp->val);
        }
        else if (tmp->type == PIPE || !tmp->next)
            add_command(list, *list);
        tmp = tmp->next;
    }
}

