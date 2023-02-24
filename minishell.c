/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/02/24 20:02:15 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft(char *line, t_token **data)
{
   int i;
   int check;
   
   check = -1;
   i = -1;
   while (line[++i])
   {
        if (line[i] == '>')
        {
            ft_lstadd_back(data, ft_lstnew(GREAT));
            check = -1;
        }
        else if (line[i] == '<')
        {
            ft_lstadd_back(data, ft_lstnew(LESS));
            check = -1;
        }
        else if (line[i] == '|')
        {
            ft_lstadd_back(data, ft_lstnew(PIPE));
            check = -1;
        }
        // else if(line[i] == ' ')
        //     ft_skip_spaces(line, &i);
        else if (check == -1)
        {
            ft_lstadd_back(data, ft_lstnew(WRD));
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
int main()
{
    t_token *data;
    char *line = "cat < Makefile | grep m > outfile";

    data = NULL;

    ft(line, &data);
    
    while (data)
    {
        printf("%d\t", data->type);
        data = data->next;
    }
   // printf("%d\n", check_operators(cmd));
}