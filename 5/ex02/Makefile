CC = c++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98 -Wpedantic $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = bureaucrat
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)
INC = Bureaucrat.hpp Form.hpp

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
