/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:35 by angela            #+#    #+#             */
/*   Updated: 2023/04/10 11:53:12 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
int path_finding(t_point p,t_mlx *mlx)
{
    int item;
    int exit;
    char **tableau_check;

    item = 0;
    exit = 0;
    //on check case actuel 

    //player_xy(t_mlx *mlx, t_point p) faut mettre ici ou dans le so_long.c?

    tableau_check = malloc(sizeof(char *)*(mlx->map.lines));
	if (!tableau_check)
    	return(NULL);
        
    // -------check la case actuel-----//
    //permet de lancer l/algo
    //if wall and if visited
    if ((mlx->map.char_map[p.player_j][p.player_i] == '1') || \
        ((tableau_check[p.player_j][p.player_i]) == 'v'))
        return(1);
    path_finding((t_point){p.player_j-1,p.player_i}, mlx);
    path_finding((t_point){p.player_j+1,p.player_i}, mlx);
    path_finding((t_point){p.player_j,p.player_i-1}, mlx);
    path_finding((t_point){p.player_j,p.player_i+1}, mlx);   
    return(0);
}

