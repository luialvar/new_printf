# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 16:47:08 by luialvar          #+#    #+#              #
#    Updated: 2024/07/31 12:05:29 by luialvar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del archivo de la biblioteca
NAME = libftprintf.a

# Rutas y archivos de la biblioteca libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente de ft_printf
SRCS = ft_printf.c \
       ft_arg_c.c \
       ft_arg_s.c \
       ft_arg_p.c \
       ft_arg_d_i.c \
       ft_arg_u.c \
       ft_arg_x.c \
       ft_arg_perc.c

# Generar los nombres de los archivos objeto a partir de los archivos fuente
OBJ = $(SRCS:.c=.o)

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Comando para crear la biblioteca
LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(LIB) $(NAME) $(OBJ)
	echo "srcs = $(SRCS)"
	echo "obj = $(OBJ)"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilación de archivos .o
$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
