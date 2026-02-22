# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 14:54:47 by lgertrud          #+#    #+#              #
#    Updated: 2025/10/24 12:09:20 by lgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = NoViolence

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRC:.cpp=.o)

# Colors
YELLOW = \e[93m
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
RESET = \033[0m

END = @echo "$(GREEN)✔ Compilation complete!$(RESET)\n\n\
To run the program: ./NoViolence\n\
  $(RED) "UNNECESSARY VIOLENCE"$(RESET)\n\n\
Enjoy 🚀"

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
	@echo "$(RED)[FCLEAN]$(RESET) Removing executable..."
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all