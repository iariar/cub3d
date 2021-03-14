# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iariss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 12:19:01 by iariss            #+#    #+#              #
#    Updated: 2020/10/15 18:47:50 by iariss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGUES = -Wall -Werror -Wextra
INCLUDES = libft.h


SRC = ft_isascii.c ft_strlen.c ft_substr.c ft_memmove.c ft_strdup.c	ft_strrchr.c ft_isdigit.c\
	  ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c ft_putchar_fd.c	ft_strlcat.c\
	  ft_atoi.c ft_itoa.c ft_putendl_fd.c	ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memccpy.c\
	  ft_calloc.c ft_putnbr_fd.c  ft_toupper.c ft_memchr.c ft_putstr_fd.c	ft_strmapi.c ft_isalnum.c\
	  ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strnstr.c

OBJ = ft_strlen.o ft_substr.o ft_isascii.o ft_memmove.o ft_strdup.o ft_strrchr.o ft_isdigit.o ft_memset.o\
	  ft_strjoin.o ft_strtrim.o ft_isprint.o ft_putchar_fd.o ft_strlcat.o ft_atoi.o ft_itoa.o\
	  ft_putendl_fd.o ft_strlcpy.o ft_tolower.o ft_bzero.o ft_memccpy.o ft_putnbr_fd.o ft_toupper.o\
	  ft_calloc.o ft_memchr.o ft_putstr_fd.o ft_strmapi.o ft_isalnum.o ft_memcmp.o ft_split.o ft_strncmp.o\
	  ft_isalpha.o ft_memcpy.o ft_strchr.o ft_strnstr.o

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONOB = ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o\
		ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o	

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: all $(BONOB)
	ar rcs $(NAME) $(BONOB)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(BONOB)

fclean: clean
	rm -f $(NAME)

re: fclean all
