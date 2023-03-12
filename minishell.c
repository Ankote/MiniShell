/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/03/12 20:26:37 by aankote          ###   ########.fr       */
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

void expaned_arg(char **env, char *arg, int s)
{
    char *p;
    
    p = ft_expand(env, arg, s);
    printf("%s", p);
    free(p);
}

void echo(char **env, t_list *list)
{
    int i;
    int n;
    char *targ;
    
    i = -1;
    n = 0;
    if(!list->args)
        return;
    targ =ft_trim(list->args[i + 1]);
    if(list->args[i + 1] && ((!ft_strcmp(targ, "-n")) || (!ft_strcmp(targ, "-e"))))
    {
        i++;
        if(!ft_strcmp(targ, "-n"))
            n = 1;
    }
    while(list->args[++ i])
    {
        expaned_arg(env, list->args[i], SUCCESS);
        if (list->args[i + 1])
            printf(" ");
    }
    if(!n)
        printf("\n");
    free(targ);
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
    (void)env;
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
            free (line);
            free(list);
            list = NULL;
            free(data);
    }
}

// int main()
// {
//     char *p = ft_strdup("hello");
//     printf("%s", ft_trim(p));
// }
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