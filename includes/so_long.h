/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:55:11 by angnguye          #+#    #+#             */
/*   Updated: 2023/04/10 11:48:15 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h> // pour open
#include <stdlib.h> // exit

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

// # define IMG_PIXEL 32
/*◇───────────────────────────────────────────────────────────────◇*\
                        Coordonnées finding_path
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_point {
	size_t	player_j;
	size_t	player_i;
}				t_point;
/*◇───────────────────────────────────────────────────────────────◇*\
                          	   Game
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_game
{
	int	exit;
	int player;
	int coins;
	int coins_count;
	int steps;
	int player_i;
	int player_j;
	
	
} t_game;

/*◇───────────────────────────────────────────────────────────────◇*\
                       Pour map
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_map
{
	char **char_map;
	int lines;
	int colonn;
	
}	t_map;

/*◇───────────────────────────────────────────────────────────────◇*\
                       Pour afficher image 
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_img
{
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
	char *check_path;
	char *exit_path;
	
	//----ptr-----//
	void *background_ptr;
	void *wall_ptr;
	void *player_ptr;
	void *check_ptr;
	void *exit_ptr;

}	t_decor;


/*◇───────────────────────────────────────────────────────────────◇*\
                       Pour afficher mlx 
\*◇───────────────────────────────────────────────────────────────◇*/

typedef struct s_mlx
{
	t_decor	decor;
	t_img	img;
	t_map	map;
	t_game	game;
	t_point	p;
	int	win_height;
	int	win_width;
	void	*mlx_ptr;
	void	*mlx_window_ptr;
	char	*adress;
	
	int x;
	int y;
	int exit_x;
	int exit_y;
	int jump;


}	t_mlx;


 //--------game_init.c------//
void player_xy(t_mlx *mlx);
 //--------Key_hook.c------//
int	key_hook(int keycode, t_mlx *mlx);

//--------loop_hook------//
//int render(t_mlx *mlx);

 //--------info_map.c------//
int	count_colonn(char **str);//compte colonne map
void print_map(char **map, int line_count); //checker map, print str par str
char **ft_harvest_map(char *map_sample); // recolte la map en str
int ft_count_line_map(char *map_sample); // compte nombre de ligne dans la map
int count_coins(t_mlx *mlx);
int check_only_PEC01(t_mlx *mlx);
//------------Check -------------//
int check_map_ext(char *argv);
int check_rectangle(int largeur, int longueur);
int check_wall_map(t_mlx *mlx);

int check_up(t_mlx *mlx);
int check_down(t_mlx *mlx);
int check_right(t_mlx *mlx);
int check_left(t_mlx *mlx);

int check_one_exit(t_mlx *mlx);
int	check_one_coin(t_mlx *mlx);
int check_one_player(t_mlx *mlx);

//-------- render -----------//
int render_exit(t_mlx *mlx);
void render_wall_map(t_mlx *mlx);
int render_player(t_mlx *mlx);
void	render_coins(t_mlx *mlx);
void	print_steps(t_mlx *mlx);

 //--------decor_init.c------//
void init_decor(t_mlx *mlx);

# endif