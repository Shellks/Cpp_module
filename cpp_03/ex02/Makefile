# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 18:19:12 by acarlott          #+#    #+#              #
#    Updated: 2023/10/06 15:07:14 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Assembly_line_work

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CC = c++

HEADER_PATH = ./include/
HEADER_FILES = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
HEADERS = $(addprefix $(HEADER_PATH), $(HEADER_FILES))

SRCS =	core/main.cpp \
		core/ClapTrap.cpp \
		core/ScavTrap.cpp \
		core/FragTrap.cpp \

OBJS = ${SRCS:.cpp=.o}

./core/%.o:	./core/%.cpp ${HEADERS}
	${CC} ${CFLAGS} -I${HEADER_PATH} -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34mCreate: \033[1;33mAssembly_line_work"
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