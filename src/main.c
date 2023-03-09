/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:48:31 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/09 19:39:41 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

int main()
{
	t_mlx mlx; // on appelle la structure
	// printf("Hello World");
	void *mlx_ptr;
	void *mlx_window_ptr;
    char *image_path;//xmp
	void *img;//xpm

	int	img_width = 1920;//xmp
	int	img_height = 1080;//xmp

	image_path = "../image/coco.xmp";

    mlx_ptr = mlx_init();
	mlx_window_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Test :3");
	mlx.newimage_ptr = mlx_new_image(mlx_ptr, 1920, 1080);
	mlx.adress = mlx_get_data_addr(mlx.newimage_ptr, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	
	// my_mlx_pixel_put(&mlx, 5, 5,0x00FF00FF );// met un pixel a 5x5y turquoise
	img = mlx_xpm_file_to_image(mlx_ptr,image_path, &img_width, img_height);

	mlx_put_image_to_window(mlx_ptr, mlx_window_ptr,mlx.newimage_ptr, 0, 0);
	mlx_loop(mlx_ptr);// a mettre a la fin pour boucler
	
	
	

}

//fonction bricole
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->adress + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

