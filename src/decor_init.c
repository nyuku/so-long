/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:20 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/03 11:07:50 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void init_decor(t_mlx *mlx)
{
	//indique le chemin de l'image, pour la fonction xpm
	mlx->decor.p_path = "image/blop.xpm";
	mlx->decor.wall_path = "image/wall1.xpm";
	mlx->decor.background_path = "image/fond_bloc.xpm";
	mlx->decor.check_path = "image/check.xpm";
	mlx->decor.exit_path = "image/exit.xpm";
	
	//ptr pour xpm

	// decor->wall_right
	// decor->wall_up
	// decor->wall_down
}