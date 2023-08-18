NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -L./libs/minilibx_mac -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

MLX_DIR = ./libs/minilibx_mac
MLXLIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = ./libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = cub3d.c init.c parsing/free/free.c move.c run.c run_util.c raycast.c\
		parsing/parsing/parsing.c preset.c parsing/parsing/wall_algo_two.c parsing/parsing/parse_color.c utils.c
SRCS := $(addprefix srcs/, $(SRCS))

GNL_SRCS	= gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I ./ $(OBJS) $(LIBFT) $(MLXFLAG) -o $@

clean :
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re
