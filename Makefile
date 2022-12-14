CFLAGS  = -Werror -Wextra -Wall
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:c=o)

all : $(NAME)

$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean :
	rm -f *.o
fclean : clean
	rm -f libftprintf.a
re : fclean all

.PHONY : clean fclean re all