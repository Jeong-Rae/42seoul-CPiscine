CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = rush-02
SRCS = main.c dict_input.c dict_malloc_input.c out_putstr_f.c out_trans.c util_ft_atoi_atoc.c util_ft_split.c util_ft_strjoin.c list_init.c list_main.c
OBJS = $(SRCS:.c=.o)
INCS = rush_dict.h rush_list.h rush_out.h

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY: fclean clean all re
