/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:48:31 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/10 20:21:19 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

int	key_hook(int keycode, t_mlx *mlx) // notre fonction
{
	if (keycode == KEY_UP){
		mlx.x += 25;
		// mlx->y += 25;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Up!\n");
	}
	
	if (keycode == KEY_LFT)
		printf("Left!\n");
	if (keycode == KEY_DWN)
		printf("Down!\n");
	if (keycode == KEY_RGT)
		printf("Right!\n");
	return (0);
}

int main()
{
	t_mlx mlx; // on appelle la structure mlx

    char *image_path = "image/blop.xpm";
	// void *img;//xpm

	int	img_width;//xmp
	int	img_height;//xmp


    mlx.mlx_ptr = mlx_init();
	mlx.mlx_window_ptr = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "Test :3");
	
	mlx.img.newimage_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, image_path, &img_width, &img_height);
	if (!mlx.img.newimage_ptr)
	{
		ft_putstr("error file image\n");
		return(ERROR);
	}
	mlx.x = 255;
	mlx.y = 255;
	while (1)
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.img.newimage_ptr, mlx.x, mlx.y);	
		mlx_key_hook(mlx.mlx_window_ptr, key_hook, &mlx);
		printf("%d\n",mlx.x);
		printf("%d\n",mlx.y);
		mlx_loop(mlx.mlx_ptr);// a mettre a la fin pour boucler
	}
	
}

