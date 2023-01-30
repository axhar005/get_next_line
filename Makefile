# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 12:09:25 by oboucher          #+#    #+#              #
#    Updated: 2023/01/30 12:13:03 by oboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = get_next_line.a
SRC =  *.c
OBJS = $(SRC:%.c=%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=21 $(SRC)

clean:
	rm -f *.o
fclean: clean	
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 