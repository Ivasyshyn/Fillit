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

typedef	struct			s_tetriminos
{
	char				**content;
	struct s_tetriminos	*next;
}						t_tetriminos;




#endif