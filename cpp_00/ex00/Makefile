# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 13:19:01 by acarlott          #+#    #+#              #
#    Updated: 2023/11/09 12:51:58 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CFLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34mCompiling: \033[1;33m megaphone"
	${CC} ${CFLAGS} megaphone.cpp -o ${NAME}
	echo "\033[1;32mSucces !"

clean :
	echo "\033[1;31mDelete objs"
	${RM} ${OBJS} 
	echo "\033[1;32mSucces !"

fclean: clean
	echo "\033[1;31mDelete executable"
	${RM} ${NAME}
	echo "\033[1;32mSucces !"

re : fclean all

.SILENT:

.PHONY: all clean fclean re
