CXX = c++
WFLAGS = -Wall -Wextra -Werror
CFLAGS = -I. -std=c++98 -Wpedantic $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = serializer
SRCS = main.cpp Serializer.cpp Data.cpp
OBJS = $(SRCS:.cpp=.o)
INC = Serializer.hpp Data.hpp

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
