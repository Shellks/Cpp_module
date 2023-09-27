# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 11:03:32 by acarlott          #+#    #+#              #
#    Updated: 2023/09/27 11:31:28 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CC = c++

HEADER = ./include

SRCS =	core/main.cpp \
		core/Zombie.cpp \
		core/newZombie.cpp \
		core/randomChump.cpp \

OBJS = ${SRCS:.cpp=.o}

./core/%.o:	./core/%.cpp Makefile ${HEADER}/Zombie.hpp
	${CC} ${CFLAGS} -I${HEADER} -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34mCreate: \033[1;33mBraiiiiiiinnnzzzZ"
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	echo "\033[1;32mSucces !"

clean :
	echo "\033[1;31mClean: \033[1;36mAll *.o"
	rm -rf ${OBJS}

fclean: clean
	echo "\033[1;31mClean: \033[1;36mexecutable"
	rm -rf ${NAME}

re : fclean all

.SILENT:

.PHONY: all clean fclean re
