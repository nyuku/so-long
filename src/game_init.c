/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:22:45 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/22 23:58:05 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	start_init(char *str, t_mlx *mlx)
{
	mlx->map.lines = ft_count_line_map(str, mlx);
	if (!mlx->map.lines)
		return (0);
	mlx->map.char_map = ft_harvest_map(str, mlx);
	mlx->map.colonn = count_colonn(mlx->map.char_map);
	mlx->game.coins = 0;
	mlx->game.steps = 0;
	mlx->game.coins_count = 0;
	mlx->game.coins_path_count = 0;
	mlx->map.exit_count = 0;
	mlx->jump = 64;
	mlx->win_height = 64 * mlx->map.lines;
	mlx->win_width = 64 * mlx->map.colonn;
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_window_ptr = mlx_new_window(mlx->mlx_ptr, \
	mlx->win_width, mlx->win_height, "Test :3");
	mlx->jump = 64;
	mlx->error_trigger = 0;
	return (1);
}

int	start_game(char *str, t_mlx *mlx)
{
	if (!start_init(str, mlx))
		return (0);
	check_error_map(str, mlx);
	count_coins(mlx);
	init_decor_path(mlx);
	init_decor_ptr(mlx);
	check_ptr(mlx);
	render_all(mlx);
	creat_path_finding_check(mlx);
	player_xy(mlx);
	return (1);
}

void	player_xy(t_mlx *mlx)
{
	mlx->p.player_i = mlx->x / 64;
	mlx->p.player_j = mlx->y / 64;
}

int	creat_path_finding_check(t_mlx *mlx)
{
	int	i;

	mlx->map.tableau_check = malloc(sizeof(char *) * (mlx->map.lines));
	if (!mlx->map.tableau_check)
		return (0);
	i = 0;
	while (i < mlx->map.lines)
	{
		mlx->map.tableau_check[i] = malloc(sizeof(char) * mlx->map.colonn);
		i++;
	}
	return (0);
}
