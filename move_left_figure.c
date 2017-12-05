/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:37:04 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/04 14:37:17 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
	return (tab);
}

int main(void)
{
	int *example;
	int count = 0;
xx
	int tab[8] = {1, 1, 2, 1, 3, 0, 3, 1};

	example = move_left_figure(tab, 0);
	example = move_left_figure(tab, 1);
	while (count <= 7)
		printf("%d\n", example[count++]);
	return (0);
}
