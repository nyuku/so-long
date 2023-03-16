/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:19:20 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/16 17:47:37 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void init_decor(t_decor *decor, t_mlx *mlx, t_img *img)
{
	decor->wall_left =  mlx_xpm_file_to_image(mlx.mlx_ptr, "./image/wall1.xpm", &img.img_width, &img.img_height);
	// decor->wall_right
	// decor->wall_up
	// decor->wall_down
}