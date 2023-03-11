/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:48:31 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/11 01:13:24 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

int	key_hook(int keycode, t_mlx *mlx) // notre fonction
{
	if (keycode == KEY_UP)
	{
		mlx->y -= 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Up!\n");
	}
	if (keycode == KEY_LEFT)
	{
		mlx->x -= 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Left!\n");
	}	
	if (keycode == KEY_DOWN)
	{
		mlx->y += 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Down!\n");
	}
	if (keycode == KEY_RIGTH)
	{
		mlx->x += 64;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->img.newimage_ptr, mlx->x, mlx->y);	
		printf("Right!\n");
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
		printf("shuting down!\n");
	}
	return (0);
}

int main(int argc, char **argv)
{
    int	fd;
    if (argc != 2)
    {
        ft_printf("Usage: ./map/ *.ber\n");
        return(NULL);
    }
    ft_printf("Launcher\n");
    ft_printf("Map selectionnée: %s\n", argv[1]);

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Fichier erroné\n");
		close (fd);
        return(NULL);
    }

	t_map	*map;
	map = get_map(argc, argv, map);
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
	
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.img.newimage_ptr, mlx.x, mlx.y);	
	mlx_key_hook(mlx.mlx_window_ptr, key_hook, &mlx);
	printf("oui\n");
	//test pour detruire image
	//mlx_destroy_image(mlx.mlx_window_ptr, mlx.img.newimage_ptr);
	printf("%d\n",mlx.x);
	printf("%d\n",mlx.y);
	mlx_loop(mlx.mlx_ptr);// a mettre a la fin pour boucler
	
	close (fd);
}

