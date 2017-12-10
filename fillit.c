/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:10:36 by sivasysh          #+#    #+#             */
/*   Updated: 2017/12/03 21:10:36 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_valid_figure_part1(int *t)
{
	if ((t[1] == t[3] && t[5] == t[7] && t[1] == t[5]) && \
	(t[0] + t[2] + t[4] + t[6] == 6))
		return (1);
	if ((t[0] == t[2] && t[4] == t[6] && t[0] == t[6]) && \
		(t[1] + t[3] + t[5] + t[7] == 6))
		return (1);
	if ((t[3] == (t[5] - 1)) && (t[3] == ((t[7]) - 2)) && \
		((t[1] == t[3]) || (t[1] == t[5]) || (t[1] == t[7])) && \
		((t[2] == t[4] && t[6] == t[2]) && t[0] == t[2] - 1))
		return (1);
	if ((t[1] == (t[3] - 1)) && (t[1] == ((t[5]) - 2)) &&
		((t[7] == t[3]) || (t[7] == t[5]) || (t[7] == t[1])) &&
		((t[0] == t[2] && t[4] == t[2]) && t[6] == t[2] + 1))
		return (1);
	if ((t[0] == t[2] && t[4] == t[6] && t[0] == t[6] - 1) &&
		(t[1] == (t[3] - 1) && t[5] == (t[7] - 1) &&
		((t[1] == t[5] + 1) || (t[1] == t[5] - 1) || t[1] == t[5])))
		return (1);
	return (0);
}

static int		ft_check_valid_figure_part2(int *t)
{
	if ((t[0] == t[2] - 1 && t[0] == t[4] - 1 && t[0] == t[6] - 2) && \
		((t[1] == t[5] && t[3] == t[7] && t[1] == t[3] + 1) || \
		(t[1] == t[3] && t[5] == t[7] && t[1] == t[5] - 1)))
		return (1);
	if ((t[0] == t[2] && t[0] == t[4] - 1 && t[0] == t[6] - 2) && \
		((t[7] == t[5] && t[5] == t[3] && t[1] == t[3] - 1) || \
		((t[7] == t[5] && t[5] == t[1] && t[3] == t[1] + 1))))
		return (1);
	if ((t[2] == t[4] && t[0] == (t[2] - 1) && t[6] == (t[4] + 1)) && \
		((t[1] == t[5] && t[5] == t[7] && (t[3] == (t[7] - 1))) || \
		(t[1] == t[3] && t[3] == t[7] && t[5] == (t[7] + 1))))
		return (1);
	if (t[6] == t[4] && t[2] == (t[4] - 1) && t[0] == t[2] - 1 && \
		((t[1] == t[3] && t[3] == t[5] && t[7] == (t[5] + 1)) \
		|| (t[1] == t[3] && t[3] == t[7] && t[5] == (t[7] - 1))))
		return (1);
	return (0);
}

static int		tetr_check(int *tab)
{
	if (ft_check_valid_figure_part1(tab) == 1)
		return (1);
	if (ft_check_valid_figure_part2(tab) == 1)
		return (1);
	return (0);
}

static int		add_t(t_tetr **root, t_tetr *new)
{
	if (!new)
		return (0);
	if (!(*root))
		*root = new;
	else
	{
		if ((*root)->next)
			add_t(&(*root)->next, new);
		else
		{
			(*root)->next = new;
			new->prev = *root;
		}
	}
	return (1);
}

static int		*get_xy(char **content)
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

static int		get_size(int *c)
{
	int x;
	int y;

	x = c[6] - c[0] + 1;
	y = c[7] - c[1] + 1;
	return (x > y ? x : y);
}

static t_tetr	*new_t(char *str, char ltr)
{
	t_tetr	*new;

	if (!(tetr_check(get_xy(ft_strsplit(str, '\n')))))
		ft_putstr("Error! The figure isn't Tetriminos\n");
	else if (ltr > 'Z')
		ft_putstr("Error! The file must contain between 1 and 26 Tetriminos\n");
	else if (!(new = (t_tetr*)malloc(sizeof(t_tetr))))
		ft_putstr("Error! Malloc hasn't been able to allocate memory\n");
	else
	{
		new->content = ft_strsplit(str, '\n');
		new->coordinates = get_xy(new->content);
		new->ltr = ltr;
		new->size = get_size(new->coordinates);
		new->next = NULL;
		new->prev = NULL;
		return (new);
	}
	return (NULL);
}

static int		error_msg(int error)
{
	if (error == 1)
		ft_putstr("Error! Only '.' and '#' are allowed\n");
	if (error == 2)
		ft_putstr("Error! Each line must have 4 symbols\n");
	if (error == 3)
		ft_putstr("Error! Tetriminos must have 4 lines, 12 '.' and 4 '#'\n");
	return (0);
}

static int		in_check(char *str)
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

static void		clean_lst(t_tetr **lst)
{
	if (*lst)
	{
		if ((*lst)->next)
			clean_lst(&(*lst)->next);
		while (*(*lst)->content)
			ft_strdel(&(*(*lst)->content++));
		ft_memdel((void*)&(*lst)->coordinates);
		ft_memdel((void*)lst);
	}
}

static t_tetr	*ft_read_file(char *file, t_tetr **lst)
{
	int		fd;
	int		ret;
	int		last;
	char	*str;
	char	ltr;

	ltr = 'A';
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	while ((ret = read(fd, str, 21)))
	{
		str[20] = '\0';
		if (!in_check(str) || !(add_t(lst, new_t(str, ltr++))))
			return (NULL);
		last = ret;
	}
	if (last != 20)
	{
		ft_putstr("Error! Invalid new line quantity\n");
		return (NULL);
	}
	return (close(fd) == -1 ? NULL : *lst);
}

int	ft_list_size(t_tetr *lst)
{
	int index;
	t_tetr *start;

	index = 0;
	start = lst;
	while(start)
	{
		index++;
		start = start->next;
	}
	return (index);
}

int				main(int argc, char **argv)
{
	t_tetr	*lst;
	t_tetr	*tetriminos;
	int		size_of_list;
	int		**tabb;

	if (argc == 2)
	{
		if (!(tetriminos = ft_read_file(argv[1], &lst)))
		{
			clean_lst(&lst);
			return (0);
		}
	}
	else
	{
		ft_putstr("usage: fillit [file name]\n");
		return (0);
	}
	size_of_list = ft_list_size(lst);
	tabb = (int **)malloc(sizeof(int *) * size_of_list);
	int index = 0;

	while (lst)
	{
		tabb[index] = lst->coordinates;
		lst = lst->next;
		index++;
	}
	taras(tabb, size_of_list);
	free(tabb);
	return (0);
}
