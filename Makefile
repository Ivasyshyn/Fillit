#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 12:26:10 by tlutsyk           #+#    #+#              #
#    Updated: 2017/10/27 12:26:11 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
CFILES = fillit.c ft_audit.c ft_mapcalc.c ft_move_figure.c ft_sort.c ft_costil.c

OFILES = $(CFILES:.c=.o)


all: $(NAME)

%.o: %.c
		@gcc -c $? $(FILES) -Wall -Wextra -Werror

$(NAME): $(OFILES)
		@gcc -Wall -Wextra -Werror $(OFILES) libft.a -o $(NAME)	

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean