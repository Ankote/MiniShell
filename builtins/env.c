/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:23:39 by rakhsas           #+#    #+#             */
/*   Updated: 2023/03/14 11:59:41 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		write(2, "env: No such file or directory", 30);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}