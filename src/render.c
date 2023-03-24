/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:07:59 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/24 16:35:45 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

	void render_wall_map(t_mlx *mlx)
	{
		int i;
		int j;

		i = 0;
		j = 0;
		while((j < (mlx->map.lines) /*i < mlx->map.colonn*/))//fin du tableau
		{
			while(i < mlx->map.colonn /*j < mlx->map.lines*/)
			{
				if(mlx->map.char_map[j][i] == '1')
				{
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.wall_ptr, (i * 64), (j * 64));
					printf("ploooop\n");
				}
				i++;
			}
			j++;
			i = 0;

		}
		
	}
	