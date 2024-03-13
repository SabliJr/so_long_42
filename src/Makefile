NAME = so_long

PRINT_F_DIR = ../libs/libft
LIBFT_DIR = ../libs/libft
GNL_DIR = ../libs/get_next_line

SO_LONG = so_long.c \
			checking_map/check_map.c \
			checking_map/check_map_extension.c \
			checking_map/print_err_msg.c \
			getting_map/get_map.c \
			getting_map/init_map.c \
			getting_map/init_player.c

GNL = ${GNL_DIR}/get_next_line.c \
		${GNL_DIR}/get_next_line_utils.c


SRCS = ${LIBFT_DIR} ${PRINT_F_DIR} ${SO_LONG} ${GNL}

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGES = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGES} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar -rsc $(NAME) $(OBJS)
	make -C ${LIBFT_DIR}
	make -C ${PRINT_F_DIR}


all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re