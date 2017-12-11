/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:50:36 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/11 12:50:37 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include "libft.h"

int ft_large_coordinates(int **tab, int figure_count)
{
	int start;
	int index;
	int max;

	start = 0;
	index = 0;
	max = tab[index][start];
	while (index < figure_count)
	{
		while (start < 8)
		{
		if (max < tab[index][start])
			max = tab[index][start];
		start++;
		}
		start = 0;
		index++;
	}
	return (max);
}

// int main (void)
// {
// 	int **tab = (int **)malloc(sizeof(int *) * 2);
// 	tab[0] = (int *)malloc(sizeof(int) * 8);
// 	tab[1] = (int *)malloc(sizeof(int) * 8);

// 	int tab1[8] = {0, 1, 1, 0, 2, 0, 8, 0};
// 	int tab2[8] = {0, 0, 0, 1, 1, 0, 10, 1};

// 	ft_memmove(tab[0], tab1, sizeof(int) * 8);
// 	ft_memmove(tab[1], tab2, sizeof(int) * 8);

// 	printf("%d\n", ft_large_coordinates(tab, 2));

// 	free(tab[0]);
// 	free(tab[1]);
// 	free(tab);
// 	return (0);
// }
// int		ft_costil(int **tab, int figure_count)
// {
// 	int tab[8];
// 	int index;

// 	tab = {0, 0, 0, 1, 1, 0, 1, 1};
// 	index = 0;
// 	while (index < figure_count)
// 	{

// 	}
// 	return (0);
// }











// int		check(int **tab, int index)
// {
// 	int first;
// 	int last;
// 	int row;

// 	row = index - 1;
// 	while (row >= 0)
// 	{
// 		first = 0;
// 		while (first <= 6)
// 		{
// 			last = 0;
// 			while (last <= 6)
// 			{
// 				if (tab[row][first] == tab[index][last] && tab[row][first + 1] == tab[index][last + 1])
// 				return (0);
// 				last = last + 2;
// 			}
// 			first = first + 2;
// 		}
// 		row--;
// 	}
// 	return (1);
// }