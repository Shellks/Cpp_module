# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:53:51 by acarlott          #+#    #+#              #
#    Updated: 2023/11/22 16:18:57 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = I_DONT_WANT_TO_BURN_THE_WORLD

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CC = c++

HEADER_PATH = ./include/
HEADER_FILES = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
HEADERS = $(addprefix $(HEADER_PATH), $(HEADER_FILES))

SRCS =	core/main.cpp \
		core/Dog.cpp \
		core/Cat.cpp \
		core/Animal.cpp \
		core/WrongCat.cpp \
		core/WrongAnimal.cpp \
		core/Brain.cpp

OBJS = ${SRCS:.cpp=.o}

./core/%.o:	./core/%.cpp ${HEADERS}
	${CC} ${CFLAGS} -I${HEADER_PATH} -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34mCreate: \033[1;33mI_DONT_WANT_TO_BURN_THE_WORLD"
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
