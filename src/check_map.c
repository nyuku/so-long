/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:19:52 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/23 00:24:35 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_ext(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		i++;
	}
	if ((argv[i - 1] == 'r') && (argv[i - 2] == 'e') && (argv[i - 3] == 'b'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	check_rectangle(char **str, int lines, int colonn)
{
	int		j;
	size_t	i;

	j = 0;
	i = ft_strlen(str[j]);
	while (j < lines)
	{	
		if (i == colonn + 1)
		{
			j++;
		}
		else
		{
			return (1);
		}
	}
	return (0);
}

int	check_one_player(t_mlx *mlx)
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
			if (mlx->map.char_map[j][i] == 'P')
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

int	check_wall_map(t_mlx *mlx)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < mlx->map.lines)
	{
		if ((mlx->map.char_map[0][j] != '1') || \
		(mlx->map.char_map[(mlx->map.lines) - 1][j] != '1'))
		{
			return (1);
		}
		if ((mlx->map.char_map[i][0] != '1') || \
		(mlx->map.char_map[i][mlx->map.colonn - 1] != '1'))
		{
			return (1);
		}
		j++;
		i++;
	}
	return (0);
}
