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
//	int size;
	int tmp;

	tmp = nb * 4;
	while ((res = ft_sqrt(tmp)) == 0)
		tmp++;
//	size = res > height ? res : height;
	return (res);
}

char	**map_creator(int nb) // створює карту
{
	char **dst;
	int tmp;
	int index;

	index = 0;
	tmp = ft_map_size(nb);
	dst = (char **)malloc(sizeof(char *) * (tmp + 1));
	while (index < tmp)
	{
		dst[index] = ft_strnew(tmp);
		ft_memset(dst[index], '.', tmp);
		index++;
	}
	dst[index] = NULL;
	return (dst);
}

void	print_map(char **src, int *tab, char alpha) // друкує наш масив
{
	int iny = 0;
 	int inx = 1;

 	while (inx <= 7)
 	{
 		 src[tab[iny]][tab[inx]] = alpha;
 		 inx = inx + 2;
 		 iny = iny + 2;
 	}
}

// int main(void)
// {
// 	int **tab = (int **)malloc(sizeof(int *) * 3);

// 	tab[0] = (int *)malloc(sizeof(int) * 8);
// 	tab[1] = (int *)malloc(sizeof(int) * 8);
// 	tab[2] = (int *)malloc(sizeof(int) * 8);
// 	tab = {0, 0, 1, 0, 2, 0, 3, 0}, {0, 1, 1, 0, 1, 1, 2, 1}, {0, 1, 1, 0, 1, 1, 2, 0};
// 	int size = ft_map_size(2);
// 	char **src;
// 	solid(tab, size);


// 	src = map_creator(4);
//  	print_map(src, tab[0], 'A');
//  	print_map(src, tab[1], 'B');

//  	while (*src)
// 		printf("%s\n", *src++);
//  	printf("%s\n", *src);
//  	////////////////////////////////////////////////////
// 	return (0);
// }

int main(void)
{
	int tab2[8] = {0, 0, 1, 0, 2, 0, 2, 1};
	int tab[8] = {0, 0, 0, 1, 1, 0, 1, 1};
	int size = ft_map_size(2);
	char **src;
	solid(tab, tab2, 3);

	src = map_creator(2);
	printf("123\n");
 	print_map(src, tab, 'A');
 	print_map(src, tab2, 'B');
 	while (*src)
		printf("%s\n", *src++);
 	printf("%s\n", *src);
 	////////////////////////////////////////////////////
	return (0);
}