# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 17:17:24 by lgertrud          #+#    #+#              #
#    Updated: 2026/03/17 15:57:38 by lgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp
OBJS = $(SRC:.cpp=.o)

# Colors
YELLOW = \e[93m
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
RESET = \033[0m

END = @echo "$(GREEN)✔ Compilation complete!$(RESET)\n\n\
To run the program: ./$(NAME)\n\
  $(GREEN) "Mommy, when I grow up, I want to be a bureaucrat!"$(RESET)\n\n\
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