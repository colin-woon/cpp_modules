CC = c++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98 -Wpedantic -Wshadow $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = claptrap
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
INC = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
