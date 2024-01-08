SRCS = ft_putchar_fd.c	ft_putstr_fd.c	ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)
MAIN = ft_printf.c
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm

all: $(NAME) prog
	@echo "-- Running Program... --"
	./a.exe

prog:
	@ echo "-- Compilling Program... --"
	$(CC) $(CFLAGS) $(MAIN) $(NAME)
	@ echo

$(NAME): $(OBJS)
	@ echo "-- Compilling Library... --"
	$(AR) $(NAME) $(OBJS)
	@ echo

clean:
	@ echo "-- Removing *.o files --"
	$(RM) $(OBJS)
	@ echo

fclean: clean
	@ echo "-- Removing *.a files --"
	$(RM) $(NAME)
	$(RM) a
	@ echo

re: fclean all
