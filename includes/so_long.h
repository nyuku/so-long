/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:55:11 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/09 20:04:55 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
#include <fcntl.h> // pour open

typedef struct s_mlx
{
	void *newimage_ptr;

	char *adress;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_mlx;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img	mlx;
}	t_data;


# endif