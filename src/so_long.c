/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:40:15 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/18 19:57:11 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_img	img;
	t_mlx	mlx;
	t_map	map;
	t_decor decor;
	t_move	*move;

	//------init move------//
	// move.up = 0;
	// move.down = 0;
	// move.right = 0;
	// move.left = 0;

	char *image_path = "image/blop.xpm";
	char *wall_path = "image/wall1.xpm";
	char *background_path = "image/fond_bloc.xpm";
	int fd;
	
	if (argc != 2)
    {
        ft_printf("error,chemin a mettre: ./map/ *.ber\n");
        return(NULL);
	}
    ft_printf("\ngoood \nMap selectionnée: %s\n", argv[1]);

	//---- ouverture de la map ----//
	fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Fichier erroné\n");
		close (fd);
        return(NULL);
    }

	//------get info map -----//
	map.lines = ft_count_line_map(argv[1]);
	map.char_map = ft_harvest_map(argv[1]);//stock la str..?
	map.colonn = count_colonn(map.char_map);
	print_map(map.char_map, map.lines);
	ft_printf("map line: %d\n",map.lines);
	ft_printf("nombre de colonne map %d\n", map.colonn);

	//------- init MLX ------//
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_window_ptr = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "Test :3");

	//-------init_decor-charger image-----//;
	mlx.decor.background = mlx_xpm_file_to_image(mlx.mlx_ptr, background_path, &img.img_width, &img.img_height);
	mlx.decor.wall_left =  mlx_xpm_file_to_image(mlx.mlx_ptr, wall_path, &img.img_width, &img.img_height);
	mlx.img.newimage_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, image_path, &img.img_width, &img.img_height);//doit stocker width et height qq part (64)

	if (!mlx.img.newimage_ptr)
	{
		ft_putstr("error file image\n");
		return(ERROR);
	}
	
	//---position de l'image de notre perso sur la fenêtre, depart---//
	mlx.x = 255;
	mlx.y = 255;

	mlx.old_x = 0;//init
	mlx.old_y = 0;
	
	//----mettre image sur la fenêtre----//
	// mlx_loop_hook(mlx.mlx_window_ptr, render, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.decor.wall_left, 100, 100);// mur
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.decor.background, 300, 300);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.img.newimage_ptr, mlx.x, mlx.y);//affiche le point depart
	
	//---mouvements---//
	mlx.jump = 64;
	mlx_key_hook(mlx.mlx_window_ptr, key_hook, &mlx);//input clavier
	//mlx_loop_hook(mlx.mlx_window_ptr, render,&mlx );//rhaaa...
	mlx_loop(mlx.mlx_ptr);// a mettre a la fin pour boucler
	
	close (fd);
}