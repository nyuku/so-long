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

#include "../includes/so_long.h"

int count_line_map(char *map_sample); //pourquoi en tableau...?
void print_map(char **map, int line_count);
char **harvest_map(char *map_sample);

int main(int argc, char **argv)
{
    int	fd;
    int line_count;


    if (argc != 2)
    {
        ft_printf("Usage: ./so_long map/*.ber\n");
        return(1);
    }
    ft_printf("Launcher\n");
    ft_printf("Map selectionnée: %s\n", argv[1]);

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Fichier erroné\n");
        return(1);
    }
    line_count = count_line_map(argv[1]);

    //
    char **map;
    map = harvest_map(argv[1]);
    //
    print_map(map, line_count);
    ft_printf("End\n");
    close (fd);
}

void print_map(char **map, int line_count)
{
    int i;
    i = 0;
    while (i < line_count)
    {
        ft_printf("%s", map[i]);
        i++;
    }
}

int count_line_map(char *map_sample) //pourquoi en tableau...?
{
	int fd; //on a besoin d'ouvrir la map pour lire avec gnl
	int count;
	char *gnl_return;// stock le retour de gnl

	count = 0;
	fd = open(map_sample, O_RDONLY);// on deference pour utiliser map
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

char **harvest_map(char *map_sample)
{
	int fd;
	int line_map;
	char **tableau_stock;
	char *line; //récupérer ce qu'a lu gnl
	int i; //index tableau

	fd = open(map_sample, O_RDONLY);
	line_map = count_line_map(map_sample);

	tableau_stock = malloc(sizeof(char *)*(line_map));
	if (!tableau_stock)
		return(NULL);
	while(i < line_map)
	{
		line = get_next_line(fd);//faut bien stocker qq part le contenu lu
		tableau_stock[i] = ft_strdup(line); //duplique la line dans le tableau
		free (line);//tout ce qui touche gnl...free pour remettre neuf
        i++;
	}
	close (fd);
	return (tableau_stock);
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