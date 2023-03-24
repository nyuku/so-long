/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:20 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/24 14:39:28 by angnguye         ###   ########.fr       */
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
	
	//ptr pour xpm

	// decor->wall_right
	// decor->wall_up
	// decor->wall_down
}