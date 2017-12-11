/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:02:01 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/07 16:02:01 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_left_figure(int *tab, int start)
{
	int y;
	int yx;
	int min;

	y = start + 6;
	yx = start;
	min = tab[y];
	while (yx <= y)
	{
		if (min > tab[yx])
			min = tab[yx];
		yx = yx + 2;
	}
	yx = start;
	while (yx <= y)
	{
		tab[yx] = tab[yx] - min;
		yx = yx + 2;
	}
	if (start < 1)
		move_left_figure(tab, 1);
}

void	move_right(int *tab)
{
	int x;

	x = 1;
	while (x <= 7)
	{
		tab[x] = tab[x] + 1;
		x = x + 2;
	}
}

void	move_down(int *tab)
{
	int y;

	y = 0;
	while (y <= 6)
	{
		tab[y] = tab[y] + 1;
		y = y + 2;
	}
}

int		chec_x_size(int *tab)
{
	int x;
	int yx;
	int max;

	x = 7;
	yx = 1;
	max = tab[x];
	while (yx <= x)
	{
		if (max < tab[yx])
			max = tab[yx];
		yx = yx + 2;
	}
	return (max);
}

int		chec_y_size(int *tab)
{
	int y;
	int yx;
	int max;

	y = 6;
	yx = 0;
	max = tab[y];
	while (yx <= y)
	{
		if (max < tab[yx])
			max = tab[yx];
		yx = yx + 2;
	}
	return (max);
}
