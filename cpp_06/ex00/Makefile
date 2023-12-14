# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:54:22 by acarlott          #+#    #+#              #
#    Updated: 2023/12/14 15:24:11 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = ConversionScalarTypes

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CC = c++

HEADER_PATH = include/

SRCS_DIR = src/

OBJS_DIR = .objs/

SRCS =	main.cpp \
		ScalarConverter.cpp

OBJS = $(addprefix $(OBJS_DIR), ${SRCS:.cpp=.o})

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp | $(OBJS_DIR)
	${CC} ${CFLAGS} -I ${HEADER_PATH} -MMD -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34mCreate: \033[1;33mConversionScalarTypes"
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
