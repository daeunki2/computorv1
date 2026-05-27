# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/27 18:52:59 by daeunki2          #+#    #+#              #
#    Updated: 2026/05/27 23:49:09 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computorv1
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g \
		-I. \
		-I./parser \
		-I./Error

OBJ_DIR = obj

SRCS = main.cpp \
		parser/parser.cpp \
		Error/Error.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME) 🛠️"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Build Complete! ✅"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files 🧹"
	@rm -rf $(OBJ_DIR)
	@echo "cleaning ✅"

fclean: clean
	@echo "Cleaning Executable 🧹"
	@rm -f $(NAME)
	@echo "fclean ✅"




re: fclean all

.PHONY: all clean fclean re
