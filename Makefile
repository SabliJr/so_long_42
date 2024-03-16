NAME = so_long

PRINT_F_DIR = ./libs/ft_printf
LIBFT_DIR = ./libs/libft
GNL_DIR = ./libs/get_next_line
HEADER = ./include

SO_LONG = src/so_long.c \
			src/checking_map/check_map.c \
			src/checking_map/check_map_f2.c \
			src/checking_map/print_err_msg.c \
			src/getting_map/get_map.c \
			src/getting_map/init_map.c \
			src/getting_map/init_player.c \
			src/checking_map/map_check_algo.c \
			src/checking_map/map_utils.c \
			src/events/handle_events.c \
			src/events/moves.c \
			src/graphics/mlx_utils.c \
			src/graphics/render_img.c


GNL = ${GNL_DIR}/get_next_line.c \
		${GNL_DIR}/get_next_line_utils.c

MLX_DIR = ./minilibX
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a
MLXFLAGS = -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

SRCS = ${SO_LONG} ${GNL} 
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGES = -Wall -Wextra -Werror -I${HEADER} -g3

.c.o:
	${CC} ${CFLAGES} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C ${LIBFT_DIR}
	make -C ${PRINT_F_DIR}
	@make -C ${MLX_DIR}
	${CC} ${CFLAGES} ${OBJS} -L${LIBFT_DIR} -lft -L${PRINT_F_DIR} -lftprintf -L${MLX_DIR} -lmlx ${MLX_PATH} $(MLXFLAGS) -o $(NAME) 
	echo $(GREEN) "[OK COMPILED]" $(EOC)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ${LIBFT_DIR}
	make clean -C ${PRINT_F_DIR}
	# make clean -C ${MLX_DIR}
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)

fclean:
	rm -f $(NAME)
	make fclean -C ${LIBFT_DIR}
	make fclean -C ${PRINT_F_DIR}
	# make fclean -C ${MLX_DIR}

re: fclean all

.PHONY: all clean fclean re