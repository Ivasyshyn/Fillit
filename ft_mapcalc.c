/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:06:15 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/02 21:06:16 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int in;
	int res;

	in = 0;
	res = 0;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (res <= nb)
	{
		res = in * in;
		if (res == nb)
			return (in);
		in++;
	}
	return (0);
}

int ft_map_size(nb)
{
	int res;
	int size;

	size = 2;
	res = nb * 4;
	size = ft_sqrt(res) == 0 ? ft_map_size(++nb) : ft_sqrt(res);
	return (size);
}

int main(void)
{
	int count;
	int res;

	count = 2;
	res = ft_map_size(count);
	printf("%d\n", res);
	return (0);
}