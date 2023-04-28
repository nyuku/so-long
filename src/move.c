/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:49:29 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/28 00:26:08 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_touch_player(t_mlx *mlx, int move_j, int move_i)
{
	if (((mlx->map.char_map[(mlx->y / 64) + move_j][(mlx->x / 64) + move_i]) \
	!= '1') && ((((mlx->map.char_map[(mlx->y / 64) + move_j] \
	[(mlx->x / 64) + move_i]) != 'E') \
	&& (mlx->game.coins_count <= mlx->game.coins))))
	{
		if (mlx->map.char_map[(mlx->y / 64) + move_j] \
		[(mlx->x / 64) + move_i] == 'C')
		{
			mlx->game.coins_count++;
			mlx->map.char_map[(mlx->y / 64) + move_j] \
			[(mlx->x / 64) + move_i] = '0';
		}
		put_and_move_player(mlx, move_j, move_i);
	}
	else if ((mlx->game.coins_count == mlx->game.coins) && \
	((mlx->map.char_map[(mlx->y / 64) + move_j][(mlx->x / 64) + move_i]) \
	== 'E') && (mlx->game.coins_count == mlx->game.coins))
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
		ft_printf("%s\n%s%s%s%s%s           ᕙ(⌐■_■)ᕗ \n\n%s\n\n", \
		DECO, SPACE, MIAM, MAMI, MERCI, SPACE, DECO);
		exit(0);
	}
	return (0);
}

void	put_and_move_player(t_mlx *mlx, int move_j, int move_i)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, \
	mlx->decor.background_ptr, mlx->x, mlx->y);
	mlx->y += (JUMP * move_j);
	mlx->x += (JUMP * move_i);
	mlx->game.steps++;
	print_steps(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, \
	mlx->decor.player_ptr, mlx->x, mlx->y);
}
