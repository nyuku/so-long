/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_PEC01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:23:45 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/23 00:25:16 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_one_exit(t_mlx *mlx)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while ((j < (mlx->map.lines)))
	{
		while (i < mlx->map.colonn)
		{
			if (mlx->map.char_map[j][i] == 'E')
				count++;
			i++;
		}
		j++;
		i = 0;
	}
	if (count != 1)
	{
		return (1);
	}
	else
		return (0);
}

int	check_one_coin(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((j < (mlx->map.lines)))
	{
		while (i < mlx->map.colonn)
		{
			if (mlx->map.char_map[j][i] == 'C')
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	check_only_pec01(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < mlx->map.lines)
	{
		while (i < mlx->map.colonn)
		{
			if ((mlx->map.char_map[j][i] == 'P') || \
			(mlx->map.char_map[j][i] == 'E') || \
			(mlx->map.char_map[j][i] == 'C') || \
			(mlx->map.char_map[j][i] == '0') || \
			(mlx->map.char_map[j][i] == '1'))
				i++;
			else
			{
				return (1);
			}
		}
		j++;
		i = 0;
	}
	return (0);
}
