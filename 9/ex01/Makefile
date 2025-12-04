CXX = c++
WFLAGS = -Wall -Wextra -Werror
CFLAGS = -I. -std=c++98 -Wpedantic $(WFLAGS) $(DEBUG)
DEBUG = -g3 -fstandalone-debug
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = RPN
SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)
INC = RPN.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
