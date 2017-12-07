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

int		check(int *tab1, int *tab2);
int		check_square(int *tab, int size);
void	move_right(int *tab);
void	move_down(int *tab);
 void	solid(int *tab1, int *tab2, int size);
// void	solid(int **tab1, int size);
int 	ft_map_size(int nb);
char	**map_creator(int nb);
int		chec_x_size(int *tab);
int		chec_y_size(int *tab);
void 	move_only_left_figure(int *tab, int start);
int		*move_left_figure(int *tab, int start);


typedef	struct			s_tetr
{
	char				**content;
	int					*coordinates;
	int					size;
	char				ltr;
	struct s_tetr		*next;
	struct s_tetr		*prev;
}						t_tetriminos;

#endif