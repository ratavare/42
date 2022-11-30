# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 13:29:27 by ratavare          #+#    #+#              #
#    Updated: 2022/11/30 14:51:22 by ratavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a
LIBFT	=		./libft/libft.a	

CC		=		cc

CFLAGS	=		-Wall -Wextra -Werror

RM		=		rm -f

SRC 	=		srcs/ft_printf.c srcs/ft_printf_utils.c 

#BONUS	=		

OBJ		=		$(SRC:.c=.o)

#BOBJ	=		$(BONUS:.c=.o)

all:			$(NAME)

#bonus:			$(BOBJ)
#		ar rcs	$(NAME) $(BOBJ)

$(NAME):		$(OBJ) $(LIBFT)
		ar rcs	$(NAME) $(OBJ)

$(LIBFT):
				make -C ./libft
				cp ./libft/libft.a $(NAME)


clean:			
				make clean -C ./libft
				$(RM) $(OBJ) $(BOBJ)

fclean: clean
				make fclean -C ./libft
				$(RM) $(NAME)

re:		fclean	$(NAME)