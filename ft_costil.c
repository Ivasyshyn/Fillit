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

int	ft_costil(int **tab, int figure_count)
{
	int *costil;
	int index;
	int start;

	index = 0;
	if (!(costil = (int*)malloc(sizeof(int) * 8)))
		return (0);
	ft_memset(costil, 0, sizeof(int) * 8);
	costil[3] = 1;
	costil[4] = 1;
	costil[6] = 1;
	costil[7] = 1;
	while (index < figure_count)
	{
		while (start < 8)
		{
			if (tab[index][start] != costil[start])
				return (0);
			start++;
		}
		start = 0;
		index++;
	}
	free(costil);
	return (1);
}

int	ft_sqrt(int nb)
{
	int in;
	int res;

	in = 0;
	res = 0;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (res <= nb)
	{
		res = in * in;
		if (res == nb)
			return (in);
		in++;
	}
	return (0);
}
