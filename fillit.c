#include "fillit.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


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

int				ft_check_valid_figure(int *tab)
{
	if (ft_check_valid_figure_part1(tab) == 1)
		return (1);
	if (ft_check_valid_figure_part2(tab) == 1)
		return (1);
	return (0);
}





static int			add_tetr(t_tetriminos **root, t_tetriminos *new)
{
	if (!new)
		return (0);
	if (!(*root))
		*root = new;
	else
	{
		if ((*root)->next)
			add_tetr(&(*root)->next, new);
		else
	 		(*root)->next = new;
	}
	return (1);
}

static int			*ft_get_coordinates(char **content)
{
	int *coordinates;
	int x;
	int y;
	int i;

	i = 0;

	if(!content || !(coordinates = (int*)malloc(sizeof(int) * 8)))
		return (NULL);
	x = 0;
	while (content[x])
	{
		y = 0;
		while (content[x][y] )
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
	return (coordinates);
}

static t_tetriminos	*new_tetr(char *str, char ltr)
{
	t_tetriminos *new;

	if (ltr <= 'Z' && (new = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
	{
		new->content = ft_strsplit(str, '\n');
		new->coordinates = ft_get_coordinates(new->content);
		if (!ft_check_valid_figure(new->coordinates))
		{
			printf("%s\n", "Error!========= FUCK ME ====");
			return (NULL);
		}
		new->ltr = ltr;
		new->next = NULL;
		return (new);
	}
	ft_putstr("Error! Your file must contain between 1 and 26 Tetriminos");
	return (NULL);
}

static int			input_check(char *str)
{
	int dot_counter;
	int hash_counter;
	int new_lines;

	dot_counter = 0;
	hash_counter = 0;
	new_lines = 0;
	while(*str)
	{
		while (*(str) != '\n')
		{
			if (*(str) != '.' && *(str) != '#')
			{
				ft_putstr("Error! Tetriminos must be made via dots and hash tags\n");
				return (0);
			}
			*str == '.' ? dot_counter++ : hash_counter++;
			str++;
		}
		new_lines++;
		str++;
		if ((dot_counter + hash_counter) / new_lines != 4)
		{
			ft_putstr("Error! Each line must have 4 symbols\n");
			return (0);
		}
	}
	if (new_lines != 4 || dot_counter != 12 || hash_counter != 4)
	{
		ft_putstr("Error! Tetriminos must have 4 lines, 12 dots and 4 hash tags\n");
		return (0);
	}
	return (1);
}

static void			clean_lst(t_tetriminos **lst)
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

	char				**content;
	int					*coordinates;
	char				letter;
	struct s_tetriminos	*next;

t_tetriminos		*ft_read_file(char *argv)
{
	int				fd;
	int				ret;
	char			*str;
	char			ltr;
	t_tetriminos	*lst;

	ltr = 'A';
	lst = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * 21);
	while ((ret = read(fd, str, 21)))
	{ 
		str[20] = '\0';
		if (!input_check(str) || !(add_tetr(&lst, new_tetr(str, ltr++))))
		{
			clean_lst(&lst);
			break ;
		}
	}
	if (close(fd) == -1)
		return (NULL);
	return (lst);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

int	main(int argc, char **argv)
{
	int a = 0;
	t_tetriminos *tetriminos;
	char **syka;
	if (argc == 2)
	{
		tetriminos = ft_read_file(argv[1]);
		syka = tetriminos->content;
		int *aaa;
		aaa = tetriminos->coordinates;
		while (a < 8)
			printf("%d, ", aaa[a++]);
		printf("\n");
		while (*syka)
			printf("%s\n", *syka++);
	}
	else
		ft_putstr("usage: fillit [file name]\n");
	return (0);
}
