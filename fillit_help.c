/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:08:48 by sivasysh          #+#    #+#             */
/*   Updated: 2017/12/11 17:08:48 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*get_xy(char **content)
{
	int *coordinates;
	int x;
	int y;
	int i;

	i = 0;
	if (!content || !(coordinates = (int*)malloc(sizeof(int) * 8)))
		return (NULL);
	x = 0;
	while (content[x])
	{
		y = 0;
		while (content[x][y])
		{
			if (content[x][y] == '#')
			{
				coordinates[i++] = x;
				coordinates[i++] = y;
			}
			y++;
		}
		x++;
	}
	move_left_figure(coordinates, 0);
	return (coordinates);
}

int		ft_list_size(t_tetr *lst)
{
	int		index;
	t_tetr	*start;

	index = 0;
	start = lst;
	while (start)
	{
		index++;
		start = start->next;
	}
	return (index);
}

int		error_msg(int error)
{
	if (error == 1 || error == 2 || error == 3)
		ft_putendl("error");
	return (0);
}

int		in_check(char *str)
{
	int dot_counter;
	int hash_counter;
	int new_lines;

	dot_counter = 0;
	hash_counter = 0;
	new_lines = 0;
	while (*str)
	{
		while (*str != '\n')
		{
			if (*str != '.' && *str != '#')
				return (error_msg(1));
			*str == '.' ? dot_counter++ : hash_counter++;
			str++;
		}
		new_lines++;
		str++;
		if ((dot_counter + hash_counter) / new_lines != 4)
			return (error_msg(2));
	}
	if (new_lines != 4 || dot_counter != 12 || hash_counter != 4)
		return (error_msg(3));
	return (1);
}

void	get_tabb(t_tetr *lst, int **tabb)
{
	int	index;

	index = 0;
	while (lst)
	{
		tabb[index] = lst->coordinates;
		lst = lst->next;
		index++;
	}
}
