/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:55:13 by aankote           #+#    #+#             */
/*   Updated: 2023/03/02 09:18:51 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  check_quotes_util(char *str, int *check, int *i)
{
	while(str[*i])
	{
		if(str[*i] == '\'' && *check == 1)
			*check = 0;
		else if (str[*i] == '\'' && *check == 0)
		{
			*check = 1;
			return;
		}
		(*i)++;
	}
}

int check_single_quotes(char *str)
{
	int i;
	int check;

	i = -1;
	check = 1;
		
	while(str[++i])
	{
		if(str[i] == '\"' && check == 1)
			check = 0;	
		else if (str[i] == '\"' && check == 0)
			check = 1;
		else if (str[i] == '\'' && check == 1)
			check_quotes_util(str, &check, &i);
	}
	return (check);
}

int count_str(char *str)
{
	int i;
	int check;
	int cpt;

	i = -1;
	check = 1;
	cpt = 0;
	while(str[++i])
	{
		if(str[i] == '\"' && check == 1)
			check = 0;	
		else if (str[i] == '\"' && check == 0)
			check = 1;
		else if (str[i] == '\'' && check == 1)
			check = 0;
		else if (str[i] == '\'' && check == 0)
			check = 1;
		else
			cpt ++;
			
	}
	return (cpt);
}

void  check_single_quot(char *str, char *p, int *check, int *i, int *j)
{
	while(str[*i])
	{
		if(str[*i] == '\'' && *check == 1)
			*check = 0;
		else if (str[*i] == '\'' && *check == 0)
		{
			*check = 1;
			return;
		}
		else 
			p[(*j)++] = str[(*i)];
		(*i)++;
	}
}

char *fill_str(char *str)
{
	int i;
	int check;
	char *p;
	int j;

	i = -1;
	check = 1;
	j = 0;
	p = malloc(count_str(str) + 1);
	printf("%d\n",count_str(str) );
	if (!p)
		return (0);
	while(str[++i])
	{
		if(str[i] == '\"' && check == 1)
			check = 0;	
		else if (str[i] == '\"' && check == 0)
			check = 1;
		else if (str[i] == '\'' && check == 1)
			check_single_quot(str, p , &check, &i, &j);
		else
			p[j++] = str[i];
	}
		p[j] = 0;
	return (p);
}