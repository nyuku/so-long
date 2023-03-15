/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:55:11 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/15 14:25:07 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h> // pour open

/*◇───────────────────────────────────────────────────────────────◇*\
                              MACRO key
\*◇───────────────────────────────────────────────────────────────◇*/
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGTH 124
# define KEY_ESC 53
# define X_BTN 17
/*◇───────────────────────────────────────────────────────────────◇*\
                              MACRO window
\*◇───────────────────────────────────────────────────────────────◇*/
# define ERROR 1
# define WIN_H 420
# define WIN_W 420
// # define IMG_PIXEL 32
/*◇───────────────────────────────────────────────────────────────◇*\
                              MACRO graphic
\*◇───────────────────────────────────────────────────────────────◇*/
# define WALL "./image/wall1.xpm"
# define MONSTER "./image/blop.xpm"



/*◇───────────────────────────────────────────────────────────────◇*\
                       Pour afficher image 
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_img
{
	void	*newimage_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int	img_width;//xmp
	int	img_height;//xpm
}	t_img;

/*◇───────────────────────────────────────────────────────────────◇*\
                       Pour afficher mlx 
\*◇───────────────────────────────────────────────────────────────◇*/

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window_ptr;
	char	*adress;
	t_img	img;
	int x;
	int y;

}	t_mlx;

/*◇───────────────────────────────────────────────────────────────◇*\
                       Pour map
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_map
{
	int	i;
	char **char_map;
	int lines;
	int colonn;
	int count_mouv;
}	t_map;




 //--------Key_hook.c------//
int	key_hook(int keycode, t_mlx *mlx);

 //--------info_map.c------//
int	count_colonn(char **str);//compte colonne map
void print_map(char **map, int line_count); //checker map, print str par str
char **ft_harvest_map(char *map_sample); // recolte la map en str
int ft_count_line_map(char *map_sample); // compte nombre de ligne dans la map
void	draw_personnage(void *mlx_ptr, void *window_ptr);
void erase_personnage(void *mlx_ptr, void *win_ptr);
int check_map_ext(char **argv);
int check_rectangle(int largeur, int longueur);
int check_wall_map(t_map *map);

# endif