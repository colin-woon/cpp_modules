CXX = c++
WFLAGS = -Wall -Wextra -Werror
CFLAGS = -I. -std=c++98 -Wpedantic $(WFLAGS) $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = mutantstack
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

LIST_NAME = list
LIST = list.cpp
LIST_OBJS = $(LIST:.cpp=.o)

INC = MutantStack.hpp

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INC)
	$(CXX) $(CFLAGS) -c $< -o $@

list: $(LIST_OBJS)
	$(CXX) $(CFLAGS) $(LIST_OBJS) -o $(LIST_NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIST_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIST_NAME)

re: clean all
