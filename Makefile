SRCS = ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putnbr_fd.c\
	   ft_unsigned_fd.c\
	   ft_hexanbr_fd.c\
	   ft_pointer.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rc
RM = rm -fr

all: $(NAME) 

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
	@ echo

re: fclean all
