/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/03/02 19:24:33 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// void lexer(char *line, t_token **data)
// {
//    int i;
//    int check1;
//    int check2;
   
//    check1 = 1;
//    check2 = 1;
//    i = -1;
//    *data = NULL;
//    while (line[++i])
//    {
//        if(line[i] == '\"' && check1 == 1 && check2 == 1)
// 			check1 = 0;
// 		else if(line[i] == '\'' && check1 == 0 && check2 == 1)
// 			check1 = 1;
//         else if(line[i] == '\"' && check1 == 1 && check2 == 1)
// 			check2 = 0;
// 		else if(line[i] == '\"' && check1 == 1 && check2 == 0)
// 			check2 = 1;
//         else if (check1 == 1 && check2 == 1)
//         {
// 			if (!ft_strncmp(line + i, "<<", 2) && check1 == 1)
//             {
//                 i++;
//             	ft_lstadd_back(data, ft_lstnew(HERDOC), &check1);
//         	}
//             else if (line[i] == '>' && check1 == 1)
//                 ft_lstadd_back(data, ft_lstnew(GREAT), &check1);
//             else if (line[i] == '<' && check1 == 1)
//                 ft_lstadd_back(data, ft_lstnew(LESS), &check1);
//             else
//             {
//                 ft_lstadd_back(data, ft_lstnew(WRD), &check1);
//                 //check1 = 0;
//             }
//         }
//     }
// }

void lexer(char *line, t_token **data)
{
   int i;
   int check;
   
   check = 1;
   i = -1;
   *data = NULL;
   while (line[++i])
   {
		if (line[i] == '\"' && check == 1)
			check = 0;
		else if (line[i] == '\"' && check == 0)
			check = 1;
		else if (line[i] == '\'' && check == 1)
			check = 0;
		else if (line[i] == '\'' && check == 0)
			check =1;
		else if (check == 1)
		{
			if (!ft_strncmp(line + i, "<<", 2) && check == 1)
            {
                i++;
            	ft_lstadd_back(data, ft_lstnew(HERDOC), &check);
        	}
            else if (line[i] == '>')
                ft_lstadd_back(data, ft_lstnew(GREAT), &check);
            else if (line[i] == '<')
                ft_lstadd_back(data, ft_lstnew(LESS), &check);
            else
                ft_lstadd_back(data, ft_lstnew(WRD), &check);
		}
   }
}

void get_token(char *line, t_token **data)
{
    char **p;
    int i;

    i = -1;
    p = ft_split(line , '|');
    while(p[++i])
    {
        data[i] = malloc(sizeof(t_token));
        lexer(line, &data[i]);
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
    i = 1;
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
        get_token(line, data);
        p = ft_split_2(line , '|');
        i = 0;
        while (*data)
        {
                while (*data)
                {
                    printf("%d ", (*data)->type);
                    (*data) = (*data)->next;
                }
                printf("\n");
            i++;
        }
        i = -1;
        while(p[++i])
        {
            printf("%s\n", p[i]);
        }
        free (line);
    }
}
