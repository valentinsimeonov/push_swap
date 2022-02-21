NAME_S = push_swap

SRCS_S = push_swap.c checkers.c indexing.c operations.c utils.c sort_few.c


OBJS_S = $(SRCS_S:.c=.o)


CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME_S)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME_S): $(OBJS_S) 
	$(CC) $(CFLAGS) -o $@ $(OBJS_S)


clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME_S)

re: fclean all

.PHONY: all bonus clean fclean re
