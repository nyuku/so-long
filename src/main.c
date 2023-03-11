/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:06:28 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/11 01:13:39 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
int ft_count_line_map(char *map_sample);
void print_map(char **map, int line_count);
char **ft_harvest_map(char *map_sample);
int	count_colonn(char **str);

t_map *get_map(int argc, char **argv, t_map map)
{
	
    map.i = 0;
	map.lines = ft_count_line_map(argv[1]);
	map.char_map = ft_harvest_map(argv[1]);
	printf("structure line: %d\n",map.lines);
	map.colonn = count_colonn(map.char_map);
	printf("nombre de colonne struc %d\n", map.colonn);
    // printf("%d\n", map.i);
	// printf("%s\n, map.char_map");

    // Imprimer la map
    //print_map(mapu, line_count);

    // Fin du programme
    ft_printf("End\n");

	return (&map);
}

void print_map(char **map, int line_count) //checker map, print str par str
{
    int i;
    i = 0;
    while (i < line_count)
    {
        ft_printf("%s", map[i]);
        i++;
    }
}

int ft_count_line_map(char *map_sample) // compte nombre de ligne dans la map
{
	int fd;
	int count;
	char *gnl_return;

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

char **ft_harvest_map(char *map_sample) // recolte la map en str
{
	int fd;
	int line_map;
	char **tableau_stock;
	char *line; //récupérer ce qu'a lu gnl
	int i; //index tableau

	fd = open(map_sample, O_RDONLY);
	line_map = ft_count_line_map(map_sample);

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

int	count_colonn(char **str)
{
	int i;
	i = 0;
	while(str[1][i]!= '\0')
	{
		i++;	
	}
	return(i-1);
}