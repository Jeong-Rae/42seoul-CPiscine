CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a

INCDIR = ./includes
SRCDIR = ./srcs
OBJDIR = ./srcs

SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
INCS = $(addprefix $(INCDIR)/, ft.h)

all: $(TARGET)

$(OBJS): $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(TARGET): $(OBJS)
	ar -ruc $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(TARGET)

re:	all fclean

.PHONY:	all clean fclean re
