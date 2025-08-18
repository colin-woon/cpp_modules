CXX = c++
WFLAGS = -Wall -Wextra -Werror
CFLAGS = -I. -std=c++98 -Wpedantic $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = easyfind
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
INC = easyfind.hpp

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
