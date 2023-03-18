/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:07:59 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/18 19:40:44 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
{
	
}
//int render(t_mlx *mlx)
{
	
	if(mlx->move->up == 1)
	{
		mlx->old_y = (mlx->y + mlx->move);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr,  mlx->img.newimage_ptr, mlx->x, mlx->y);
		// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background, mlx->x, mlx->old_y);
		move.up = 0;
	}
	if(mlx->move.down == 1)
	{
		mlx->old_y = (mlx->y - mlx->move);
		mlx_put_image_to_window(mlx->mlx_ptr,  mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);
		// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background, mlx->x, mlx->old_y);
		move.down = 0;
	}
	if(mlx->move.right == 1)
	{
		mlx->old_x = (mlx->x - mlx->move);
		mlx_put_image_to_window(mlx->mlx_ptr,  mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);
		// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background, mlx->old_x, mlx->y);
		move.right = 0;
	}
	if(mlx->move.left == 1)
	{
		mlx->old_x = (mlx->x + mlx->move);
		mlx_put_image_to_window(mlx->mlx_ptr,  mlx->mlx_window_ptr,  mlx->img.newimage_ptr, mlx->x, mlx->y);
		// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background, mlx->old_x, mlx->y);
		move.left = 0;
	}
	return(0);
}