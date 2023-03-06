/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/03/04 21:51:10 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



// void ft_chcek_operators(char *str, t_token **data, int *i)
// {
//     while(str[(*i)++])
//     {
//         if((str[*i] != ' ' && str[*i] != '<' 
//             && str[*i] != '>'))
//         {
//             ft_lstadd_back(data, ft_lstnew(WRD));
//         }
//         else
//             return;
//     }
// }

// void lexer(char *line, t_token **data)
// {
//    int i;
//    int check;
   
//    check = 1;
//    i = -1;
//    *data = NULL;
//    while (line[++i])
//    {
// 		if (line[i] == '\"' && check == 1)
//         {
//              ft_lstadd_back(data, ft_lstnew(WRD));
// 			check = 0;
//         }
// 		else if (line[i] == '\"' && check == 0)
//             check = 1;
// 		else if (line[i] == '\'' && check == 1)
// 			check = 0;
// 		else if (line[i] == '\'' && check == 0)
// 			check =1;
// 		else if (check == 1)
// 		{
// 			if (!ft_strncmp(line + i, "<<", 2) && check == 1)
//             {
//                 i++;
//             	ft_lstadd_back(data, ft_lstnew(HERDOC));
//         	}
//             else if (line[i] == '>')
//                 ft_lstadd_back(data, ft_lstnew(GREAT));
//             else if (line[i] == '<')
//                 ft_lstadd_back(data, ft_lstnew(LESS));
//             else if (line[i] == ' ')
//                 continue;
//             else
//             {
//                 ft_lstadd_back(data, ft_lstnew(WRD));
//                 while (line[i] && !check_operators(line[i]))
//                     i++;
//                 i--;
//             }
// 		}
//    }
// }

// void get_token(char *line, t_token **data)
// {
//     char **p;
//     int i;

//     i = -1;
//     p = ft_split(line , '|');
//     while(p[++i])
//     {
//         data[i] = malloc(sizeof(t_token));
//         lexer(line, &data[i]);
//     }  
// }

// void ft_g(char *line, t_token **data)
// {
//     char **p;
//     int i;

//     i = 0;
//     p = ft_split(line, ' ');
//     while(p[i])
//     {
//         if(ft_strncmp(p[i], ">", ft_strlen(p[i])))
//             ft_lstadd_back(data, ft_lstnew(GREAT));
//         if(ft_strncmp(p[i], "<<", ft_strlen(p[i])))
//             ft_lstadd_back(data, ft_lstnew(HERDOC));
//         if(ft_strncmp(p[i], "<", ft_strlen(p[i])))
//             ft_lstadd_back(data, ft_lstnew(LESS));
//         else 
//              ft_lstadd_back(data, ft_lstnew(WRD));
//     }
// }


int main(int ac, char **av)
{
//    int fd = open("file", O_CREAT |O_RDONLY, 000);
//    char *p[] = {"cat file1 file2", NULL};
//    int id = execve("/bin/ls", p, NULL);
//    printf("%d\n", id); 
    t_token *data;
  
    char *line;
    (void)ac;
    
    (void)av;
    
    while (1)
    {
        //line = readline("\033[0;31m𝑴𝒊𝒏𝒊𝒔𝒉𝒆𝒍𝒍~$ \033[0m\e[1;59m");
       line = readline("minishell~$");
        if (!ft_strncmp(line, "stop", 4))
            return 0;
        if (!check_single_quotes(line))
        {
            printf("Syntax Error!\n");
            continue;
        }
        get_token(line, &data);
        while (data)
        {
         //   type_arg(data);
            printf("%p %p %p %s\n",data, data->next, data->prev, data->val);
            data = data->next;
        } 
        free (line);
    }
}
