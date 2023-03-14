/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:13:46 by rakhsas           #+#    #+#             */
/*   Updated: 2023/03/14 10:18:24 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void expaned_arg(char **env, char *arg, int s)
{
	char *p;

	p = ft_expand(env, arg, s);
	if (!p)
		printf("Command Not Found\n");
	else
		printf("%s", p);
	free(p);
}

void echo(char **env, t_list *list)
{
	int		i;
	int		n;
	char	*targ;

	i = -1;
	n = 0;
	if (!list->args)
		return;
	targ = ft_trim(list->args[i + 1]);
	if (list->args[i + 1] && ((!ft_strcmp(targ, "-n")) || (!ft_strcmp(targ, "-e"))))
	{
		i++;
		if (!ft_strcmp(targ, "-n"))
			n = 1;
	}
	while (list->args[++ i])
	{
		expaned_arg(env, list->args[i], SUCCESS);
		if (list->args[i + 1])
			printf(" ");
	}
	if (!n)
		printf("\n");
	free(targ);
}
