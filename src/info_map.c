/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:46:50 by angela            #+#    #+#             */
/*   Updated: 2023/03/15 14:25:04 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_colonn(char **str)//compte colonne map
{
	int i;
	i = 0;
	while(str[1][i]!= '\0')
	{
		i++;	
	}
	return(i-1);
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
int check_map_ext(char **argv)
{
	int i = 0;
	ft_printf("le nom du doc: %s\n", argv[1]);
	while(argv[1][i] != '\0')//pour aller a la fin du nom
	{
		i++;
	}
	ft_printf("index:%d\n",i);
	if ((argv[1][i-1] == 'r') && (argv[1][i-2] == 'e') && (argv[1][i-3] == 'b'))
	{
		ft_printf("yepiiiie, bon format de map\n");
        return(0);
	}
	else
	{
        ft_printf("bouhhhhhh\n");
        return(1);
    }
}
int check_rectangle(int largeur, int longueur)
{
    if (largeur != longueur)
    {
        ft_printf("c'est un rectangle\n");
        return(0);
    }
    else
    {
        ft_printf("carré!!nope");
        return(1);
    }
}
int check_wall_map(t_map *map,int i, int j)
int check_wall_map(t_map *map)
{
    int i = 0;
    int j = 0;

    // defini fin d'un bord
    while (i < map->lines)
    {
        // check horizontale
        if ((map->char_map[0][j] != 1) || (map->char_map[map->lines-1][j] != 1))
        {
            printf("mauvaise map\n");
            return 1;
        }

        // check vertical
        if ((map->char_map[i][0] != 1) || (map->char_map[i][map->colonn - 1] != 1))
        {
            printf("mauvaise map\n");
            return 1;
        }
        j++;
        i++;
    }

    printf("map valide\n");
    return 0;
}
/*-----------------------------------\*
         MAIN test les fonctions map
\*----------------------------------*/
//mettre la map apres ./so_long

// #include <stdio.h>
// int main(int argc, char **argv)
// {

// 	t_map map; // structure
    
// 	map.lines = ft_count_line_map(argv[1]);
// 	map.char_map = ft_harvest_map(argv[1]);//stock la str..?
// 	map.colonn = count_colonn(map.char_map);
    
//     //------TEST-----//
//     printf("structure line: %d\n",map.lines);
// 	printf("nombre de colonne struc %d\n", map.colonn);
// 	printf("%s\n, map.char_map");

//     //---Imprimer la map---//
//     print_map(argv[1], map.lines);

//     //--Fin du programme--//
//     ft_printf("End\n");

// 	return (0);
// }