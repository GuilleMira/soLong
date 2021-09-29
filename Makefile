# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 12:11:49 by guilmira          #+#    #+#              #
#    Updated: 2021/09/29 13:02:48 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
LIB_DIR		= libft_submodule
LIB			= $(LIB_DIR)/libft.a
INCLUDES	= -I ./0includes -I ./libft_submodule/0includes
INCLUDES_LIBX	= -lmlx -framework OpenGL -framework AppKit
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		= so_long.c
OBJS		= $(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

#%.o: %.c
#-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) $(INCLUDES_LIBX) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled" $(NONE)

exe: $(NAME)
	./$(NAME)

#$(NAME): $(OBJS)
#$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) -o $(NAME)
#@echo "'$(NAME)' is now compiled."

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
GREEN='\033[1;32m'
