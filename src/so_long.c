/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:40:15 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/03 09:51:32 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	// t_img	img;
	t_mlx	mlx;
	int fd;
	// t_map	map;
	// t_decor decor;
	// t_move	*move;

	//------init move------//
	// move.up = 0;
	// move.down = 0;
	// move.right = 0;
	// move.left = 0;
	
	// mlx.decor.p_path = "image/blop.xpm";
	// mlx.decor.wall_path = "image/wall1.xpm";
	// mlx.decor.background_path = "image/fond_bloc.xpm";

	init_decor(&mlx);
	
	
	if (argc != 2)
    {
        ft_printf("error,chemin a mettre: ./map/ *.ber\n");
        return(NULL);
	}
    ft_printf("\ngoood! : \nMap selectionnée: %s\n", argv[1]);
	check_map_ext(argv[1]);
	
	

	//---- ouverture de la map ----//
	fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Fichier erroné\n");
		close (fd);
        return(NULL);
    }


	//------get info map -----//
	mlx.map.lines = ft_count_line_map(argv[1]);
	mlx.map.char_map = ft_harvest_map(argv[1]);//stock la str..?
	mlx.map.colonn = count_colonn(mlx.map.char_map);
	print_map(mlx.map.char_map, mlx.map.lines);
	ft_printf("map nombre de lignes: %d\n",mlx.map.lines);
	ft_printf("nombre de colonne map %d\n", mlx.map.colonn);
	check_rectangle(mlx.map.lines,mlx.map.colonn);
	check_wall_map(&mlx);
	//------- init MLX ------//
	mlx.win_height = 64 * mlx.map.lines;
	mlx.win_width = 64 * mlx.map.colonn;
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_window_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_width, mlx.win_height, "Test :3");

	//-------init_decor-charger image-----//;
	mlx.decor.background_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.background_path, &mlx.img.img_width, &mlx.img.img_height);
	mlx.decor.wall_ptr =  mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.wall_path, &mlx.img.img_width, &mlx.img.img_height);
	mlx.decor.player_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.p_path, &mlx.img.img_width, &mlx.img.img_height);//doit stocker width et height qq part (64)
	mlx.decor.check_ptr =  mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.check_path, &mlx.img.img_width, &mlx.img.img_height);
	if (!mlx.decor.player_ptr)
	{
		ft_putstr("error file image\n");
		return(ERROR);
	}
	
	//---position de l'image de notre perso sur la fenêtre, depart---//
	//mlx.x = 255;
	//mlx.y = 255;

	// mlx.old_x = 0;//init
	// mlx.old_y = 0;
	
	//----mettre image sur la fenêtre----//
	// mlx_loop_hook(mlx.mlx_window_ptr, render, &mlx);
	//mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.decor.wall_ptr, 100, 100);// mur
	render_wall_map(&mlx);
	//mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.decor.background_ptr, 300, 300);
	//-----------player begin-------------//
	//mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.decor.player_ptr, mlx.x, mlx.y);//affiche le point depart
	render_player(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.decor.check_ptr, 0, 128);
	//---mouvements---//
	mlx.jump = 64;
	mlx_key_hook(mlx.mlx_window_ptr, key_hook, &mlx);//input clavier
	//mlx_loop_hook(mlx.mlx_window_ptr, render,&mlx );//rhaaa...
	mlx_loop(mlx.mlx_ptr);// a mettre a la fin pour boucler
	
	close (fd);
}