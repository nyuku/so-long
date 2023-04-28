/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:35 by angela            #+#    #+#             */
/*   Updated: 2023/04/28 00:43:58 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_background(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (mlx->map.lines))
	{
		while (i < mlx->map.colonn)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, \
			mlx->decor.background_ptr, (i * 64), (j * 64));
			i++;
		}
		j++;
		i = 0;
	}
}

void	render_all(t_mlx *mlx)
{
	render_background(mlx);
	render_wall_map(mlx);
	render_wall_map(mlx);
	render_player(mlx);
	render_exit(mlx);
	render_coins(mlx);
	render_wall_map(mlx);
}

void	print_steps(t_mlx *mlx)
{
	ft_printf("Steps: %d\n", mlx->game.steps);
}

int	path_finding(t_point p, t_mlx *mlx)
{
	if ((mlx->map.char_map[p.player_j][p.player_i]) == '1' \
	|| (mlx->map.tableau_check[p.player_j][p.player_i]) == 'v')
	{
		return (1);
	}
	mlx->map.tableau_check[p.player_j][p.player_i] = 'v';
	if ((mlx->map.char_map[p.player_j][p.player_i]) == 'E')
	{
		mlx->map.exit_count = 1;
	}
	else if ((mlx->map.char_map[p.player_j][p.player_i]) == 'C')
	{
		mlx->game.coins_path_count++;
	}
	path_finding((t_point){p.player_j - 1, p.player_i}, mlx);
	path_finding((t_point){p.player_j + 1, p.player_i}, mlx);
	path_finding((t_point){p.player_j, p.player_i - 1}, mlx);
	path_finding((t_point){p.player_j, p.player_i + 1}, mlx);
	return (0);
}
