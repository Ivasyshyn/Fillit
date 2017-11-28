/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:29:10 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/24 14:29:43 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h> //printf("%s\n", );

t_tetriminos	*ft_new_tetriminos(char *content)
{
	t_tetriminos *new;
	char **content;

	if ((new = (t_tetriminos)malloc(sizeof(t_tetriminos))))
		if ((content = (char **)malloc(sizeof(char *) * 5)))
		{
			t_tetriminos->content = ft_strsplit(content, '\n');
			t_tetriminos->next = NULL;
			return (new);
		}
	return (NULL);
}



void		ft_read_file(char **dst, char *av, int argc);
int			ft_tochka(char *dst);

static	void	ft_change_alphabet(char *dst)
{
	int count;	//заміна шарпів на алфавіт

	char alpha;

	alpha = 65;
	count = 0;
	while (*dst)
	{
		if (*dst == '#' && count <= 4)
		{
			*dst = alpha;
			count++;
		}
		if (count == 4)
		{
			alpha = alpha + 1;
			count = 0;
		}
		dst++;
	}
}

int			main(int argc, char **argv)
{
	char *dst;
	char **tmp;
	dst = NULL;
	ft_read_file(&dst, argv[1], argc);
	printf("%s\n", dst);   //друкуємо одновимірний масив для перевірки нашаго
// зчитування 
	if (ft_tochka(dst) == 0) // перевіряємо валідність нашого файлу на к-ть точок і дієзів у фігури
		return (0);
	// if (ft_valid_figure(dst) == 0)
	// 	return (0);
	ft_change_alphabet(dst);
	tmp = ft_strsplit(dst, '\n'); // розділяємо одновимірний на масив 2/вимірний
	free(dst);
	dst = NULL;
	while(*tmp)
		printf("%s\n", *tmp++);
	return (0);
}
