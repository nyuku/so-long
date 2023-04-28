/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:35:01 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/28 18:06:22 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_msg(char *str, t_mlx *mlx)
{
	ft_printf("\n%s\nERROR\n-----\n%s\n%s\n", DECO, str, DECO);
	mlx->error_trigger = 1;
	return (1);
}

int	check_error_map(char *str, t_mlx *mlx)
{
	if (check_map_ext(str) == 1)
		return (error_msg(ERROR_EXT, mlx));
	else if (check_rectangle(mlx->map.char_map, \
	mlx->map.lines, mlx->map.colonn) == 1)
		return (error_msg(ERROR_RECTANGLE, mlx));
	else if (check_only_pec01(mlx) == 1)
		return (error_msg(ERROR_PEC01, mlx));
	else if (check_wall_map(mlx) == 1)
		return (error_msg(ERROR_WALL, mlx));
	else if (check_one_exit(mlx) == 1)
		return (error_msg(ERROR_EXIT, mlx));
	else if (check_one_player(mlx) == 1)
		return (error_msg(ERROR_PLAYER, mlx));
	else if (check_one_coin(mlx) == 1)
		return (error_msg(ERROR_COINS, mlx));
	return (0);
}

int	check_error_game(int a, t_mlx *mlx)
{
	if (mlx->game.coins_path_count != \
	mlx->game.coins || mlx->map.exit_count != 1)
	{
		mlx->error_trigger = 1;
		ft_printf("Error: Path\n");
		return (1);
	}
	return (0);
}

int	exit_game(t_mlx *mlx)
{
	if (mlx->map.char_map)
		free_str (mlx->map.char_map, mlx->map.lines);
	if (mlx->map.tableau_check)
		free_str (mlx->map.tableau_check, mlx->map.lines);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
	exit (1);
}

void	free_str(char **str, int length)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL && i < length)
	{
		free (str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}
