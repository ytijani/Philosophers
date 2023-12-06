# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 09:28:16 by ytijani           #+#    #+#              #
#    Updated: 2022/06/23 17:33:26 by ytijani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRC = ft_atoi.c \
	  ft_putstr_fd.c \
	  help1.c \
	  help2.c \
	  help_myfun.c \
	  philo.c

CC = cc

CFLAGS = -Wall -Werror -Wextra
OBJCT = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJCT)
	@$(CC) $(CFLAGS) $(OBJCT) -o $(NAME)
clean :
	@rm -f $(OBJCT)
fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re bonus
