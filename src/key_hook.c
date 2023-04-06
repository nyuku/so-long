/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:33:44 by angela            #+#    #+#             */
/*   Updated: 2023/04/06 16:42:43 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_mlx *mlx) // notre fonction de key input
{
	if((mlx->y <= mlx->win_height) || mlx->x <= mlx->win_width)
	{
		if (keycode == KEY_UP)
			check_up(mlx);
		if (keycode == KEY_LEFT)
			check_left(mlx);
		if (keycode == KEY_DOWN)
			check_down(mlx);
		if (keycode == KEY_RIGHT)
			check_right(mlx);		
		if (keycode == KEY_ESC)
		{
			mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
			printf("shuting down!\n");
			exit(1);
		}
	}	
	return (0);
}