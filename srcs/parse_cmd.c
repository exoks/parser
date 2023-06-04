/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:40:39 by oezzaou           #+#    #+#             */
/*   Updated: 2023/06/01 17:52:42 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*parse_cmd(t_list **tokens)
{
	t_cmd	*cmd;
	t_list	*cursor;

	printf("PARSE TOKEN| => %s\n", get_token_name(*tokens));
	if (!ft_strcmp(get_token_name(*tokens), "("))
		return (parse_subshell(tokens));
	cmd = (t_cmd *) cmd_node();
	if (!cmd)
		return (0);
	cursor = *tokens;
	cmd->args = get_args(cursor);
	cmd->name = *(cmd->args);
	// I have to handle the path
	// Also in out
	while (tokens && *tokens && !is_non_terminal(*tokens))
		*tokens = (*tokens)->next;
	return ((t_node *) cmd);
}

int	get_args_count(t_list *tokens)
{
	t_list	*cursor;
	int		count;

	count = 0;
	cursor = tokens;
	while (cursor)
	{
		if (get_token_type(cursor) == redir || get_token_type(cursor) == redir2)
			cursor = cursor->next;
		else
			break ;
		cursor = cursor->next;
	}
	while (cursor && (get_token_type(cursor) != redir && get_token_type(cursor) != redir2))
	{
		count++;
		cursor = cursor->next;
	}
	return (count);
}

char	**get_args(t_list *tokens)
{
	char	**args;
	t_list	*cursor;
	int		i;

	args = malloc(sizeof(char *) * (get_args_count(tokens) + 1));
	if (!args)
		return (NULL);
	cursor = tokens;
	while (cursor)
	{
		if (get_token_type(cursor) == redir || get_token_type(cursor) == redir2)
			cursor = cursor->next;
		else
			break ;
		cursor = cursor->next;
	}
	i = 0;
	while (cursor && !is_redir(cursor) && !is_non_terminal(cursor))
	{
		args[i++] = get_token_name(cursor);
		cursor = cursor->next;
	}
	args[i] = 0;
	return (args);
}

char	*get_token_name(t_list *token)
{
	return (((t_token *) token->content)->name);
}

int	get_token_type(t_list *token)
{
	return (((t_token *)token->content)->type);
}
