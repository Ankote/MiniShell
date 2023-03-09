/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/03/09 17:38:25 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft(int c)
{
    if(c == CMD)
        printf("CMD ");
    if(c == ARG)
        printf("ARG ");
    if(c == TRUNC)
        printf("TRUNC ");
    if(c == APPEND)
        printf("APPEND ");
    if(c == INPUT)
        printf("INPUT ");
    if(c == PIPE)
        printf("PIPE ");
    if(c == INFILE )
        printf("INFILE ");
    if(c == OUTFILE)
        printf("OUTFILE ");
    if(c == HERDOC)
        printf("HERDOC ");
    if(c == LIMITER)
        printf("LIMITER ");
}

void tokens(char *line, t_token **token)
{
    get_token(line, token);
    while ((*token))
    {
        type_arg(*token);
        *token = (*token)->next;
    }
}

int main(int ac, char **av)
{
    t_token *data;
    t_list *list;
    data = malloc(sizeof(data));
  
    char *line;
    (void)ac;
    (void)av;
    list =  (t_list *)malloc(sizeof(t_list));
    list_init(list);
    while (1)
    {
       line = readline("minishell~$");
        if (!check_single_quotes(line))
        {
            printf("Syntax Error!\n");
            continue;
        }
        get_token(line, &data);
        get_cmd(&list, &data);
        while(list)
        {
            printf("%s ", list->cmd);
            list = list->next;
        }
            printf("\n");
            free (line);
        }
}
