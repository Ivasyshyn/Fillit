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

int	ft_large_coordinates(int **tab, int figure_count)
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
