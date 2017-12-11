/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_audit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:08:36 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/10 22:08:37 by tlutsyk          ###   ########.fr       */
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

int				tetr_check(int *tab)
{
	if (ft_check_valid_figure_part1(tab) == 1)
		return (1);
	if (ft_check_valid_figure_part2(tab) == 1)
		return (1);
	return (0);
}

int				check(int **tab, int index)
{
	int first;
	int last;
	int row;

	row = index - 1;
	while (row >= 0)
	{
		first = 0;
		while (first <= 6)
		{
			last = 0;
			while (last <= 6)
			{
				if (tab[row][first] == tab[index][last]
					&& tab[row][first + 1] == tab[index][last + 1])
					return (0);
				last = last + 2;
			}
			first = first + 2;
		}
		row--;
	}
	return (1);
}

void			ft_move_default_figure(int **tab, int figure_count)
{
	int index;

	index = 0;
	while (index < figure_count)
		move_left_figure(tab[index++], 0);
}
