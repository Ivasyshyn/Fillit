
#include "fillit.h"

#include "libft.h"

#include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>
      #include <fcntl.h>
#include <stdio.h>
// int		ft_search_error(int argc)	// друкує помилки коли назва файла некоректна
// {
// 	if (argc < 2 || argc > 2)
// 	{
// 		ft_putstr("usage: fillit [file name]\n");
// 		return (0);
// 	}
// 		return (1);
// }

void	ft_lst_add_last2(t_tetriminos **root, t_tetriminos *new)
{
	if (!(*root))
	{
		//printf("%s\n", "sss22222");
		*root = new;
	}
	else
	{
		if ((*root)->next)
		{
			//printf("%s\n", "sss2");
			ft_lst_add_last2(&(*root)->next, new);
		}
		else
		{
			//printf("%s\n", "sss3");
	 		(*root)->next = new;
		}
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
		//while (*content2)
		//	printf("%s\n", *content2++);
		return (new);
	}
	return (NULL);
}

int		ft_first_check(char *str)// Валідність файлу на точки і дієзи (кількість в межах фігури)
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
	int 	fd;						// читає файл та записує інформацію в межах однов/масиву 
	int		ret;
	int		i;
	char	*dst;
	t_tetriminos *tetriminos;

	tetriminos = NULL;
	i = 0;
	// if (!ft_search_error(argc))
	// 	return ;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		//ft_search_error(0);
		return (NULL);
	}

	dst = (char *)malloc(sizeof(char) * 20);
	while ((ret = read(fd, &dst[i], 1)))
	{
		i++;
		printf("%d\n", i);
		printf("%c\n", dst[i -	1]);
		//if (dst[0] == '\n')
		//	return (0);
		if (dst[i -	1] == '\n' && dst[i] == '\n')
		{
			dst[i - 1] = '\0';
			if (ft_first_check(dst))
			{
				ft_lst_add_last2(&tetriminos, ft_new_tetriminos(dst));
				i = 0;
				//ft_bzero(dst, 1);
			}
		}
	}
	if (close(fd) == -1)
		return (NULL);

	return (tetriminos);
}



int	main(int argc, char **argv)
{
	t_tetriminos *tetriminos;
	char **syka;

	tetriminos = ft_read_file(argv[1]);
	syka = tetriminos->next->next->next->next->content;
	while (*syka)
		printf("%s\n", *syka++);
	

	return 0;
}