/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:38:56 by oezzaou           #+#    #+#             */
/*   Updated: 2023/06/01 17:44:06 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

void	show_tree(t_node *cmds)
{
	if (cmds->type == AND || cmds->type == OR)
		show_and_or(cmds);
	else if (cmds->type == PIPE)
		show_pipe(cmds);
	else if (cmds->type == SEQ)
		show_seq(cmds);
	else if (cmds->type == SUBSHELL)
		show_cmd(cmds);
	else
		show_cmd(cmds);
}

void	show_and_or(t_node *cmds)
{
	show_pipe(((t_and_or *)cmds)->left);
	if (((t_and_or *)cmds)->right->type == AND)
		show_and_or(((t_and_or *)cmds)->right);
	else
		show_pipe(((t_and_or *) cmds)->right);
}

void	show_pipe(t_node *cmds)
{
	if (cmds->type == CMD)
	{
		show_cmd(cmds);
		return ;
	}
	if (cmds->type == SUBSHELL)
	{
		show_and_or(cmds);
		return ;
	}
	show_seq(((t_pipe *)cmds)->left);
	if (((t_pipe *)cmds)->right->type == PIPE)
		show_pipe(((t_pipe *)cmds)->right);
	else
		show_seq(((t_pipe *) cmds)->right);
}

void	show_seq(t_node *cmds)
{
	if (cmds->type == CMD)
	{
		show_cmd(cmds);
		return ;
	}
	if (cmds->type == SUBSHELL)
	{
		show_and_or(cmds);
		return ;
	}
	show_cmd(((t_seq *)cmds)->left);
	if (((t_seq *)cmds)->right->type == SEQ)
		show_seq(((t_seq *)cmds)->right);
	else
		show_cmd(((t_seq *) cmds)->right);
}

void	show_cmd(t_node *node)
{
	t_cmd	*cmd;

	if (node->type == SUBSHELL)
	{
		show_and_or(node);
		return ;
	}
	cmd = (t_cmd *) node;
	printf("CMD| ====> (%s)\n", cmd->name);
	while (*cmd->args)
		printf("args -> %s\n", *(cmd->args++));
}

void	print_tokens(t_list *tokens)
{
	while (tokens)
	{
		printf("==========\nToken : %s\nType : %d\n", ((t_token *)tokens->content)->name, ((t_token *)tokens->content)->type);
		tokens = tokens->next;
	}
}
