# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 19:14:02 by oezzaou           #+#    #+#              #
#    Updated: 2023/05/26 16:11:56 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC			:= cc
NAME 		:= parser
SRCS_DIR	:= srcs
OBJS_DIR	:= objs
LIBFT_DIR	:= libft
SRCS		:= $(wildcard $(SRCS_DIR)/*.c)
OBJS		:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
INCLUDES	:= includes/
LIBFT		:= $(LIBFT_DIR)/libft.a
LINKS		:= readline

all: $(OBJS_DIR) $(NAME) 

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $^ -o $@ -I $(LIBFT_DIR) -I $(INCLUDES) -l $(LINKS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) -c $< -o $@ -I $(LIBFT_DIR)/includes -I $(INCLUDES)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

$(OBJS_DIR):
	@mkdir -p $(@)

.PHONY: all clean fclean re
