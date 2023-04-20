/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:35 by angela            #+#    #+#             */
/*   Updated: 2023/04/19 12:45:38 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
//faut init tableau_check ailleirs et les compteurs pour exit et item
int path_finding(t_point p,t_mlx *mlx)//entré coodonné model
{    
    // -------check la case actuel-----//
    //permet de lancer l/algo
    //if wall and if visited

    if((mlx->map.char_map[p.player_j][p.player_i]) == '1' || (mlx->map.tableau_check[p.player_j][p.player_i]) == 'v')
    {
        printf("stop\n");
        return(1);
    }
	printf("after check\n");
	mlx->map.tableau_check[p.player_j][p.player_i] = 'v';// marqueur
	if ((mlx->map.char_map[p.player_j][p.player_i]) == 'E')
	{
		printf("Exit\n");
		mlx->map.exit_count = 1;
	}

	else if ((mlx->map.char_map[p.player_j][p.player_i]) == 'C')
	{
		// printf("p.player_j: %d | p.player_i: %d \n", p.player_j, p.player_i);
		mlx->map.coins_count++;
	}
	// printf("p.player_j: %d | p.player_i: %d \n", p.player_j, p.player_i);
	path_finding((t_point){p.player_j-1,p.player_i}, mlx);
	path_finding((t_point){p.player_j+1,p.player_i}, mlx);
	path_finding((t_point){p.player_j,p.player_i-1}, mlx);
	path_finding((t_point){p.player_j,p.player_i+1}, mlx);
//	printf("End check_path\n");

	return(0);

}

