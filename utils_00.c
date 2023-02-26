#include "minishell.h"

void ft_skip_white_spaces(char *str, int *i)
{
    while (str[*i] == ' ')
    	(*i) ++;
}

int ft_handled_quotes(char *line)
{
	int i;
	int cpt;

	i = -1;
	cpt = 0;
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			cpt ++;
	}
	if (cpt % 2 == 0)
		return (1);
	return (0);
}

void	ft_lstadd_back(t_token **lst, t_token *new, int *i)
{
	t_token	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		*i = -1;
	}
}

t_token	*ft_lstnew(int type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (0);
    new->type = type;
	new->next = NULL;
	return (new);
}
