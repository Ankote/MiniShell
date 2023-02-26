/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/02/26 20:50:26 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft(char *line, t_token **data)
{
   int i;
   int check;
   
   check = -1;
   i = -1;
   *data = NULL;
   while (line[++i])
   {
        if (line[i] == '>')
            ft_lstadd_back(data, ft_lstnew(GREAT), &check);
        else if (line[i] == '<')
            ft_lstadd_back(data, ft_lstnew(LESS), &check);
        // else if (line[i] == '|')
        //     ft_lstadd_back(data, ft_lstnew(PIPE), &check);
        else if(line[i] == ' ')
            check = -1;
        else if (check == -1)
        {
            ft_lstadd_back(data, ft_lstnew(WRD), &check);
            check = 0;
        }
   }
}

// int check_operators(char *line)
// {
//     int i;

//     i = -1;
//     while (line[++i])
//     {
//         if (line[i] == '<' || line[i] == '>'
//             || line[i] == '|')
//             return (1);   
//     }
//     return (0);
// }

// void get_token(char *line)
// {
// 	int i = 0;
	
// 	while(line[i])
// 	{
// 		if()
// 	}
// }
//View, edit and save tldraw files (.tldr)



int main(int ac, char **av)
{
    //int fd = open("file", O_CREAT |O_RDONLY, 000);
//     char *p[] = {"cat file1 file2", NULL};
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
        line = readline("\033[0;31mMinishell~$ \033[0m");
        if (!ft_strncmp(line, "stop", 4) || !ft_handled_quotes(line))
            return 0;
        i = -1;
        p = ft_split(line , '|');
        while (p[++i])
        {
            ft(p[i], &data[i]);
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
