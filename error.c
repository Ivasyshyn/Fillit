#include "fillit.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	ft_lst_add_last2(t_tetriminos **root, t_tetriminos *new)
{
	if (!(*root))
		*root = new;
	else
	{
		if ((*root)->next)
			ft_lst_add_last2(&(*root)->next, new);
		else
	 		(*root)->next = new;
	}
}

int		*ft_take_coordinates(char **content)
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
				*coordinates++ = x;
				*coordinates++ = y;
			}
			y++;
		}
		x++;
	}

	return (coordinates);
}

t_tetriminos	*ft_new_tetriminos(char *str)
{
	t_tetriminos *new;

	if ((new = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
	{
		new->content = ft_strsplit(str, '\n');
		new->coordinates = ft_take_coordinates(new->content);
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int		ft_first_check(char *str)
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

t_tetriminos  *ft_read_file(char *argv)
{
	int				fd;
	int				ret;
	char			*dst;
	t_tetriminos	*tetriminos;

	tetriminos = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * 21);
	while ((ret = read(fd, dst, 21)))
	{ 
		dst[20] = '\0';
		if (!ft_first_check(dst))
			break ;
		ft_lst_add_last2(&tetriminos, ft_new_tetriminos(dst));
	}
	if (close(fd) == -1)
		return (NULL);
	return (tetriminos);
}

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
