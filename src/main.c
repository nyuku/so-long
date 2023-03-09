/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:48:31 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/09 23:50:45 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

int main()
{
	t_mlx mlx; // on appelle la structure
	// printf("Hello World");

	
	// void *mlx_ptr;
	// void *mlx_window_ptr;
    char *image_path = "image/blop.xpm";
	void *img;//xpm

	int	img_width;//xmp
	int	img_height;//xmp


    mlx.mlx_ptr = mlx_init();
	mlx.mlx_window_ptr = mlx_new_window(mlx.mlx_ptr, 750, 600, "Test :3");
	
	// my_mlx_pixel_put(&mlx, 5, 5,0x00FF00FF );// met un pixel a 5x5y turquoise
	mlx.newimage_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, image_path, &img_width, &img_height);
	if (!mlx.newimage_ptr)
	{
		ft_putstr("error file image\n");
		return(1);
	}
	
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.newimage_ptr, 250, 250);
	mlx_loop(mlx.mlx_ptr);// a mettre a la fin pour boucler

}
// void	img_pix_put(t_mlx *img, int x, int y, int color)
// {
// 	char    *pixel;

//     pixel = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
// 	*(int *)pixel = color;
// }

//fonction bricole
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->adress + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

