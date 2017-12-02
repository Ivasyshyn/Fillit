/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:09:34 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/02 19:09:35 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// int				main(void)
// {
// 	int ta31[8] = {1, 1, 1, 2, 2, 1, 2, 2};

// 	if (ft_check_valid_figure(ta31))
// 		printf("%s\n", "yoyo");
// 	else
// 		printf("%s\n", "FUCKYOURSELF");
// 	return (0);
// }