# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 13:19:01 by acarlott          #+#    #+#              #
#    Updated: 2023/09/26 13:16:10 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CFLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34m\nCompiling: \033[1;33m megaphone"
	${CC} ${CFLAGS} megaphone.cpp -o ${NAME}
	echo "\033[1;32mSucces !\n"

clean :
	echo "\033[1;31mDelete executable"
	${RM} ${NAME} 
	echo "\033[1;32mSucces !\n"

fclean:
	echo "\033[1;31mDelete executable"
	${RM} ${NAME}
	echo "\033[1;32mSucces !\n"

re : fclean all

.SILENT:

.PHONY: all clean fclean re
