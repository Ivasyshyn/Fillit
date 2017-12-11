/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:12:29 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/05 17:12:31 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_shift(int **tab, int in, int *map_size) // рухає фігури
{
	if (chec_x_size(tab[in]) < *map_size - 1)
		move_right(tab[in]);
	else if (chec_x_size(tab[in]) >= *map_size - 1)
	{
		move_left_figure(tab[in], 1);
		if (chec_y_size(tab[in]) < *map_size - 1)
			move_down(tab[in]);
		else
		{
			move_left_figure(tab[in], 0);
			return (0);
		}
	}
	return (1);
}

void	solid(int **tab, int *map_size, int figure_count) // сортування фігур перебором
{
	int in;
	int c;
	int j;

	in = 0;
	while (in < figure_count)
	{
		c = 1;	
		j = check(tab, in);
		if (j)
			in++;
		if (!j && in > 0)
			c = ft_shift(tab, in, map_size);;
		while (c == 0 && in > 0)
		{
			in--;
			c = ft_shift(tab, in, map_size);
		}
		if (in == 0 && c == 0)
		{
			(*map_size)++;
			ft_move_default_figure(tab, figure_count);
		}
	}
}
