/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:18:35 by aankote           #+#    #+#             */
/*   Updated: 2023/03/10 20:40:07 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void list_init(t_list *list)
{
    list->args = NULL;
    list->cmd = NULL;
    list->infile = 0;
    list->outfile = 1;
    list->append_in = 1;
    list->next = NULL;
}

void get_cmd(t_list **list, t_token **token)
{
    t_token *tmp;
    t_list *tmp_list;

    tmp = *token;
   
    tmp_list = (t_list *)malloc(sizeof(t_list));
    list_init(tmp_list);
    while (tmp)
    {
        type_arg(tmp);
        if(tmp->type == CMD)
            tmp_list->cmd = tmp->val;
        else if(tmp->type == ARG)
            tmp_list->args = ft_realloc( tmp_list->args, tmp->val);
        else if(tmp->type == INFILE)
            get_infile(tmp_list, tmp->val);
        else if(tmp->type == OUTFILE)
            get_outfile(tmp_list, tmp->val, OUTFILE);
        else if(tmp->type == APPEND)
            get_outfile(tmp_list, tmp->val, APPEND);
        if ((tmp->next && tmp->next->type == PIPE) || !tmp->next)
        {
            add_command(list, tmp_list);
            tmp_list = (t_list *)malloc(sizeof(t_list));
            list_init(tmp_list);
        }
        tmp = tmp->next;
    }
}

