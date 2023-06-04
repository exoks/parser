/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:33:37 by oezzaou           #+#    #+#             */
/*   Updated: 2023/05/31 23:37:36 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

int	is_non_terminal(t_list *token)
{
	char	*name;

	name = get_token_name(token);
	if (!ft_strcmp(name, "|") || !ft_strcmp(name, ";") || !ft_strcmp(name, "(") || !ft_strcmp(name, ")")
			|| !ft_strcmp(name, "&&"))
		return (TRUE);
	return (FALSE);
}

int	is_redir(t_list *token)
{
	if (get_token_type(token) == redir || get_token_type(token) == redir2)
		return (TRUE);
	return (FALSE);
}
/*
t_list *get_subshell_tokens(t_list *tokens)
{
	t_list	*subshell;
	t_list	*cursor;

	subell = 0;
	cursor = tokens;
	while (tokens)
	{
		ft_lstadd_back(subshell, 
		tokens
	}
	return (subshell);
}
*/
