#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 20:11:35 by lmatvien          #+#    #+#              #
#    Updated: 2018/09/24 09:19:54 by lmatvien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= lem-in
NAME1 			= lib_mini.a
MAIN_NAME_LIB	= mlib.a
ODIR = obj
SDIR = src
LDIR = libft_mini

FLAGS  = 	-Wall -Werror -Wextra
CFILES = 	lem_in_ants_nav.c \
			lem_in_con_way.c \
			lem_in_data_analyzing.c \
			lem_in_data_analyzing_p.c \
			lem_in_list_cntr.c \
			lem_in_main.c \
			lem_in_mem_cl.c \
			lem_in_print_way.c \
			lem_in_printer.c \
			lem_in_queue_control.c \
			lem_in_input_list_cntrl.c \
			lem_in_reader.c	\
			lem_in_reader_hlp.c \
			lem_in_chain.c \
			lem_in_usage.c \

LIBFILE =   ft_atoi_base.c \
			ft_itoa.c \
			ft_strnew.c \
			ft_pow.c \
			ft_strchr.c \
			ft_dgt_quntt_i.c \
			ft_isdigit.c  \
			ft_strrchr.c \
			ft_putnbr_fd.c \
			ft_putstr_error.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcmp.c \
			ft_strlen.c \
			ft_strnlen.c \
	 		ft_strdup.c \
			ft_strjoin.c \
			ft_strstr.c \
			ft_memset.c \
			ft_memcpy.c	\
			ft_strncat.c \
			ft_strcat.c \
			get_next_line.c \
			ft_strsplit.c \
			ft_isdigit.c \
			ft_atoi.c \
			ft_swap.c \

MAIN_HEADERS = -I ./libft_mini -I ./includes -I ./ft_printf/includes

_LIB_OBJ		= $(LIBFILE:.c=.o)
_OBJ_MAIN =	$(CFILES:.c=.o)
OBJ_MAIN =	$(addprefix ./obj/, $(_OBJ_MAIN))
LIB_OBJ =	$(addprefix ./obj/, $(_LIB_OBJ))

all: $(NAME)

$(ODIR)/%.o : $(SDIR)/%.c
	@mkdir -p $(ODIR)
	@gcc -c $(FLAGS) $(MAIN_HEADERS) $< -o $@ -O3
$(ODIR)/%.o: $(LDIR)/%.c 
	@gcc -c $(FLAGS) $< -o $@ -O3

$(NAME): $(OBJ_MAIN) $(LIB_OBJ)
	@ar rcs ./obj/$(MAIN_NAME_LIB) $(OBJ_MAIN)
	@ar rcs ./obj/$(NAME1) $(LIB_OBJ)
	@make -C ./ft_printf/
	@gcc -o $(NAME) ./obj/mlib.a ./obj/lib_mini.a ./ft_printf/libftprintf.a -I ./lib_mini -O3
clean:
	@/bin/rm -f $(LIB_OBJ) $(OBJ_MAIN)
	@make clean -C ./ft_printf/
	@echo "\033[35;1m>>>Removed OBJ Files\033[0m"
	
fclean: clean
	@/bin/rm -f ./obj/lib_mini.a ./obj/mlib.a ./lem-in
	@make fclean -C ./ft_printf/
	@echo "\033[35;1m>>>Removed executed files\033[0m"

re: fclean all