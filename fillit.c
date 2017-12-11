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
			(*root)->next = new;
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

static t_tetr	*new_t(char *str, char ltr)
{
	t_tetr	*new;

	if (!(tetr_check(get_xy(ft_strsplit(str, '\n')))))
		ft_putstr("error\n");
	else if (ltr > 'Z')
		ft_putstr("error\n");
	else if (!(new = (t_tetr*)malloc(sizeof(t_tetr))))
		ft_putstr("error\n");
	else
	{
		new->content = ft_strsplit(str, '\n');
		new->coordinates = get_xy(new->content);
		new->ltr = ltr;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

static int		error_msg(int error)
{
	if (error == 1 || error == 2 || error == 3)
		ft_putendl("error");
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
		ft_putstr("error\n");
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
	int index;

	index = 0;
	while (lst)
	{
		tabb[index] = lst->coordinates;
		lst = lst->next;
		index++;
	}
	sirizyk_pirozik(tabb, size_of_list);
	free(tabb);
	return (0);
}
