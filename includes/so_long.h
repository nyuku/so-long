/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:55:11 by angnguye          #+#    #+#             */
/*   Updated: 2023/03/23 23:06:28 by angnguye         ###   ########.fr       */
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
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_r 82
# define X_BTN 17
/*◇───────────────────────────────────────────────────────────────◇*\
                              MACRO window
\*◇───────────────────────────────────────────────────────────────◇*/
# define ERROR 1
# define WIN_H 383
# define WIN_W 511
// # define IMG_PIXEL 32
/*◇───────────────────────────────────────────────────────────────◇*\
                              MACRO graphic
\*◇───────────────────────────────────────────────────────────────◇*/
# define WALL "./image/wall1.xpm"
# define MONSTER "./image/blop.xpm"

/*◇───────────────────────────────────────────────────────────────◇*\
                          	   Move
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_move
{
	int up;
	int down;
	int right;
	int left;
}	t_move;
/*◇───────────────────────────────────────────────────────────────◇*\
                          	   Game
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_game
{
	int	loot;
	int	exit;
	int player;
	int moves;
	
	
} t_game;

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

/*◇───────────────────────────────────────────────────────────────◇*\
                       Pour afficher image 
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_img
{
	//void	*newimage_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int	img_width;//xmp
	int	img_height;//xpm
}	t_img;

typedef struct s_decor
{
	//----path----//
	void *wall_left;
	char *background_path;
	char *p_path;
	char *wall_path;
	//----ptr-----//
	void *background_ptr;
	void *wall_ptr;
	void *player_ptr;
	// void *wall_right;
	// void *wall_up;
	// void *wall_down;
}	t_decor;


/*◇───────────────────────────────────────────────────────────────◇*\
                       Pour afficher mlx 
\*◇───────────────────────────────────────────────────────────────◇*/

typedef struct s_mlx
{
	t_decor	decor;
	t_img	img;
	t_move	move;
	t_map	map;
	//t_move	jump;
	int	win_height;
	int	win_width;
	void	*mlx_ptr;
	void	*mlx_window_ptr;
	char	*adress;
	
	int x;
	int y;
	int old_x;
	int old_y;
	int jump;


}	t_mlx;

 //--------Key_hook.c------//
int	key_hook(int keycode, t_mlx *mlx);

//--------loop_hook------//
//int render(t_mlx *mlx);

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
void render_wall_map(t_mlx *mlx);

 //--------decor_init.c------//
void init_decor(t_mlx *mlx);

# endif