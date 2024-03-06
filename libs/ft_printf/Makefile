SRCS = ft_printf.c ft_putnbr_unsigned.c ft_putptr.c ft_utilities.c ft_puthex.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGES = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGES} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar -rsc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
