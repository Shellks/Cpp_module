# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 15:26:08 by acarlott          #+#    #+#              #
#    Updated: 2023/11/09 12:54:04 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CC = c++

HEADER = ./include

SRCS =	core/Main.cpp \
		core/Contact.cpp \
		core/PhoneBook.cpp \

OBJS = ${SRCS:.cpp=.o}

./core/%.o:	./core/%.cpp ${HEADER}/Contact.hpp ${HEADER}/PhoneBook.hpp
	${CC} ${CFLAGS} -I${HEADER} -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34mCreate: \033[1;33mPhoneBook"
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
