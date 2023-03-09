/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:31 by aankote           #+#    #+#             */
/*   Updated: 2023/03/09 12:57:36 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



char *get_value(char **env, char *var)
{
    int i;

    i = -1;
    while(env[++i])
    {
        if(!ft_strncmp(env[i], var, ft_strlen(var)))
            return(env[i] + ft_strlen(var) + 1);
    }
    return(0);
}

