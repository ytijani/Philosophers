# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 16:43:34 by ytijani           #+#    #+#              #
#    Updated: 2022/06/19 11:09:43 by ytijani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo_bonus

SRC = ft_atoi.c \
	  ft_putstr_fd.c \
	  help2_bonus.c \
	  help3.bonus.c \
	  help4_bonus.c \
	  philo_bonus.c

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