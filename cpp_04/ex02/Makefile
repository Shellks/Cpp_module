# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:53:51 by acarlott          #+#    #+#              #
#    Updated: 2023/12/13 13:19:18 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = ABSTRACT_CLASS

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CC = c++

HEADER_PATH = include/

SRCS_DIR = core/

OBJS_DIR = .objs/

SRCS =	main.cpp \
		Dog.cpp \
		Cat.cpp \
		AAnimal.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp \
		Brain.cpp

OBJS = $(addprefix $(OBJS_DIR), ${SRCS:.cpp=.o})

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp | $(OBJS_DIR)
	${CC} ${CFLAGS} -I ${HEADER_PATH} -MMD -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34mCreate: \033[1;33mABSTRACT_CLASS"
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	echo "\033[1;32mSucces !"

clean :
	echo "\033[1;31mClean: \033[1;36mAll *.o"
	rm -rf ${OBJS_DIR}

fclean: clean
	echo "\033[1;31mClean: \033[1;36mexecutable"
	rm -rf ${NAME}

re : fclean all

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

-include $(OBJS:.o=.d)

.SILENT:

.PHONY: all clean fclean re
