/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:42:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/05/31 22:18:53 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

t_node	*and_or_node(t_node *left, t_node *right, int type)
{
	t_and_or	*and_or;

	and_or = malloc(sizeof(t_and_or));
	if (!and_or)
		return (NULL);
	and_or->type = type;
	and_or->left = left;
	and_or->right = right;
	return ((t_node *) and_or);
}

t_node	*pipe_node(t_node *left, t_node *right)
{
	t_pipe	*pipe;

	pipe = malloc(sizeof(t_pipe));
	if (!pipe)
		return (NULL);
	pipe->type = PIPE;
	pipe->left = left;
	pipe->right = right;
	return ((t_node *) pipe);
}

t_node	*sequencing_node(t_node *left, t_node *right)
{
	t_seq	*seq;

	seq = malloc(sizeof(t_seq));
	if (!seq)
		return (NULL);
	seq->type = SEQ;
	seq->left = left;
	seq->right = right;
	return ((t_node *) seq);
}

t_node	*subshell_node(t_node *left, t_node *right)
{
	t_subshell	*subshell;

	subshell = malloc(sizeof(t_subshell));
	if (!subshell)
		return (NULL);
	subshell->type = SUBSHELL;
	subshell->left = left;
	subshell->right = right;
	return ((t_node *) subshell);
}

t_node	*cmd_node(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->type = CMD;
	return ((t_node *) cmd);
}
