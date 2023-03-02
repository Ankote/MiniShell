/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/03/01 15:47:35 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void lexer(char *line, t_token **data)
{
   int i;
   int check;
   
   check = -1;
   i = -1;
   *data = NULL;
   while (line[++i])
   {
        if (!ft_strncmp(line + i, "<<", 2))
        {
            i++;
            ft_lstadd_back(data, ft_lstnew(HERDOC), &check);
        }
        else if (line[i] == '>')
            ft_lstadd_back(data, ft_lstnew(GREAT), &check);
        else if (line[i] == '<')
            ft_lstadd_back(data, ft_lstnew(LESS), &check);
        else if(line[i] == ' '|| line[i] == '\"' || line[i] == '\'')
            check = -1;
        else if (check == -1)
        {
            ft_lstadd_back(data, ft_lstnew(WRD), &check);
            check = 0;
        }
   }
}

int main(int ac, char **av)
{
//    int fd = open("file", O_CREAT |O_RDONLY, 000);
//    char *p[] = {"cat file1 file2", NULL};
//    int id = execve("/bin/ls", p, NULL);
//    printf("%d\n", id);
    t_token **data;
  
    char **p;
    int i;
    char *line;
    (void)ac;
    (void)av;
    data = malloc(sizeof(t_token *));
    
    while (1)
    {
        line = readline("\033[0;31m𝑴𝒊𝒏𝒊𝒔𝒉𝒆𝒍𝒍~$ \033[0m\e[1;59m");
        if (!ft_strncmp(line, "stop", 4))
            return 0;
        if (!check_single_quotes(line))
        {
            printf("Syntax Error!\n");
            continue;
        }
        i = -1;
        p = ft_split_2(line , '|');
        while (p[++i])
        {
            lexer(p[i], &data[i]);
            printf("%s\n", p[i]);
        }
        data[i] = NULL;
        i = 0;
        while (data[i])
        {
                while (data[i])
                {
                    printf("%d ", data[i]->type);
                    data[i] = data[i]->next;
                }
                printf("\n");
            i++;
        }
        free (line);
    }
}
