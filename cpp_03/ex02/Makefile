# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 18:19:12 by acarlott          #+#    #+#              #
#    Updated: 2023/12/01 13:34:56 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Assembly_line_work

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CC = c++

HEADER_PATH = include/

SRCS_DIR = core/

OBJS_DIR = .objs/

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

OBJS = $(addprefix $(OBJS_DIR), ${SRCS:.cpp=.o})

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp | $(OBJS_DIR)
	${CC} ${CFLAGS} -I ${HEADER_PATH} -MMD -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJS}
	echo "\033[1;34mCreate: \033[1;33mAssembly_line_work"
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
