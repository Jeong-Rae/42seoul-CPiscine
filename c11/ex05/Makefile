CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = do-op
SRCS = main.c ft_calc.c ft_ops.c ft_utils.c
OBJS = $(SRCS:.c=.o)
INCS = do_op.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
