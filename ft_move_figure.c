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

int *move_left_figure(int *tab, int start) // позиціонує фігуру у верхній лівий 
{											//куток
	int y;
	int yx;
	int min;

	y = start + 6;
	yx = start;
	min = tab[y];
	while(yx <= y)
	{
		if (min > tab[yx])
			min = tab[yx];
		yx = yx + 2;
	}
	yx = start;
	while(yx <= y)
	{
	tab[yx] = tab[yx] - min;
	yx = yx + 2;
	}
	if (start < 1) 
		move_left_figure(tab, 1);
	return (tab);
}

void	move_right(int *tab) // перемещує праворуч по осі х
{
	int x = 1;

	while (x <= 7)
	{
		tab[x] = tab[x] + 1;
		x = x + 2;
	}
}

void	move_down(int *tab) // переміщує вниз по осі y
{
	int y = 0;

	while (y <= 6)
	{
		tab[y] = tab[y] + 1;
		y = y + 2;
	}
}

int	chec_x_size(int *tab) // перевіряє розмір квадрата по х
{
	int x;
	int yx;
	int max;

	x = 7;
	yx = 1;
	max = tab[x];
	while(yx <= x)
	{
		if (max < tab[yx])
			max = tab[yx];
		yx = yx + 2;
	}
	return (max);
}

int	chec_y_size(int *tab) // перевіряє розмір квадрата по Y 
{
	int y;
	int yx;
	int max;

	y = 6;
	yx = 0;
	max = tab[y];
	while(yx <= y)
	{
		if (max < tab[yx])
			max = tab[yx];
		yx = yx + 2;
	}
	return (max);
}

int		check(int *tab1, int *tab2) // перевіряє співпадіння координат порівняно
{								// з іншими координатами
	int first;
	int last;

	first = 0;
	while (first <= 6)
	{
		last = 0;
		while (last <= 6)
		{
			if (tab1[first] == tab2[last] && tab1[first + 1] == tab2[last + 1])
				return (0);
			last = last + 2;
		}
		first = first + 2;
	}
	return (1);
}
