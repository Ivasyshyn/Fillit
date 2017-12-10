/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:06:15 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/10 20:28:55 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_map_size(int nb) /* вираховує розмір фігури */
{
	int res;
	int tmp;

	tmp = nb * 4;
	while ((res = ft_sqrt(tmp)) == 0)
		tmp++;
	return (res);
}

void	map_creator(char ***src, int nb) /* створює карту */
{
	int index;

	index = 0;
	(*src) = (char **)malloc(sizeof(char *) * (nb + 1));
	while (index < nb)
	{
		(*src)[index] = ft_strnew(nb);
		ft_memset((*src)[index], '.', nb);
		index++;
	}
	(*src)[index] = NULL;
}

void	figure_print(char **src, int *tab, char alpha) /* друкує наш масив */
{
	int iny;
 	int inx;

 	iny = 0;
 	inx = 1;
 	while (inx <= 7)
 	{
 		 src[tab[iny]][tab[inx]] = alpha;
 		 inx = inx + 2;
 		 iny = iny + 2;
 	}
}

void	map_print(int **tab, int map_size, int figure_count)
{
	char **src;
	int		index;								/* print */
	char	a;

	a = 'A';
	index = 0;
	map_creator(&src, map_size);
	while (index < figure_count)
	{
		figure_print(src, tab[index], a);
		index++;
		a++;
	}
	index = 0;
 	while (src[index])
		ft_putendl(src[index++]);
	ft_putendl(src[index]);
	free(src);
}

void taras(int **tab, int figure_count)
{
	int map_size;

	map_size = ft_map_size(figure_count);
	solid(tab, &map_size, figure_count);
	map_print(tab, map_size, figure_count);

}
