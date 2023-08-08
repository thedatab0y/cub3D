NAME		= cub3d

CC			= gcc
MLXFLAG		= -I./minilibx -L./minilibx_mac -lmlx -framework OpenGL -framework AppKit
FLAGS		= -Werror -Wextra -Wall -g
RM			= rm -rf

INCLUDES	= -I /usr/local/include
LIBFT		= -L libft -lft

MINILIBX_PATH	=	./minilibx_mac
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

MAIN		= cub3d
FREE		= free
PARSING		= parsing wall_algo wall_algo_two
ERROR		= error
UTILS		= utils dimentions

SRC			= $(addsuffix .c, $(addprefix srcs/cub3d/, $(MAIN))) \
			$(addsuffix .c, $(addprefix srcs/free/, $(FREE))) \
			$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING))) \
			$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS))) \
			$(addsuffix .c, $(addprefix srcs/error/, $(ERROR)))

OBJ			= $(SRC:c=o)
OBJDIR		= obj_files

all:		$(NAME)

$(NAME):	$(OBJ)
	@make -sC libft/
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@make clean -C libft/
	@rm -rf srcs/cub3d/cub3d.o
	@rm -rf srcs/error/error.o
	@rm -rf srcs/free/free.o
	@rm -rf srcs/parsing/parsing.o
	@rm -rf srcs/parsing/wall_algo.o
	@rm -rf srcs/parsing/wall_algo_two.o
	@rm -rf srcs/utils/dimentions.o
	@rm -rf srcs/utils/utils.o

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@rm -rf cub3d

re:		fclean all
