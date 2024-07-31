# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 16:47:08 by luialvar          #+#    #+#              #
#    Updated: 2024/07/31 13:44:12 by luialvar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del archivo que se generará
NAME = libftprintf.a

# Rutas y archivos necesarios
LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a

# Compilador y banderas de compilación
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Comando para eliminar archivos
REMOVE = rm -f

# Incluir directorios
INCLUDE = -I ./libft

# Directorio y archivos fuente 
SRCS_PATH = ./printf
SRCS = $(SRCS_PATH)/ft_printf.c \
       $(SRCS_PATH)/ft_arg_c.c \
       $(SRCS_PATH)/ft_arg_s.c \
       $(SRCS_PATH)/ft_arg_p.c \
       $(SRCS_PATH)/ft_arg_d_i.c \
       $(SRCS_PATH)/ft_arg_u.c \
       $(SRCS_PATH)/ft_arg_x.c \
       $(SRCS_PATH)/ft_arg_perc.c

# Archivos objeto generados a partir de los archivos fuente
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(NAME)

# Regla para crear el archivo de biblioteca
$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(NAME) $(OBJS)

# Regla para compilar libft y copiar el archivo libft.a
$(LIBFT):
	make -C $(LIB_PATH)
	cp $(LIBFT) $(NAME)

# Regla para compilar los archivos objeto
.c.o:
	$(CC) -c $(CFLAGS) $< -o ${<:.c=.o} $(INCLUDE)

# Limpiar los archivos objeto
clean:
	make clean -C $(LIB_PATH)
	$(REMOVE) $(OBJS)

# Limpiar todos los archivos generados
fclean:
	make fclean -C $(LIB_PATH)
	$(REMOVE) $(OBJS)
	$(REMOVE) $(NAME)

# Regenerar todo
re: fclean all

# Norminette
norm:
	norminette

.PHONY: re all clean fclean norm
