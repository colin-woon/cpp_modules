CC = c++
CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++98 -I. $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = a.out
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(SRCS:.cpp=.o)
INC = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
