/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:55:11 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/10 19:44:28 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h> // pour open


# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LFT 123
# define KEY_DWN 125
# define KEY_RGT 124
# define KEY_ESC 53
# define X_BTN 17

# define ERROR 1

# define WIN_H 650
# define WIN_W 420
# define IMG_PXL 32



/*-----------------------------------------------*
    Pour afficher image 
*------------------------------------------------*/
typedef struct s_img
{
	void	*newimage_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/*-----------------------------------------------*
    Pour afficher mlx
*------------------------------------------------*/
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window_ptr;
	char	*adress;
	t_img	img;
	int x;
	int y;

}	t_mlx;


/*-----------------------------------------------*
    Pour map
*------------------------------------------------*/
typedef struct s_map
{
	int	i;
}	t_map;



# endif