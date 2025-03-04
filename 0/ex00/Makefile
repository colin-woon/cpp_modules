#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I. $(FSAN)
FSAN	=	-g3 -fsanitize=address,leak
RM		=	rm -rf

# Dir and file names
NAME	=	megaphone
SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:.cpp=.o)
INC		=	$(wildcard *.hpp)


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
