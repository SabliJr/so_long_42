LIBC = ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_bzero.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_toupper.c ft_isalnum.c ft_memcmp.c ft_split.c ft_isalpha.c ft_memcpy.c ft_strncmp.c ft_isascii.c ft_memmove.c ft_isdigit.c ft_memset.c ft_striteri.c ft_strrchr.c ft_isprint.c ft_putchar_fd.c

SRCS = ${LIBC}

SRCSALL = ${LIBC}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o}

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar -rcs $(NAME) $(OBJS)

bonus: ${OBJSALL}
	ar -rcs $(NAME) $(OBJSALL)

all: $(NAME)

clean:
	rm -f $(OBJSALL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
