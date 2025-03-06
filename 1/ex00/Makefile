.PHONY = all clean fclean re
.DELETE_ON_ERROR: $(NAME)

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -I. $(FSAN)
FSAN = -g3 -fsanitize=address,leak
RM = rm -rf

NAME = zombie
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
INC = $(wildcard *.hpp)

all: $(NAME)

# IF BOTH RULES ARE COMBINED, MAKE WILL COMPILE ALL FILES EVERY TIME INSTEAD OF CHANGED ONES
# (HENCE WE SEPERATE THEM, SAVING MEMORY) (COMPILE > LINK)
# Linking rule (focuses on creating final executable)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Compilation rule (automaticaly called by make when OBJS is need)
%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
