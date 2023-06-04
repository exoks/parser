/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:44:46 by oezzaou           #+#    #+#             */
/*   Updated: 2023/05/31 16:20:33 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

int	main(void)
{
	char	*line;
	t_node	*ast;

	while (1)
	{
		line = readline("minishell> ");
		ast = parser(line);
		show_tree(ast);
	}
	return (0);
}
