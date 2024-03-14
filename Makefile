NAME = so_long

PRINT_F_DIR = ./libs/ft_printf
LIBFT_DIR = ./libs/libft
GNL_DIR = ./libs/get_next_line
HEADER = ./include

SO_LONG = src/so_long.c \
			src/checking_map/check_map.c \
			src/checking_map/check_map_extension.c \
			src/checking_map/print_err_msg.c \
			src/getting_map/get_map.c \
			src/getting_map/init_map.c \
			src/getting_map/init_player.c

GNL = ${GNL_DIR}/get_next_line.c \
		${GNL_DIR}/get_next_line_utils.c


SRCS = ${SO_LONG} ${GNL} 

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGES = -Wall -Wextra -Werror -I${HEADER} -g3

.c.o:
	${CC} ${CFLAGES} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C ${LIBFT_DIR}
	make -C ${PRINT_F_DIR}
	${CC} ${CFLAGES} ${OBJS} -o $(NAME) -L${LIBFT_DIR} -lft -L${PRINT_F_DIR} -lftprintf


all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ${LIBFT_DIR}
	make clean -C ${PRINT_F_DIR}

fclean:
	rm -f $(NAME)
	make fclean -C ${LIBFT_DIR}
	make fclean -C ${PRINT_F_DIR}

re: fclean all

.PHONY: all clean fclean re