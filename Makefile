# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmieshko <kmieshko@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 17:29:00 by dfedorov          #+#    #+#              #
#    Updated: 2018/02/25 17:09:30 by dfedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_atoi.c\
ft_bzero.c\
ft_conver_to_bin.c\
ft_count_size_uni.c\
ft_create_structs.c\
ft_fill_res.c\
ft_fill_res_norm1.c\
ft_fill_res_norm2.c\
ft_fill_res_wchar.c\
ft_fill_res_digit.c\
ft_fill_res_wstr.c\
ft_fill_struc.c\
ft_itoa_max.c\
ft_join.c\
ft_needle_flag_width.c\
ft_prec_size.c\
ft_print_result.c\
ft_print_wchar.c\
ft_print_wstr.c\
ft_printf.c\
ft_read_struc.c\
ft_recursive_power.c\
ft_spec.c\
ft_strcat.c\
ft_strchr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strlen.c\
ft_strnew.c\
ft_strsub.c\
ft_type.c\
ft_free_res.c\

%.o : %.c
	$(COMPILE) $(FLAGS) -o $@ $<

OBJ = $(SRCS:.c=.o)

RM = rm -f

COMPILE = gcc -c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
