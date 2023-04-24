/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:46:50 by angela            #+#    #+#             */
/*   Updated: 2023/04/23 00:22:30 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_colonn(char **str)
{
	int	i;

	i = 0;
	while (str[1][i] != '\0')
	{
		i++;
	}
	return (i - 1);
}

void	print_map(char **map, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**ft_harvest_map(char *map_sample, t_mlx *mlx)

{
	int		fd;
	int		line_map;
	char	**tableau_stock;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_sample, O_RDONLY);
	line_map = mlx->map.lines;
	tableau_stock = malloc(sizeof(char *) * (line_map + 1));
	if (!tableau_stock)
		return (NULL);
	while (i < line_map)
	{
		line = get_next_line(fd);
		tableau_stock[i] = ft_strdup(line);
		free (line);
		i++;
	}
	close (fd);
	return (tableau_stock);
}

int	ft_count_line_map(char *map_sample, t_mlx *mlx)
{
	int		fd;
	int		count;
	char	*gnl_return;

	count = 0;
	fd = open(map_sample, O_RDONLY);
	gnl_return = get_next_line(fd);
	while (gnl_return)
	{
		free(gnl_return);
		gnl_return = get_next_line(fd);
		count++;
	}
	if (count < 3 || gnl_return == "\0")
	{
		error_msg(ERROR_EMPTY, mlx);
		return (0);
	}
	close (fd);
	return (count);
}

int	count_coins(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < mlx->map.lines)
	{
		while (i < mlx->map.colonn)
		{
			if (mlx->map.char_map[j][i] == 'C')
				mlx->game.coins++;
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}
