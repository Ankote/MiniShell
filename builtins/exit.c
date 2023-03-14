/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:24:00 by rakhsas           #+#    #+#             */
/*   Updated: 2023/03/13 21:23:01 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_args(char **args)
{
	int	i;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
		i++;
	return (i + 1);
}

void	is_numeric(t_list *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	data->global = malloc(sizeof(t_global));
	while (data->args[0][j])
	{
		if ((data->args[0][0] == '-' || data->args[0][0] == '+') && data->args[0][1] == '0'
		&& !ft_atoi(&data->args[0][0]))
			(printf("exit\n"), exit(0));
		if (data->args[0][j] != '0' && !ft_atoi(&data->args[0][j]))
		{
			write(2, "exit: ", 6);
			write(2, data->args[0], ft_strlen(data->args[0]));
			write(2, ": numeric argument required\n", 28);
			data->global->exit_status = 255;
			exit(data->global->exit_status);
		}
		j++;
	}
}

int	ft_exit(t_list *data)
{
	long long	len;

	len = count_args(data->args);
	if (!data->args[0])
		(printf("exit\n"), exit(0));
	is_numeric(data);
	if (len > 2)
		write(2, "exit\nminishell: exit: too many arguments\n", 41);
	else if (len == 2)
	{
		len = ft_atoi(data->args[0]);
		if (data->args[0][0] != '-' && len < 0)
		{
			write(2, "exit: ", 6);
			write(2, data->args[0], ft_strlen(data->args[0]));
			write(2, ": numeric argument required\n", 28);
			exit(data->global->exit_status);
		}
		else
			(printf("exit\n"), data->global->exit_status = ft_atoi(data->args[0]),  exit(data->global->exit_status));
	}
	return (1);
}
