/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 21:43:40 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/29 21:43:41 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

int		check(int **tab, int index);
void	move_right(int *tab);
void	move_down(int *tab);
void	solid(int **tab, int *map_size, int figure_count);
int 	ft_map_size(int nb);
void	map_creator(char ***src, int nb);
int		chec_x_size(int *tab);
int		chec_y_size(int *tab);
void 	move_only_left_figure(int *tab, int start);
void	move_left_figure(int *tab, int start);
void	ft_move_default_figure(int **tab, int figure_count);
void	taras(int **tab, int figure_count);

typedef	struct			s_tetr
{
	char				**content;
	int					*coordinates;
	int					size;
	char				ltr;
	struct s_tetr		*next;
	struct s_tetr		*prev;
}						t_tetr;

#endif