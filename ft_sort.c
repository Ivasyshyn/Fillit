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

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

void	solid(int *tab1, int *tab2, int size) // сортування фігур перебором
{
	while (check(tab1, tab2) != 1)
	{
		move_right(tab2);
		if (chec_x_size(tab2) >= size)
		{
			printf("asd\n");
			move_left_figure(tab2, 1);
			move_down(tab2);
		}
		if (chec_y_size(tab2) >= size)
		{
			move_left_figure(tab2, 0);
			// size++;
			move_right(tab1);
			int i = 0;
				while (i < 8)
					printf("%d\n", tab1[i++]);
			// solid(tab1, tab2, size++);
		}
	}
//	return (size);
}

// void	solid(int **tab, int *size) // сортування фігур перебором
// {
// 	while (check(tab[0], tab[1]) != 1)
// 	{
// 		move_right(tab[1]);
// 		if (chec_x_size(tab[1]) >= size)
// 		{
// 			move_left_figure(tab[1], 1);
// 			move_down(tab[1]);
// 		}
// 		else if (chec_y_size(tab[1]) >= size)
// 		{
// 			move_left_figure(tab[1], 0);
// 			move_right(tab[0
// 				])
// 			(*size)++;
// 			// solid(tab1, tab2, size++);
// 		}
// 	}
// //	return (size);
// }

// void	solid(int *tab1, int *tab2, int size) // сортування фігур перебором
// {
// 	while (check(tab1, tab2) != 1)
// 	{
// 		move_right(tab2);
// 		if (chec_x_size(tab2) >= size)
// 		{
// 			move_left_figure(tab2, 1);
// 			move_down(tab2);
// 		}
// 		else if (chec_y_size(tab2) >= size)
// 		{
// 			move_left_figure(tab2, 0);
// 			size++;
// 			// solid(tab1, tab2, size++);
// 		}
// 	}
// //	return (size);
// }