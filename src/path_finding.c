/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:35 by angela            #+#    #+#             */
/*   Updated: 2023/04/23 01:08:45 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_all(t_mlx *mlx)
{
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
