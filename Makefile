# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhakh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 15:15:42 by rhakh             #+#    #+#              #
#    Updated: 2017/02/28 15:15:51 by rhakh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =   ft_putchar.c \
        check_spec.c \
        check_colour.c \
        check_spec_helper.c \
        ft_atoi.c \
        ft_bzero.c \
        ft_isdigit.c \
        ft_printf.c \
        ft_strdel.c \
        ft_strlen.c \
        ft_strncpy.c \
        ft_strnew.c \
        ft_memcpy.c \
        ft_memset.c \
        ft_strncmp.c \
        get_c_spec.c \
        get_d_spec.c \
        get_o_spec.c \
        get_result.c \
        get_s_spec.c \
        get_ls_spec.c \
        get_p_spec.c \
        get_b_spec.c \
        get_spec.c \
        get_u_spec.c \
        get_x_spec.c \
        new_spec.c \
        numb_to_char.c \
        spec_helper.c \
        str_capitalizer.c \
        strp_functions.c \

SRCDIR = ./srcs/
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
