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
CFILES = fillit.c fillit_help.c ft_audit.c ft_mapcalc.c ft_move_figure.c ft_sort.c ft_costil.c

OFILES = $(CFILES:.c=.o)
FOLDER = libft

all: $(NAME)

%.o: %.c
		@gcc -c $? $(FILES) -Wall -Wextra -Werror

$(NAME): $(OFILES)
		make -C $(FOLDER)
		@gcc -Wall -Wextra -Werror $(OFILES) -L $(FOLDER) -lft -o $(NAME)

clean:
	@/bin/rm -f $(OFILES)
	make clean -C $(FOLDER)

fclean: clean
	@/bin/rm -f $(NAME)
	make fclean -C $(FOLDER)

re: fclean all

.PHONY: all clean fclean