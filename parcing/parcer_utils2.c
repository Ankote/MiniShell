/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:52:16 by aankote           #+#    #+#             */
/*   Updated: 2023/03/10 20:40:32 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void free_double(char **p)
{
    int i;

    i = 0;
    while(p && p[i])
        free(p[i++]);
    free(p);
}

char **ft_realloc(char **p, char *str)
{
    int i;
    char **rp;
    
    i = 0;
  
    // if(!p)
    //     return (NULL);
    while(p && p[i])
        i++;
     rp = (char **)malloc(sizeof(char *) * (i + 2));
     i = 0;
     while(p && p[i])
     {
         rp[i] = ft_calloc(1, 1);
         rp[i] = ft_strjoin(rp[i], p[i]);
         i++;
     }
    
     rp[i] = ft_calloc(1, 1); 
     rp[i] = ft_strjoin(rp[i], str);
     
     i ++;
     rp[i] = NULL;
     return(free_double(p),rp);
}

void get_infile(t_list *list, char *val)
{
    list->infile = open(val, O_RDONLY);
    if(list->infile == -1)
        perror(val);
}

void get_outfile(t_list *list, char *val, int type)
{
    if (type == OUTFILE)
        list->outfile = open(val, O_CREAT | O_TRUNC | O_RDWR, 0777);
    else
         list->outfile = open(val, O_CREAT | O_RDWR, 0777);
    if(list->outfile == -1)
        perror(val);
}