/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:40:15 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/03 15:28:25 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_mlx	mlx;
	int fd;
	init_decor(&mlx);
	
	if (argc != 2)
    {
        ft_printf("error,chemin a mettre: ./map/ *.ber\n");
        return(NULL);
	}
	
	//---- ouverture de la map - check ----//
	check_map_ext(argv[1]);
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
	check_one_exit(&mlx);

	//------- init MLX ------//
	mlx.win_height = 64 * mlx.map.lines;
	mlx.win_width = 64 * mlx.map.colonn;
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_window_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_width, mlx.win_height, "Test :3");

	//-------init_decor-charger image-----//;
	mlx.decor.background_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.background_path, &mlx.img.img_width, &mlx.img.img_height);
	mlx.decor.wall_ptr =  mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.wall_path, &mlx.img.img_width, &mlx.img.img_height);
	mlx.decor.exit_ptr =  mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.exit_path, &mlx.img.img_width, &mlx.img.img_height);
	mlx.decor.player_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.p_path, &mlx.img.img_width, &mlx.img.img_height);//doit stocker width et height qq part (64)
	//mlx.decor.check_ptr =  mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.decor.check_path, &mlx.img.img_width, &mlx.img.img_height);
	if (!mlx.decor.player_ptr)
	{
		ft_putstr("error file image\n");
		return(ERROR);
	}
	
	render_wall_map(&mlx);
	render_player(&mlx);//depart
	render_exit(&mlx);

	//---init mouvements---//
	mlx.jump = 64;
	
	mlx_key_hook(mlx.mlx_window_ptr, key_hook, &mlx);//input clavier

	mlx_loop(mlx.mlx_ptr);// a mettre a la fin pour boucler
	
	close (fd);
}