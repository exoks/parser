/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:37:55 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/29 15:32:04 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/*###############################################################
#  	   * Includes :		    								 	#
###############################################################*/
# include "libft.h"

/*###############################################################
#  	   * define     :		    								#
###############################################################*/
typedef enum e_state
{
	start,
	redir,
	redir2,
	pipes,
	seq,
	string,
	quotes,
	end,
}	t_state;

// define :
typedef t_state	(*t_state_func)(char, t_state);

/*###############################################################
#  	   * struct     :		    								#
###############################################################*/
typedef struct s_token
{
	char	*name;
	t_state	type;
}	t_token;

/*###############################################################
#  	   * Functions :											#
###############################################################*/
// minishell toknizer
t_list		*tokenizer(char *line);

// utils :
t_state		get_next_state(t_state state, char input);

// function state
t_state		st_start(char input, t_state prv_state);
t_state		st_string(char input, t_state prv_state);
t_state		st_redir(char input, t_state prv_state);
t_state		st_pipes(char input, t_state prv_state);

#endif /* LEXER_H */
