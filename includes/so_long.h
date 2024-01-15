/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:55:11 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/06 12:58:51 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

/*◇───────────────────────────────────────────────────────────────◇*\
							  MACRO key
\*◇───────────────────────────────────────────────────────────────◇*/

# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53
# define JUMP 64
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
/*◇───────────────────────────────────────────────────────────────◇*\
 *  MACRO ERROR
\*◇───────────────────────────────────────────────────────────────◇*/
# define ERROR_EXT "Bad hair day, Mauvaise extension"
# define ERROR_PEC01 "Puni! Caractères non autorisés"
# define ERROR_RECTANGLE "Ceci n'est pas un rectangle"
# define ERROR_WALL "La carte peut pas faire dodo, elle est mal bordée"
# define ERROR_EXIT "C'est par où la sortie?"
# define ERROR_PLAYER "C'est un jeu monoplace!"
# define ERROR_COINS "Picsou devait passer"
# define ERROR_EMPTY "Fichier vide!"
# define DECO "\n*──────────────────────────────────────────────────────*\n"
# define MIAM "Miam! La meilleur tarte aux pommes!\n"
# define MAMI "              Mamie peut aller se gratter\n\n"
# define MERCI "              Merci d'avoir joué!"
# define SPACE "              "

typedef struct s_point
{
	size_t	player_j;
	size_t	player_i;
}				t_point;

typedef struct s_game
{
	int		exit;
	int		player;
	int		coins;
	int		coins_count;
	int		coins_path_count;
	int		steps;
	int		player_i;
	int		player_j;
}				t_game;

typedef struct s_map
{
	char	**char_map;
	char	**tableau_check;
	int		lines;
	int		colonn;
	int		exit_count;
}				t_map;

/*◇───────────────────────────────────────────────────────────────◇*
* Pour afficher image
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_img
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_decor
{
	void	*wall_left;
	char	*background_path;
	char	*p_path;
	char	*wall_path;
	char	*check_path;
	char	*exit_path;
	void	*background_ptr;
	void	*wall_ptr;
	void	*player_ptr;
	void	*check_ptr;
	void	*exit_ptr;
}			t_decor;
/*◇───────────────────────────────────────────────────────────────◇*\
* 	Pour afficher mlx
\*◇───────────────────────────────────────────────────────────────◇*/

typedef struct s_mlx
{
	t_decor	decor;
	t_img	img;
	t_map	map;
	t_game	game;
	t_point	p;
	int		win_height;
	int		win_width;
	void	*mlx_ptr;
	void	*mlx_window_ptr;
	char	*adress;
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
	int		jump;
	int		error_trigger;
}			t_mlx;

//---------so_long.c-----//
int		openfile(char *s);
//--------error.c------//
int		check_error_map(char *str, t_mlx *mlx);
int		error_msg(char *str, t_mlx *mlx);
int		check_error_game(int a, t_mlx *mlx);
void	free_str(char **str, int length);
int		exit_game(t_mlx *mlx);
//--------path_finding.c------//
int		path_finding(t_point p, t_mlx *mlx);
void	render_background(t_mlx *mlx);
void	render_all(t_mlx *mlx);
void	print_steps(t_mlx *mlx);
//--------game_init.c------//
void	player_xy(t_mlx *mlx);
int		creat_path_finding_check(t_mlx *mlx);
int		start_init(char *str, t_mlx *mlx);
int		start_game(char *str, t_mlx *mlx);
//--------Key_hook.c------//
int		key_hook(int keycode, t_mlx *mlx);
//--------info_map.c------//
int		count_colonn(char **str);
void	print_map(char **map, int line_count);
char	**ft_harvest_map(char *map_sample, t_mlx *mlx);
int		ft_count_line_map(char *map_sample, t_mlx *mlx);
int		count_coins(t_mlx *mlx);
//----------check_map_pec01-------------//
int		check_only_pec01(t_mlx *mlx);
int		check_one_exit(t_mlx *mlx);
//------------Check -------------//
int		check_map_ext(char *argv);
int		check_rectangle(char **str, int largeur, int longueur);
int		check_wall_map(t_mlx *mlx);
//------move.c-------------//
void	put_and_move_player(t_mlx *mlx, int move_j, int move_i);
int		check_touch_coins(t_mlx *mlx, int move_j, int move_i);
int	check_touch_player(t_mlx *mlx, int move_j, int move_i);

int		check_one_coin(t_mlx *mlx);
int		check_one_player(t_mlx *mlx);
//-------- render -----------//
int		render_exit(t_mlx *mlx);
void	render_wall_map(t_mlx *mlx);
int		render_player(t_mlx *mlx);
void	render_coins(t_mlx *mlx);
//--------decor_init.c------//
void	init_decor_path(t_mlx *mlx);
int		check_null_ptr(void *str);
int		check_ptr(t_mlx *mlx);
void	init_decor_ptr(t_mlx *mlx);

#endif