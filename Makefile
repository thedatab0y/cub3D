NAME		= cub3d

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -lX11 -lXext
RM			= rm -rf

INCLUDES	= -I /usr/local/include
LIBFT		= -L libft -lft -L
LIBMLX		= -L /usr/local/lib

MAIN		= cub3d

SRC			= $(addsuffix .c, $(addprefix srcs/main/, $(MAIN)))

OBJ			= $(SRC:c=o)
OBJDIR		= obj_files

MAIN		= cub3d
# PARSER = $(addprefix parser/, parser)

# UTILS = $(addprefix utils/, ft_strlen)

all:		$(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
	@make -sC libft/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLXFLAGS)

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
