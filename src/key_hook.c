/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:33:44 by angela            #+#    #+#             */
/*   Updated: 2023/04/28 18:07:32 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if ((mlx->y <= mlx->win_height) || mlx->x <= mlx->win_width)
	{
		if (keycode == KEY_UP)
			check_touch_player(mlx, -1, 0);
		if (keycode == KEY_LEFT)
			check_touch_player(mlx, 0, -1);
		if (keycode == KEY_DOWN)
			check_touch_player(mlx, 1, 0);
		if (keycode == KEY_RIGHT)
			check_touch_player(mlx, 0, 1);
		if (keycode == KEY_ESC)
		{
			mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
			ft_printf("\n%s\nshuting down!\n%s\n", DECO, DECO);
			exit(0);
		}
	}	
	return (0);
}
