/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:37:08 by aankote           #+#    #+#             */
/*   Updated: 2023/02/24 14:13:05 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_operators(char c)
{
   if (c == '<' || c == '>' || c == '|' || c == ' ')
            return (1);   
    return (0);
}

static void	*ft_free(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
	return (NULL);
}

static char	**first_alloc(char const *s)
{
	int		i;
	int		cpt;
	int		test;
	char	**p;

	i = 0;
	test = 0;
	cpt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!check_operators(s[i]) && test == 0)
		{
			test = 1;
			cpt++;
		}
		if (check_operators(s[i]))
			test = 0;
		i++;
	}
	p = (char **)malloc(sizeof(char *) * (cpt + 1));
	return (p);
}

static char	**mini(char const *s, char **p)
{
	size_t	i;
	size_t	k;
	int		start;

	i = 0;
	k = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (!check_operators(s[i]) && start == -1)
			start = i;
		else if ((check_operators(s[i]) || i == ft_strlen(s)) && start >= 0)
		{
			p[k++] = ft_substr(s, start, i - start);
			if (!p[k - 1])
				return (ft_free(p));
			start = -1;
		}
		i++;
	}
	p[k] = NULL;
	return (p);
}

char	**ft_split_op(char const *s)
{
	char	**p;
	char	**x;

	p = first_alloc(s);
	if (!p)
		return (0);
	x = mini(s, p);
	return (x);
}
