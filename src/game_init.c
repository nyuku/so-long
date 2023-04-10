/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:22:45 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/10 11:49:16 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void player_xy(t_mlx *mlx, t_point p)//converti les coordonnées pour naviguer tableau
{
    p.player_i = mlx->x / 64;
    p.player_j = mlx->y / 64;
  
}

