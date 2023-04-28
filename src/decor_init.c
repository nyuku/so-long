/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:20 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/28 18:05:32 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_decor_path(t_mlx *mlx)
{
	mlx->decor.p_path = "image/chat_chef.xpm";
	mlx->decor.wall_path = "image/buisson_fleurie.xpm";
	mlx->decor.background_path = "image/herbe.xpm";
	mlx->decor.check_path = "image/pomme.xpm";
	mlx->decor.exit_path = "image/four.xpm";
}

void	init_decor_ptr(t_mlx *mlx)
{
	mlx->decor.background_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	mlx->decor.background_path, &mlx->img.img_width, &mlx->img.img_height);
	mlx->decor.wall_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	mlx->decor.wall_path, &mlx->img.img_width, &mlx->img.img_height);
	mlx->decor.exit_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	mlx->decor.exit_path, &mlx->img.img_width, &mlx->img.img_height);
	mlx->decor.player_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	mlx->decor.p_path, &mlx->img.img_width, &mlx->img.img_height);
	mlx->decor.check_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	mlx->decor.check_path, &mlx->img.img_width, &mlx->img.img_height);
}

int	check_null_ptr(void *str)
{
	if (!str)
	{
		ft_printf("Error\n ptrmlx\n");
		return (1);
	}
	return (0);
}

int	check_ptr(t_mlx *mlx)
{
	if (check_null_ptr(mlx->decor.background_ptr) == 1)
		return (1);
	if (check_null_ptr(mlx->decor.wall_ptr) == 1)
		return (1);
	if (check_null_ptr(mlx->decor.exit_ptr) == 1)
		return (1);
	if (check_null_ptr(mlx->decor.player_ptr) == 1)
		return (1);
	if (check_null_ptr(mlx->decor.check_ptr) == 1)
		return (1);
	else
		return (0);
}
