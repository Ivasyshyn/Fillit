/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:06:15 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/02 21:06:16 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int ft_map_size(int nb) // вираховує розмір фігури
{
	int res;
	int tmp;

	tmp = nb * 4;
	while ((res = ft_sqrt(tmp)) == 0)
		tmp++;
	return (res);
}

char	**map_creator(int nb) // створює карту
{
	char **dst;
	int index;

	index = 0;
	dst = (char **)malloc(sizeof(char *) * (nb + 1));
	while (index < nb)
	{
		dst[index] = ft_strnew(nb);
		ft_memset(dst[index], '.', nb);
		index++;
	}
	dst[index] = NULL;
	return (dst);
}

void	print_map(char **src, int *tab, char alpha) // друкує наш масив
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

int main(void)
{
	/////////////////////////////////////////////////////
	int **tab = (int **)malloc(sizeof(int *) * 4);
	tab[0] = (int *)malloc(sizeof(int) * 8);
	tab[1] = (int *)malloc(sizeof(int) * 8);
	tab[2] = (int *)malloc(sizeof(int) * 8);
	tab[3] = (int *)malloc(sizeof(int) * 8);
	// tab[4] = (int *)malloc(sizeof(int) * 8);
	// tab[5] = (int *)malloc(sizeof(int) * 8);
	// tab[6] = (int *)malloc(sizeof(int) * 8);
	// tab[7] = (int *)malloc(sizeof(int) * 8);
	int tab1[8] = {0, 0, 0, 1, 1, 0, 1, 1}; // г ліва
	int tab2[8] = {0, 0, 0, 1, 0, 2, 0, 3}; // квадрат
	int tab3[8] = {0, 0, 1, 0, 1, 1, 1, 2}; // г права
	int tab4[8] = {0, 0, 0, 1, 1, 1, 1, 2};
	// int tab5[8] = {0, 0, 1, 0, 2, 0, 3, 0};
	// int tab6[8] = {0, 0, 1, 0, 2, 0, 3, 0};
	// int tab7[8] = {0, 0, 1, 0, 2, 0, 3, 0};
	ft_memmove(tab[0], tab1, sizeof(int) * 8);
	ft_memmove(tab[1], tab2, sizeof(int) * 8);
	ft_memmove(tab[2], tab3, sizeof(int) * 8);
	ft_memmove(tab[3], tab4, sizeof(int) * 8);
	// ft_memmove(tab[4], tab5, sizeof(int) * 8);
	// ft_memmove(tab[5], tab6, sizeof(int) * 8);
	// ft_memmove(tab[6], tab7, sizeof(int) * 8);
	// ft_memmove(tab[7], tab1, sizeof(int) * 8);
	/////////////////////////////////////////////////////
	int figure_count = 4; // = list_size	
	int map_size = ft_map_size(figure_count);
	

//	solid(tab, &map_size, figure_count); // solid
	solid(tab, &map_size, figure_count);
	////////////////////////////////////////////////////
	char **src;								// print
	src = map_creator(map_size);

  	print_map(src, tab[0], 'A');
  	print_map(src, tab[1], 'B');
  	print_map(src, tab[2], 'C');
 	print_map(src, tab[3], 'D');
  	// print_map(src, tab[4], 'E');
  	// print_map(src, tab[5], 'F');
  	// print_map(src, tab[6], 'G');
  	// print_map(src, tab[7], 'H');

 	while (*src)
		printf("%s\n", *src++);
 	printf("%s\n", *src);
 	printf("xaxa = %d\n", map_size);
 	////////////////////////////////////////////////////
	return (0);
}