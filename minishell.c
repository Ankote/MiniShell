/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/03/10 18:31:42 by aankote          ###   ########.fr       */
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
    t_token *tmp;
    
    tmp = *token;
    while (tmp)
    {
        type_arg(tmp);
        // ft(tmp->type);
        tmp = tmp->next;
    }
}

int main()
{
    t_token *data;
    t_list *list;
    data = malloc(sizeof(data));
  
    list = NULL;
    char *line;
    
    while (1)
    {
       //list_init(list);
       line = readline("minishell~$");
        if (!check_single_quotes(line))
        {
            printf("Syntax Error!\n");
            continue;
        }
        tokens(line, &data);
        get_cmd(&list, &data);
        int i = 0;
        while (list)
        {
            i = 0;
            printf("command : ");
            printf("%s\n", (list)->cmd);
             printf("Args : ");
            if((list)->args)
            {
                while((list)->args[i])
                    printf("%s ", (list)->args[i++]);
                printf("\n");
            }
            else
                printf("EMPTY\n");
            printf("intfile :  %d\n", list->infile);
            printf("outfile :  %d\n", list->outfile);
            printf("\n**********************\n");
            (list) =(list)->next;
        }
            printf("\n");
            free (line);
            free(list);
            list = NULL;
            free(data);
    }
    
    // t_list *head = NULL;
    // t_list *n1;
    // t_list *n2;
    // t_list *n3;
    // t_list *n4;

    // n1 = malloc(sizeof(t_list));
    // n2 = malloc(sizeof(t_list));
    // n3 = malloc(sizeof(t_list));
    // n4 = malloc(sizeof(t_list));

    // n1->cmd = "hello";
    // n1->append_in = 0;
    // n1->next = 0;

    // n2->cmd = "hello";
    // n2->append_in = 0;
    // n2->next = 0;

    // n3->cmd = "hello";
    // n3->append_in = 0;
    // n3->next = 0;

    // n4->cmd = "hello";
    // n4->append_in = 0;
    // n4->next = 0;
    
    // add_command(&head, n1);
    // add_command(&head, n2);
    // add_command(&head, n3);
    // add_command(&head, n4);
    
    // while(head)
    // {
    //     printf("%s\n", head->cmd);
    //     head = head->next;
    // }
}
