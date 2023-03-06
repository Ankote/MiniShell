/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:50:47 by aankote           #+#    #+#             */
/*   Updated: 2023/03/04 21:53:17 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		quotes(char *line, int index)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (line[i] && i != index)
	{	
		if (open == 0 && line[i] == '\"')
			open = 1;
		else if (open == 1 && line[i] == '\"')
			open = 0;
		else if (open == 0 && line[i] == '\'')
			open = 2;
		else if (open == 2 && line[i] == '\'')
			open = 0;
		i++;
	}
	return (open);
}
// "zfvsfv'"""
char *ft_charjoin(char *s, char c)
{
	char *p;
	int i;
	
	i = 0;
	p  = malloc(ft_strlen(s) + 2);
	while(s[i])
	{
		p[i] = s[i];
		i ++;
	}	
	p[i++] = c;
	p[i] = 0;
	return (p);
}

char *ft_join_free(char *s1, char c)
{
	char *tmp;

	tmp = ft_charjoin(s1, c);
	free(s1);
	return(tmp);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


void	type_arg(t_token *token)
{
	if (ft_strcmp(token->val, ">") == 0)
		token->type = TRUNC;
	else if (ft_strcmp(token->val, ">>") == 0)
		token->type = APPEND;
	else if (ft_strcmp(token->val, "<") == 0)
		token->type = INPUT;
	else if (ft_strcmp(token->val, "|") == 0)
		token->type = PIPE;
	else if (token->prev == NULL || token->prev->type >= TRUNC)
		token->type = CMD;
	else
		token->type = ARG;
}

int		ignore_sep(char c, char *line, int index)
{
	if(quotes(line, index))
		return (0);
	if (c && c == '|')
		return (1);
	else if (c && c == '>')
		return (1);
    else if (c && c == ' ')
		return (1);
	else if (c && c == '<')
		return (1);
	return (0);
}


void get_token(char *line, t_token **token)
{
    int i;
	char *p;
    
	*token = NULL;
    i = -1;
    while(line[++i])
    {
		p = ft_calloc(1, 1);
		if(line[i] && !ignore_sep(line[i], line, i))
		{
			while (line[i] && !ignore_sep(line[i], line, i))
			{
				while((line[i] == '\"' && (!quotes(line, i) || quotes(line, i) == 1))
					|| ((line[i] == '\'' && (!quotes(line, i) || quotes(line, i) == 2))))
					i++;
				p = ft_charjoin(p, line[i]);
				if((line[i + 1] && ignore_sep(line[i + 1], line, i)) || !line[i + 1] )
				{
					ft_lstadd_back(token, ft_lstnew(CMD, p));
					break;
				}
				i ++;
			}
		}
		else
		{
			if(line[i] && ignore_sep(line[i], line, i))
			{
				while (line[i] && ignore_sep(line[i], line, i) && line[i] != ' ')
				{
					p = ft_join_free(p, line[i]);
					if((line[i + 1] && !ignore_sep(line[i + 1], line, i)) || !line[i + 1] || line[i+1] == ' ')
					{
						ft_lstadd_back(token, ft_lstnew(CMD, p));
						break;
					}
					i ++;
				}
			}
		}
    }
}


