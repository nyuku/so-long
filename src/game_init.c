/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:22:45 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/13 17:42:18 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void player_xy(t_mlx *mlx)//converti les coordonnées pour naviguer tableau
{
    mlx->p.player_i = mlx->x / 64;
    mlx->p.player_j = mlx->y / 64;
    printf("coucou je suis Corentin\n");

  
}
int creat_path_finding_check(t_mlx *mlx)
{
    int i;

    i = 0;
    mlx->map.tableau_check = malloc(sizeof(char *)*(mlx->map.lines));
	if (!mlx->map.tableau_check)
    	return(NULL);
    printf("coucou je suis Amandine\n");
    // while(i < mlx->map.lines)
	// {
	// 	bzero(mlx->map.tableau_check[i], mlx->map.colonn);
    //     i++;
	// }
    return(0);
}
