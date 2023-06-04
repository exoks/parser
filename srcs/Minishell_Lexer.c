/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell_Lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:58:44 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/27 09:52:49 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_state	get_next_state(t_state state, char input)
{
	t_state_func	state_func[4];

	state_func[start] = st_start;
	state_func[redir] = st_redir;
	state_func[redir2] = st_redir;
	state_func[pipes] = st_pipes;
	if (state < 4)
		return (state_func[state](input, state));
	return (st_string(input, state));
}

t_token	*create_token(char *start, char *end, t_state type)
{
	t_token	*new_token;
	char	*name;

	new_token = malloc(sizeof(t_token));
	name = malloc(end - start + 1);
	if (new_token == NULL || name == NULL)
	{
		free(new_token);
		free(name);
		return (NULL);
	}
	new_token->name = name;
	new_token->type = type;
	while (start < end)
		*name++ = *start++;
	*name = 0;
	return (new_token);
}

t_list	*listadd_token(t_list **list, t_token *new_token)
{
	t_list	*new_node;

	new_node = ft_lstnew(new_token);
	if (new_token == NULL || new_node == NULL)
	{
		ft_lstclear(list, free);
		return (NULL);
	}
	ft_lstadd_back(list, new_node);
	return (*list);
}

t_list	*tokenizer(char *line)
{
	t_state	cur_state;
	t_state	prv_state;
	t_list	*tokens;
	char	*cursor;

	prv_state = start;
	tokens = NULL;
	while (line != NULL)
	{
		cur_state = get_next_state(prv_state, *line);
		if (prv_state == start && cur_state == end)
			break ;
		if (cur_state == end && prv_state != start)
		{
			if (!listadd_token(&tokens, create_token(cursor, line, prv_state)))
				return (NULL);
			prv_state = start;
			continue ;
		}
		if (prv_state == start)
			cursor = line;
		prv_state = cur_state;
		line++;
	}
	return (tokens);
}
