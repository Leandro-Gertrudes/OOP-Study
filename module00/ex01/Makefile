# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 12:52:09 by lgertrud          #+#    #+#              #
#    Updated: 2025/09/25 15:42:11 by lgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = 00-main.cpp 10-add.cpp 20-search.cpp
OBJS = $(SRC:.cpp=.o)
INCLUDE = -I

# Colors
YELLOW = \e[93m
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
RESET = \033[0m

END = @echo "\n\033[1;32m✔ Compilation complete!\033[0m\n\n\
To run the program:\n\
  \033[1;34m./phonebook\033[0m\n"

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	$(END)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing object files..."
	@rm -f $(OBJS)

fclean:
	@echo "$(RED)[FCLEAN]$(RESET) Removing all file generated..."
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all