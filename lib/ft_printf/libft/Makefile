# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggochita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 19:35:12 by ggochita          #+#    #+#              #
#    Updated: 2023/07/12 16:12:33 by ggochita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strdup.c ft_substr.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c ft_strjoin.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_strlen.c  ft_strrchr.c ft_strtrim.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  \
					ft_memset.c  ft_split.c ft_itoa.c  ft_strmapi.c \
					ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
