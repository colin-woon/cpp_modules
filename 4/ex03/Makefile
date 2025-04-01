CC = c++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98 -Wpedantic $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = materia
SRCS = main.cpp AMateria.cpp
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
