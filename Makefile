NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include

SRC =	src/main.c \
		src/utils.c \
		src/init_map.c \
		src/cleans_close.c \
		src/parse_map.c \
		src/render.c \
		src/move_player.c \
		src/flood_fill.c \
		src/sprites.c

OBJS = ${SRC:.c=.o}

LIBFT_DIR = lib/libft
MLX_DIR = lib/minilibx-linux
LIBFT = -L ${LIBFT_DIR} -lft
MLX	= -L ${MLX_DIR} -lmlx -Ilmlx -lXext -lX11 -lm

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

all:	${NAME}

clean:
		make -C ${LIBFT_DIR} clean
		make -C ${MLX_DIR} clean
		rm -f ${OBJS}

fclean: clean
		make -C ${LIBFT_DIR} fclean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
