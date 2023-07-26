NAME = cub3d

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES = -I /usr/local/include
LIBMLX = -L /usr/local/lib

OBJDIR = obj_files

PARSER = $(addprefix parser/, parser)

UTILS = $(addprefix utils/, ft_strlen)

