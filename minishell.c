/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/13 10:08:19 by rakhsas          ###   ########.fr       */
=======
/*   Updated: 2023/03/13 10:29:44 by aankote          ###   ########.fr       */
>>>>>>> 9b6d852c9e4ad9c4c2fe24f40379383471ab79f9
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft(int c)
{
<<<<<<< HEAD
	if (c == CMD)
		printf("CMD ");
	if (c == ARG)
		printf("ARG ");
	if (c == TRUNC)
		printf("TRUNC ");
	if (c == APPEND)
		printf("APPEND ");
	if (c == INPUT)
		printf("INPUT ");
	if (c == PIPE)
		printf("PIPE ");
	if (c == INFILE)
		printf("INFILE ");
	if (c == OUTFILE)
		printf("OUTFILE ");
	if (c == HERDOC)
		printf("HERDOC ");
	if (c == LIMITER)
		printf("LIMITER ");
=======
    get_token(line, token);
    t_token *tmp;
    
    tmp = *token;
    while (tmp)
    {
        type_arg(tmp);
        // ft(tmp->type);
       //printf(".%s ", tmp->val);
        tmp = tmp->next;
    }
>>>>>>> 9b6d852c9e4ad9c4c2fe24f40379383471ab79f9
}

void	tokens(char *line, t_token **token)
{
	t_token	*tmp;

	get_token(line, token);
	tmp = *token;
	while (tmp)
	{
		type_arg(tmp);
		tmp = tmp->next;
	}
}

void	ft_next(char *line, t_token *data, char **env, t_list *list)
{
<<<<<<< HEAD
	int	i;

	i = 0;
	tokens(line, &data);
	get_cmd(&list, &data);
	while (list)
	{
		i = -1;
		str_tolower(list->cmd);
		if (!ft_strcmp(list->cmd, "echo"))
			echo(env, list);
		else if (!ft_strcmp(list->cmd, "pwd"))
		{
			expaned_arg(env, "$PWD", SUCCESS);
			printf("\n");
		}
		else if (!ft_strcmp(list->cmd, "exit"))
		{
			//ft_exit(list);
		}
		(list) = (list)->next;
	}
	free (line);
	free (list);
	list = NULL;
	free (data);
}

int	main(int ac, char **av, char **env)
{
	t_token	*data;
	t_list	*list;
	char	*line;

	data = malloc(sizeof(data));
	list = NULL;
	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		line = readline("minishell$ ");
		if (!check_single_quotes(line))
		{
			printf("Syntax Error!\n");
			continue ;
		}
		add_history(line);
		ft_next(line, data, env, list);
	}
=======
    int i;
    int n;
    char *targ;
    
    i = -1;
    n = 0;
    if(!list->args)
    {
        printf("\n");
        return;
    }
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

    int i = 0;
    while (++i < 4)
    {
       line = readline("\033[1;33mminishell~$ \033[0m");
        
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
             if(!ft_strcmp(list->cmd, "exit"))
                exit(0);
            if(!ft_strcmp(list->cmd, "pwd"))
            {
                expaned_arg(env, "$PWD", SUCCESS);
                printf("\n");
            }   
            (list) =(list)->next;
        }
            free (line);
            free(list);
            list = NULL;
            free(data);
    }
>>>>>>> 9b6d852c9e4ad9c4c2fe24f40379383471ab79f9
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