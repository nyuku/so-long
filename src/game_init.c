/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:22:45 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/17 16:28:26 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void player_xy(t_mlx *mlx)//converti les coordonnées pour naviguer tableau
{
    mlx->p.player_i = mlx->x / 64;
    mlx->p.player_j = mlx->y / 64;
    printf("coordonée du player :coordonnée i : %zu\n coordonnée j : %zu\n",mlx->p.player_i, mlx->p.player_j );


}
int creat_path_finding_check(t_mlx *mlx)
{
    int i;

    mlx->map.tableau_check = malloc(sizeof(char *)*(mlx->map.lines));
	if (!mlx->map.tableau_check)
    	return(0);
    printf("coucou je suis Amandine\n");

	i = 0;
     while(i < mlx->map.lines)
	 {
	 	mlx->map.tableau_check[i] = malloc( sizeof(char) * mlx->map.colonn);
		 i++;
	 }
    return(0);
}
