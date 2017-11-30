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

t_tetriminos	*ft_new_tetriminos(char *str)
{
	t_tetriminos *new;
	char **content2;

	if ((new = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
	{
		new->content = ft_strsplit(str, '\n');
		new->next = NULL;
		content2 = new->content;
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
				printf("%s\n", "Handled error 1: Only '.' and '#' signs are allowed");
				return (0);
			}
			*str == '.' ? dot_counter++ : hash_counter++;
			str++;
		}
		new_lines++;
		str++;
		if ((dot_counter + hash_counter) / new_lines != 4)
		{
			printf("%s\n", "Handled error 2: Only 4 chars per line");
			return (0);
		}
	}
	if (new_lines != 4 || dot_counter != 12 || hash_counter != 4)
	{
		printf("%s\n", "Handled error 3: Only 4 lines, 12 dots and 4 hash tags");
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
	t_tetriminos *tetriminos;
	char **syka;

	if (argc == 2)
	{
		tetriminos = ft_read_file(argv[1]);
		syka = tetriminos->next->next->next->next->content;
		while (*syka)
			printf("%s\n", *syka++);
	}
	else
		ft_putstr("usage: fillit [file name]\n");
	return (0);
}
