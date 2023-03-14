/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:56:34 by aankote           #+#    #+#             */
/*   Updated: 2023/03/14 11:56:21 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft(int c)
{
	if (c == CMD)
		printf("CMD ");
	if (c == ARG)
		printf("ARG ");
	if (c == TRUNC)
		printf("TRUNC ");
	if (c == APPEND)
		printf("APPEND ");
	if (c == INPUT)
		printf("INPUT ");
	if (c == PIPE)
		printf("PIPE ");
	if (c == INFILE)
		printf("INFILE ");
	if (c == OUTFILE)
		printf("OUTFILE ");
	if (c == HERDOC)
		printf("HERDOC ");
	if (c == LIMITER)
		printf("LIMITER ");
}

void	tokens(char *line, t_token **token)
{
	t_token	*tmp;

	get_token(line, token);
	tmp = *token;
	while (tmp)
	{
		type_arg(tmp);
		tmp = tmp->next;
	}
}

void	ft_next(char *line, t_token *data, char **env, t_list *list)
{
	int	i;

	i = 0;
	tokens(line, &data);
	get_cmd(&list, &data);
	while (list)
	{
		i = -1;
		str_tolower(list->cmd);
		if (!ft_strcmp(list->cmd, "echo"))
			echo(env, list);
		else if (!ft_strcmp(list->cmd, "pwd"))
		{
			expaned_arg(env, "$PWD", SUCCESS);
			printf("\n");
		}
		else if (!ft_strcmp(list->cmd, "exit"))
			ft_exit(list);
		else if (!ft_strcmp(list->cmd, "unset"))
			ft_unset(list);
		else if (!ft_strcmp(list->cmd, "env"))
			ft_env(env);
		(list) = (list)->next;
	}
	free (line);
	free (list);
	list = NULL;
	free (data);
}

int	main(int ac, char **av, char **env)
{
	t_token	*data;
	t_list	*list;
	char	*line;

	data = malloc(sizeof(data));
	list = NULL;
	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		line = readline("minishell$ ");
		if (!check_single_quotes(line))
		{
			printf("Syntax Error!\n");
			continue ;
		}
		add_history(line);
		ft_next(line, data, env, list);
	}
}

// int main()
// {
//     char *p = ft_strdup("hello");
//     printf("%s", ft_trim(p));
// }
// int main(int ac, char **av , char **env)
// {
//     (void)ac;
//     (void)av;
//     (void)env;
//     char *p = ft_strdup("\"$USER\"");
//    printf("%s\n",ft_expand(env, p));
// // ft_expand(env, p);

//     // char *p = ft_strdup("hello world");
//     // char *s;
//     // int i= 0;
//     // s = ft_strdup("");
//     // while(p[i])
//     // {
//     //     s = ft_charjoin(s, p[i]);
//     //     i++;
//     // }
//     // printf("%s\n", s);
// }