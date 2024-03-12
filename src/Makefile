PRINT_F = ../libs/ft_printf/ft_printf.c \
			../libs/ft_printf/ft_putnbr_unsigned.c \
			../libs/ft_printf/ft_putptr.c \
			../libs/ft_printf/ft_utilities.c \
			../libs/ft_printf/ft_puthex.c

SO_LONG = so_long.c

LIBC = ../libs/libft/ft_atoi.c \
		../libs/libft/ft_itoa.c \
		../libs/libft/ft_putendl_fd.c \
		../libs/libft/ft_strlcat.c \
		../libs/libft/ft_substr.c \
		../libs/libft/ft_bzero.c \
		../libs/libft/ft_putnbr_fd.c \
		../libs/libft/ft_strlcpy.c \
		../libs/libft/ft_tolower.c \
		../libs/libft/ft_calloc.c \
		../libs/libft/ft_memchr.c \
		../libs/libft/ft_putstr_fd.c \
		../libs/libft/ft_strlen.c \
		../libs/libft/ft_toupper.c \
		../libs/libft/ft_isalnum.c \
		../libs/libft/ft_memcmp.c \
		../libs/libft/ft_split.c \
		../libs/libft/ft_strmapi.c \
		../libs/libft/ft_isalpha.c \
		../libs/libft/ft_memcpy.c \
		../libs/libft/ft_strncmp.c \
		../libs/libft/ft_isascii.c \
		../libs/libft/ft_memmove.c \
		../libs/libft/ft_strdup.c \
		../libs/libft/ft_strnstr.c \
		../libs/libft/ft_isdigit.c \
		../libs/libft/ft_memset.c \
		../libs/libft/ft_striteri.c \
		../libs/libft/ft_strrchr.c \
		../libs/libft/ft_isprint.c \
		../libs/libft/ft_putchar_fd.c \
		../libs/libft/ft_strtrim.c

BONUS = ../libs/libft/ft_lstadd_front_bonus.c \
		../libs/libft/ft_lstclear_bonus.c \
		../libs/libft/ft_lstiter_bonus.c \
		../libs/libft/ft_lstlast_bonus.c \
		../libs/libft/ft_lstdelone_bonus.c \
		../libs/libft/ft_lstsize_bonus.c \
		../libs/libft/ft_lstadd_back_bonus.c \
		../libs/libft/ft_lstnew_bonus.c \
		../libs/libft/ft_lstmap_bonus.c

SRCS = ${LIBC} ${PRINT_F} ${SO_LONG} ${BONUS}

OBJS = ${SRCS:.c=.o}
NAME = libsolong.a

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