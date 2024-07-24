SRCS = ft_printf.c\
	   ft_putchar_fd.c\
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
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
