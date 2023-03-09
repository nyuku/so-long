/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:55:11 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/09 22:03:09 by angnguye         ###   ########.fr       */
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
	void	*newimage_ptr;
	void	*mlx_ptr;
	void	*mlx_window_ptr;
	char	*adress;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;





# endif