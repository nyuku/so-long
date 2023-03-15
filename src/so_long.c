/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:40:15 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/15 14:25:11 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_img	img;
	t_mlx	mlx;
	t_map	map;
	char *image_path = "image/blop.xpm";
	int fd;
	
	if (argc != 2)
    {
        ft_printf("chemin a mettre: ./map/ *.ber\n");
        return(NULL);
	}
    ft_printf("Map selectionnée: %s\n", argv[1]);

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

	//ft_printf("la map\n%s\n, map.char_map");
	//------- MLX ------//
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_window_ptr = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "Test :3");
	//--charge image--//
	//!!mlx.img.newimage_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, image_path, &img.img_width, &img.img_height);//doit stocker width et height qq part (64)
	//!!mlx.img.newimage_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, ./image/wall1.xpm, &img.img_width, &img.img_height);
	if (!mlx.img.newimage_ptr)
	{
		ft_putstr("error file image\n");
		return(ERROR);
	}
	//---position de l'image sur la fenêtre---//
	mlx.x = 255;
	mlx.y = 255;

	//----mettre image sur la fenêtre----//
	
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window_ptr, mlx.img.newimage_ptr, mlx.x, mlx.y);	
	
	//---mouvements---//
	mlx_key_hook(mlx.mlx_window_ptr, key_hook, &mlx);
	
	mlx_loop(mlx.mlx_ptr);// a mettre a la fin pour boucler
	
	close (fd);
}