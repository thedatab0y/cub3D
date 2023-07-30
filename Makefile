NAME		= cub3d

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
# MLXFLAGS	= -lX11 -lXext
RM			= rm -rf

INCLUDES	= -I /usr/local/include
LIBFT		= -L libft -lft
# LIBMLX		= -L /usr/local/lib

MINILIBX_PATH	=	./minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

MAIN		= cub3d
FREE		= free
PARSING		= parsing
ERROR		= error

SRC			= $(addsuffix .c, $(addprefix srcs/main/, $(MAIN))) \
			$(addsuffix .c, $(addprefix srcs/free/, $(FREE))) \
			$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING))) \
			$(addsuffix .c, $(addprefix srcs/error/, $(ERROR)))

OBJ			= $(SRC:c=o)
OBJDIR		= obj_files

MAIN		= cub3d
# PARSER = $(addprefix parser/, parser)

# UTILS = $(addprefix utils/, ft_strlen)

all:		$(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
	@make -sC libft/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX) $(MLXFLAGS)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@make clean -C libft/
	@rm -f obj/$(OBJ)

fclean:
	@make fclean -C libft/
	@rm -f obj/*.o
	@rm -rf obj/
	@rm srcs/main/*.o
	@rm -f $(NAME)
	@rm -rf cub3d

re:		fclean all
