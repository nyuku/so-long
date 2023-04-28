/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:40:15 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/28 18:04:16 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memset(void *p, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (p);
}

int	openfile(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Fichier erroné\n");
		close (fd);
		return (0);
	}
	else
		close (fd);
	return (1);
}

static int	my_red_cross(void *mydata)
{
	(void) mydata;
	ft_printf("\n%s\nUn pti courant d'air gênant?\n", DECO);
	ft_printf("Vous avez bien fait de fermer la fenêtre!, Fufufu\n%s\n", DECO);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	if (argc != 2 || openfile(argv[1]) == 0)
		exit(1);
	if (!start_game(argv[1], &mlx))
		return (exit_game(&mlx));
	if (mlx.error_trigger == 1)
		return (exit_game(&mlx));
	path_finding(mlx.p, &mlx);
	if (check_error_game(argc, &mlx) != 0)
		return (exit_game(&mlx));
	mlx_key_hook(mlx.mlx_window_ptr, key_hook, &mlx);
	mlx_hook(mlx.mlx_window_ptr, 17, 0, &my_red_cross, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
