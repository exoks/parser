/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:23:48 by oezzaou           #+#    #+#             */
/*   Updated: 2023/05/31 23:43:01 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSER_H
# define PARSER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "lexer.h"
# include <readline/readline.h>

# define CMD		1
# define SUBSHELL	2
# define SEQ		3
# define PIPE		4
# define AND		5
# define OR			6

typedef struct s_node
{
	int			type;
}				t_node;

typedef struct s_and_or
{
	int		type;
	t_node	*right;
	t_node	*left;
}				t_and_or;

typedef struct s_pipe
{
	int			type;
	t_node		*right;
	t_node		*left;
}				t_pipe;

typedef struct s_seq
{
	int			type;
	t_node		*right;
	t_node		*left;

}				t_seq;

typedef struct s_subshell
{
	int			type;
	t_node		*left;
	t_node		*right;
}				t_subshell;

typedef struct s_cmd
{
	int			type;
	char		*name;
	char		*path;
	char		**args;
	t_list		*in_out;	
	pid_t		pid;
}				t_cmd;

/* ****************** PARSER ****************** */
t_node	*parser(char *line);

/* *************** CONSTRUCTORS *************** */
t_node	*and_or_node(t_node *left, t_node *right, int type);
t_node	*pipe_node(t_node *left, t_node *right);
t_node	*sequencing_node(t_node *left, t_node *right);
t_node	*subshell_node(t_node *left, t_node *right);
t_node	*cmd_node(void);

/* ***************** PARSING ***************** */
t_node	*parse_and_or(t_list **tokens);
t_node	*parse_pipe(t_list **tokens);
t_node	*parse_seq(t_list **tokens);
t_node	*parse_subshell(t_list **tokens);
t_node	*parse_cmd(t_list **tokens);

/* ***************** TEST ******************** */
char	*get_token_name(t_list *token);
int		get_token_type(t_list *token);
int		get_args_count(t_list *token);
char	**get_args(t_list *tokens);

int		is_non_terminal(t_list *token);
int		is_redir(t_list *token);
t_list	*subtokens(t_list *tokens);

/* **************** TREE ******************** */
void	show_tree(t_node *cmds);
void	show_and_or(t_node *cmds);
void	show_pipe(t_node *cmds);
void	show_seq(t_node *cmds);
void	show_cmd(t_node *node);
void	show_subshell(t_node *node);
void	print_tokens(t_list *tokens);

#endif
