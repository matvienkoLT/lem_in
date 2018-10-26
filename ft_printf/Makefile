#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 13:19:33 by lmatvien          #+#    #+#              #
#    Updated: 2018/09/14 10:55:48 by lmatvien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS  += -Wall -Werror -Wextra
FLAGS  += -I includes/

CFILES = 	ft_afect_flags.c \
			ft_afect_flags_psecond.c \
			ft_afect_flags_pthird.c \
			ft_affect_specifier.c \
			ft_affect_specifier_ptwo.c \
			ft_allocate_memory.c \
			ft_cmp_size.c \
			ft_atoi.c \
			ft_cmpspecifier.c \
			ft_define_flags.c \
			ft_define_flags_psecond.c \
			ft_destroyer_obj.c \
			ft_ftoa.c \
			ft_ftoa_tools.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lltoa.c \
			ft_primary_setting.c \
			ft_memset.c  \
			ft_printf.c \
			ft_strcat.c \
			ft_strcmp.c \
			ft_strlen.c \
			ft_strncpy.c \
			ft_strnew.c \
			ft_summarize.c \
			ft_type_converter.c \
			ft_type_converter_pfour.c \
			ft_type_converter_psecond.c \
			ft_type_converter_pthird.c \
			ft_type_converter_pfive.c \
			ft_type_converter_psix.c \
			ft_ulltoa_base.c \
			ft_vfprintf.c \
			ft_wcstrlen.c \
			ft_color.c \
			ft_color_p2.c \
			ft_colorcmp.c \
			ft_stylesheet.c \
			ft_color_background.c \

FT_PRINTFSRC = $(addprefix src/, $(CFILES))
OBJ = $(FT_PRINTFSRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(FLAGS) $< -o $@ -O3

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
clean:
	 @/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all