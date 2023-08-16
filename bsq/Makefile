CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = bsq
SRCS = main.c bsq.c board_get.c board_info.c utils_allocate.c utils_op.c utils_str.c vector.c run_bsq.c
OBJS = $(SRCS:.c=.o)
INCS = bsq.h vector.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
