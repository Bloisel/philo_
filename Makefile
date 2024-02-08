# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 18:33:37 by bloisel           #+#    #+#              #
#    Updated: 2023/10/20 17:23:15 by bloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Werror -Wextra 

CC = gcc

INCS = srcs/

SRCS = srcs/main.c \
			srcs/init_philo.c \
			srcs/init_struct.c \
			srcs/routine.c \
			srcs/free.c \
			srcs/parsing.c \
			srcs/init_thread.c \
			srcs/utils.c 

OBJS = $(SRCS:.c=.o)

.c.o :
	@echo "${_BOLD}${_BLUE}to > .o :${_YELLOW} ${<:.c=.o} ${_END}"
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all: $(NAME)

${NAME} : $(OBJS)
	@echo "${_BOLD}${_BLUE}Depacement des *.a to ./${_END}"
	@echo "${_BOLD}${_GREEN}Done${_END}"
	@echo "${_BOLD}${_BLUE}Comilation ...${_END}"
	@${CC} ${FLAGS} ${OBJS} -o ${NAME}
	@echo "${_BOLD}${_GREEN}Done 🙈${_END}"

clean:
	@echo "${_BOLD}${_BLUE}rm *.o${_END}"
	@rm -rf *.o
	@echo "${_BOLD}${_GREEN}Done${_END}"

fclean:clean
	@echo "${_BOLD}${_BLUE} rm de : ${_YELLOW} $(OBJS) $(NAME) ${_END}"
	@rm -rf $(OBJS) $(NAME)
	@echo "${_BOLD}${_GREEN}Done${_END}"

fclean_all:clean
	rm -rf $(OBJS) $(NAME)

re: fclean all

ree: fclean all


# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m
