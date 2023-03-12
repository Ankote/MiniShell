/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/03/12 16:45:20 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Just for chick 

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
//for gake to  every token his type
void tokens(char *line, t_token **token)
{
    get_token(line, token);
    t_token *tmp;
    
    tmp = *token;
    while (tmp)
    {
        type_arg(tmp);
        tmp = tmp->next;
    }
}

void echo(char **env, t_list *list)
{
    int i;
    int n;
    char *p;
    
    i = -1;
    n = 0;
    if(!list->args)
        return;
    if(list->args[i + 1] && !ft_strcmp(list->args[i + 1], "-n"))
    {
        i++;
        n = 1;
    }
    while(list->args[++i])
    {
        p = ft_expand(env, list->args[i], SUCCESS);
        printf("%s", p);
        free(p);
        if (list->args[i + 1])
            printf(" ");
    }
    if(!n)
        printf("\n");
}

// feel free to test what do  you want
int main(int ac, char **av, char **env)
{
    t_token *data;
    t_list *list;
    data = malloc(sizeof(data));
  
    list = NULL;
    char *line;
    (void)ac;
    (void)av;
    // (void)env;
    while (1)
    {
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
            i = -1;
            if(!ft_strcmp(list->cmd, "echo"))
                echo(env, list);
            (list) =(list)->next;
        }
            printf("\n");
            free (line);
            free(list);
            list = NULL;
            free(data);
    }
}

// int main(int ac, char **av , char **env)
// {
//     (void)ac;
//     (void)av;
//     (void)env;
//     char *p = ft_strdup("\"$USER\"");
//    printf("%s\n",ft_expand(env, p));
// // ft_expand(env, p);

//     // char *p = ft_strdup("hello world");
//     // char *s;
//     // int i= 0;
//     // s = ft_strdup("");
//     // while(p[i])
//     // {
//     //     s = ft_charjoin(s, p[i]);
//     //     i++;
//     // }
//     // printf("%s\n", s);
// }