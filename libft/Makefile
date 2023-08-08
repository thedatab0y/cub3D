# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 20:13:14 by snocita           #+#    #+#              #
#    Updated: 2023/07/22 15:04:17 by snocita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile Libft 

#MACROS

NAME 		=	libft
CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
RM			=	rm -rf
HEADER		=	libft.h
SRCS_DIR	=	src
OBJS_DIR	=	obj
AR			=	ar -rcs

FT_GEN		=	ft_atoi ft_bzero ft_calloc ft_double_strdup \
				ft_itoa ft_skip_space ft_split ft_tolower ft_tolower \
				ft_free_double_arr

FT_IS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
				ft_isspace ft_issep ft_isexactmatch ft_strisnum

FT_MEM		=	ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset

FT_PUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FT_STR		=	ft_strchr ft_strcmp ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr ft_strdel

SRC = $(addsuffix .c, $(addprefix ft_gen/, $(FT_GEN))) \
	  $(addsuffix .c, $(addprefix ft_is/, $(FT_IS))) \
	  $(addsuffix .c, $(addprefix ft_mem/, $(FT_MEM))) \
	  $(addsuffix .c, $(addprefix ft_put/, $(FT_PUT))) \
	  $(addsuffix .c, $(addprefix ft_str/, $(FT_STR))) \

OBJ = $(SRC:c=o)

all: $(NAME)

.c: $(SRCS)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
		@$(AR) libft.a $(OBJ)
		@ranlib libft.a

clean: 
	@$(RM) *.o
	@rm -rf $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) libft.a

re: fclean all
	
.PHONY: all clean fclean re