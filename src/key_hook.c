/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:33:44 by angela            #+#    #+#             */
/*   Updated: 2023/03/15 14:25:00 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void draw_personnage(void *mlx_ptr, void *win_ptr)
{
    t_mlx mlx;
    mlx_ptr = mlx.mlx_ptr;
    win_ptr = mlx.mlx_window_ptr;
    char *image_path = "image/blop.xpm";
    int personnage_width;
    int personnage_height;
    //Chargement de l'image du personnage
    void *img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, image_path, &personnage_width, &personnage_height);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, img_ptr, 10, 10);
}
void erase_personnage(void *mlx_ptr, void *win_ptr)
{
    t_mlx mlx;
    mlx_clear_window(mlx.mlx_ptr, mlx.mlx_window_ptr);
}

int	key_hook(int keycode, t_mlx *mlx) // notre fonction
{
    erase_personnage(mlx->mlx_ptr, mlx->mlx_window_ptr);
    //map.count_mouv = 0;
	if (keycode == KEY_UP)
	{
		mlx->y -= 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Up!\n");
       // map.count_mouv++;
	}
	if (keycode == KEY_LEFT)
	{
		mlx->x -= 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Left!\n");
        //map.count_mouv++;
	}	
	if (keycode == KEY_DOWN)
	{
		mlx->y += 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Down!\n");
        //map.count_mouv++;
	}
	if (keycode == KEY_RIGTH)
	{
		mlx->x += 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Right!\n");
        //map.count_mouv++;
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
		printf("shuting down!\n");
        //map.count_mouv++;
	}
    draw_personnage(mlx->mlx_ptr, mlx->mlx_window_ptr);
	return (0);
}