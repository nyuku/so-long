/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:33:44 by angela            #+#    #+#             */
/*   Updated: 2023/03/16 19:50:49 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void draw_personnage(void *mlx_ptr, void *win_ptr)
// {
//     t_mlx mlx;
//     mlx_ptr = mlx.mlx_ptr;
//     win_ptr = mlx.mlx_window_ptr;
//     char *image_path = "image/blop.xpm";
//     int personnage_width;
//     int personnage_height;
//     //Chargement de l'image du personnage
//     void *img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, image_path, &personnage_width, &personnage_height);
//     mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, img_ptr, 10, 10);
// }
// void erase_personnage(void *mlx_ptr, void *win_ptr)
// {
//     t_mlx mlx;
//     mlx_clear_window(mlx.mlx_ptr, mlx.mlx_window_ptr);
// }

int	key_hook(int keycode, t_mlx *mlx) // notre fonction
{
    // erase_personnage(mlx->mlx_ptr, mlx->mlx_window_ptr);
    //map.count_mouv = 0;
	if (keycode == KEY_UP)
	{
		mlx->old_y = mlx->y;
		mlx->y -= mlx->move;
		//mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, "image/fond_bloc.xpm", 100, 100);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		
		printf("Up!\n");
       // map.count_mouv++;
	}
	if (keycode == KEY_LEFT)
	{
		mlx->old_x = mlx->x;
		mlx->x -= mlx->move;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		//mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, "image/fond_bloc.xpm", mlx->old_x, mlx->y);
		printf("Left!\n");
        //map.count_mouv++;
	}	
	if (keycode == KEY_DOWN)
	{
		mlx->old_y = mlx->y;
		mlx->y += mlx->move;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x,mlx->y);	
		//mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, "image/fond_bloc.xpm", mlx->x, mlx->old_y);
		printf("Down!\n");
        //map.count_mouv++;
	}
	if (keycode == KEY_RIGTH)
	{
		mlx->old_x = mlx->x;
		mlx->x += mlx->move;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		//mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, "image/fond_bloc.xpm", mlx->old_x, mlx->y);
		printf("Right!\n");
        //map.count_mouv++;
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
		printf("shuting down!\n");
        //map.count_mouv++;
	}
    // draw_personnage(mlx->mlx_ptr, mlx->mlx_window_ptr);
	return (0);
}