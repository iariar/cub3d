# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iariss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 18:57:04 by iariss            #+#    #+#              #
#    Updated: 2021/01/21 17:12:40 by iariss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME     = cub3D.a
EXEC    = cub3D
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
LIBFT = libft/libft.a
LIBS     = -lmlx -framework OpenGL -framework AppKit -lm

SRC = tea.c get_next_line.c get_next_line_utils.c table_utils.c parse.c init.c check.c\
    parse2.c player.c ps.c ray.c render.c bmp.c error.c sprite.c projection.c ray2.c ray3.c left.c\
	
OBJ = $(SRC:.c=.o)


all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)

	ar rcs $(NAME) $(OBJ) libft/*.o
	$(CC) $(CFLAGS) $(LIBS) $(SRC) $(NAME) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
