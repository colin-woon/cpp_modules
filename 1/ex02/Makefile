.PHONY = all re clean fclean

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = brain
SRCS = main.cpp
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
