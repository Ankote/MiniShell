/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:41:48 by aankote           #+#    #+#             */
/*   Updated: 2023/03/04 20:24:21 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char	**first_alloc(char const *s, char c)
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
		if (s[i] != c && test == 0)
		{
			test = 1;
			cpt++;
		}
		if (s[i] == c)
			test = 0;
		i++;
	}
	p = (char **)malloc(sizeof(char *) * (cpt + 1));
	return (p);
}

static char	**mini(char const *s, char c, char **p)
{
	size_t	i;
	size_t	k;
	int		start;

	i = 0;
	k = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
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

char	**ft_split_2(char const *s, char c)
{
	char	**p;
	char	**x;
	char *tmp;
    int i;

    i = -1;
	p = first_alloc(s, c);
	if (!p)
		return (0);
	x = mini(s, c, p);
    while(x[++i])
	{
		tmp = x[i];
		x[i] = fill_str(tmp);
		free(tmp);
	}
          
	return (x);
}
