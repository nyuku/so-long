/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:48:31 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/04 23:32:26 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int	fd;
		
	if (argc == 2) // s'il y a 1 argument
	{
		if (fd < 0)
		{
			ft_printf("Fichier erroné");
			return(1);
		}
		else
			fd = open(&argv[1], O_RDONLY);
	}
	//soucis avec le fichier
	
	close (fd);
}

int count_line_map(char **map_sample) //pourquoi en tableau...?
{
	int fd; //on a besoin d'ouvrir la map pour lire avec gnl
	int count;
	char *gnl_return;// stock le retour de gnl

	count = 0;
	fd = open(*map_sample, O_RDONLY);// on deference pour utiliser map
	gnl_return = get_next_line(fd);//pour la first, rentrer boucle

	while(gnl_return) // car sera == null a la fin
	{
		free(gnl_return); // touche statik, osef on a deja check. propre pour le prochain tour
		gnl_return = get_next_line(fd);
		count++;
	}
	close (fd);
	return(count);
}

int	harvest_map(char **map_sample)//recolte
{
	int fd;
	int line_map;
	char *tableau_stock;
	char *line; //récupérer ce qu'a lu gnl
	int i; //index tableau

	fd = open(*map_sample, O_RDONLY);
	line_map = count_line_map(map_sample);//encore un *?
	
	// if (line_map == 0)//si il y a aucune ligne. map vide
	// {
	// 	ft_printf("Error,\n______\nempty map\n");
	// 	return (-1);
	// }
	tableau_stock = malloc(sizeof(char *)*(line_map));//tableau simple
	if (!tableau_stock)
		return(0);
	while(i < line_map)
	{
		line = get_next_line(fd);//faut bien stocker qq part le contenu lu
		tableau_stock[i] = ft_strdup(line); //duplique la line dans le tableau
		free (line);//tout ce qui touche gnl...free pour remettre neuf
	}
	close (fd);
	return (0);
}

// #include "../lib/so_long.h"
// #include <stdio.h>

// int main()
// {
// 	printf("Hello World");
// 	void *mlx;
// 	void *mlx_window;
    
//     mlx = mlx_init();
// 	mlx_window = mlx_new_window(mlx, 1920, 1080, "Test :3");
// 	mlx_loop(mlx);
// 	return(0);
// }