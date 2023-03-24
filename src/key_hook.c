/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:33:44 by angela            #+#    #+#             */
/*   Updated: 2023/03/24 14:31:59 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_mlx *mlx) // notre fonction de key input
{
	if((mlx->y <= WIN_H) || mlx->x <= WIN_W)
	{
		if (keycode == KEY_UP)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
			mlx->y -= mlx->jump;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
			// move.up = 1;
			printf("Up!\n");
		}
		if (keycode == KEY_LEFT)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
			mlx->x -= mlx->jump;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
			//move.left = 1;
			printf("Left!\n");
		}	
		if (keycode == KEY_DOWN)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
			mlx->y += mlx->jump;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x,mlx->y);	
			//move.down = 1;
			printf("Down!\n");
		}
		if (keycode == KEY_RIGHT)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
			mlx->x += mlx->jump;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
			//move.right = 1;
			printf("Right!\n");
		}
		if (keycode == KEY_ESC)
		{
			mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
			printf("shuting down!\n");
			exit(1);
		}
	}
	
	return (0);
}