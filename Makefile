# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/27 18:52:59 by daeunki2          #+#    #+#              #
#    Updated: 2026/05/27 18:53:55 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computorv1
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g\
		-I $(SRC_DIR)/parser \
		-I $(SRC_DIR)/solver \


OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc


SRCS = $(SRC_DIR)/main.cpp \
		$(SRC_DIR)/parser/config_parser.cpp \
		$(SRC_DIR)/parser/Location.cpp \

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME) 🛠️"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Build Complete! ✅"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
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