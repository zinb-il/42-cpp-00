SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = megaphone

$(NAME) :
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

all : $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re