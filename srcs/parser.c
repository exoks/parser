/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:23:32 by oezzaou           #+#    #+#             */
/*   Updated: 2023/06/01 18:04:06 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

# define TYPE(A) (AND * (!ft_strcmp(A, "&&"))) + (OR * (!ft_strcmp(A, "||")))

t_node	*parse_and_or(t_list **tokens)
{
	t_node	*and_or;

	and_or = parse_pipe(tokens);
	if (tokens && *tokens && !ft_strcmp(get_token_name(*tokens), "&&"))
	{
		*tokens = (*tokens)->next;
		and_or = and_or_node(and_or, parse_and_or(tokens), AND);
	}
	return (and_or);
}

t_node	*parse_pipe(t_list **tokens)
{
	t_node	*pipe;

	pipe = parse_seq(tokens);
	if (tokens && *tokens && get_token_type(*tokens) == pipes)
	{
		*tokens = (*tokens)->next;
		pipe = pipe_node(pipe, parse_pipe(tokens));
	}
	return (pipe);
}

t_node	*parse_seq(t_list **tokens)
{
	t_node	*seq;

	seq = parse_cmd(tokens);
	if (tokens && *tokens && !ft_strcmp(get_token_name(*tokens), ";"))
	{
		*tokens = (*tokens)->next;
		seq = sequencing_node(seq, parse_seq(tokens));
	}
	return (seq);
}

t_node	*parse_subshell(t_list **tokens)
{
	t_node	*subshell;

	if (!ft_strcmp(get_token_name(*tokens), "("))
		*tokens = (*tokens)->next;
	// Need to use sub tokens
	subshell = parse_and_or(tokens);
	if (tokens && *tokens && !ft_strcmp(get_token_name(*tokens), ")"))
		*tokens = (*tokens)->next;
	if (tokens && *tokens && !ft_strcmp(get_token_name(*tokens), "("))
	{
		*tokens = (*tokens)->next;
		subshell = subshell_node(subshell, parse_subshell(tokens));
	}
	return (subshell);
}

t_node	*parser(char *line)
{
	t_list	*tokens;
	t_node	*cmds;

	tokens = tokenizer(line);
	printf("START| => %p\n", tokens);
	if (ft_strnstr(line, "&&", ft_strlen(line)))
		cmds = parse_and_or(&tokens);
	else if (ft_strchr(line, '|'))
		cmds = parse_pipe(&tokens);
	else if (ft_strchr(line, ';'))
		cmds = parse_seq(&tokens);
	else
		cmds = parse_cmd(&tokens);
	printf("END| => %p\n", tokens);
	return (cmds);
}
