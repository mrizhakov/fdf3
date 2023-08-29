# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 18:02:05 by mrizakov          #+#    #+#              #
#    Updated: 2023/08/08 18:02:05 by mrizakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



LIBMLX = MLX42/build/libmlx42.a
MLXFLAGS = -L/path/to/glfw/library -lglfw -lm
CFLAGS = -Wall -Werror -Wextra -g3

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SRC= main.c fdf_utils.c fdf_utils2.c fdf_utils3.c draw.c draw2.c

all:name
	cc $(CFLAGS) $(SRC) $(LIBFT) $(LIBMLX) $(MLXFLAGS) -o fdf
	
name:
	make -C $(LIBFT_PATH) all
	
clean:
	make -C $(LIBFT_PATH) fclean

fclean:clean
	@rm fdf

re: fclean all


