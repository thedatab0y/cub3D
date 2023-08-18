# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 13:39:58 by busmanov          #+#    #+#              #
#    Updated: 2023/08/17 17:32:48 by busmanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

SRS		=	ft_atoi.c ft_itocs.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_strncmp.c ft_strlen.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strnstr.c \
				ft_itoa.c ft_toupper.c ft_tolower.c ft_substr.c ft_strrchr.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_strtrim.c \
				ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
				ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strcmp.c

SRSB	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBFILES	=		$(SRSB:.c=.o)

OFILES	=		$(SRS:.c=.o)

all:	$(NAME)

$(NAME):	$(OFILES)
	ar rcs $(NAME) $(OFILES)
	ranlib $(NAME)

$(OFILES):	$(SRS)
	$(CC) $(CFLAGS) -c $(SRS)

bonus:	$(OBFILES)
$(OBFILES):	$(SRSB)
	$(CC) -c $(CFLAGS) $(SRSB)
	ar rcs $(NAME) $(OBFILES)
	ranlib $(NAME)

clean:
		$(RM) $(OFILES) $(OBFILES)

fclean:	clean
		$(RM) $(NAME)

re:	clean all

.PHONY:	clean fclean all re bonus