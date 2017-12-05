/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:16:16 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/26 17:16:16 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct			s_tetr
{
	char				**content;
	int					*coordinates;
	int					size;
	char				ltr;
	struct s_tetr		*next;
	struct s_tetr		*prev;
}						t_tetr;

#endif
