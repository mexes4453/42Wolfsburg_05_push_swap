# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:08:09 by cudoh             #+#    #+#              #
#    Updated: 2022/08/04 21:07:15 by cudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRCS:= $(shell ls *.c | grep -v lst | xargs)
SRCS:= main.c stack_ops_utils.c \
		custom_srt_a_utils.c custom_srt_b_utils.c custom_srt_c_utils.c \
		custom_srt_d_utils.c custom_srt_e_utils.c custom_srt_f_utils.c \
		custom_srt_g_utils.c \
		quick_srt_a_utils.c quick_srt_b_utils.c quick_srt_c_utils.c \
		quick_srt_d_utils.c quick_srt_e_utils.c quick_srt_f_utils.c \
		quick_srt_g_utils.c \
		err_chk_a_utils.c err_chk_b_utils.c err_chk_c_utils.c

#OBJS_BONUS:=$(SRCS_BONUS:.c=.o)
OBJS:=$(SRCS:.c=.o)

NAME = push_swap
USR_LIB = libft.a
USR_LIB_PATH = ./libft

CC = cc
#CFLAGS = -Werror -Wall -Wextra -g -fsanitize=address
CFLAGS = -Werror -Wall -Wextra -g
LIBFLAGS_STATIC = -L$(USR_LIB_PATH) -lft 
INCLUDES = -I./ -I$(USR_LIB_PATH)

NAME : all
all : $(NAME)
$(NAME) : $(OBJS) $(USR_LIB)
	$(CC) $^ $(CFLAGS) $(INCLUDES) -o $@
#	$(CC) $^ $(CFLAGS) $(INCLUDES) $(LIBFLAGS_STATIC) -o $@

	
# obj files output
%.o : %.c
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -o $@


$(USR_LIB) :
	@echo
#	$(AR) $(LIBFLAGS_STATIC) $@ $^						# create the library file for linking
	cd ./libft; make; make bonus; cp libft.a ../; cd ..	
#	@echo												# print new line on screen


# remove all object files
fclean:
	rm -rf $(OBJS)
	cd ./libft; make fclean; cd ..;

# remove final target files
clean: fclean
	rm -rf $(NAME)
	rm -rf *.a
	cd ./libft; make clean; cd ..;

# recompile everything
re: clean all

.PHONY : all fclean clean re 
