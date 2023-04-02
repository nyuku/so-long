#include "../includes/so_long.h"
//str[y][x]

int check_up(t_mlx *mlx)
{
   if ((mlx->map.char_map[(mlx->y / 64) - 1][mlx->x / 64]) == '1')
    {
        printf("mur haut\n");
    }
    else
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
        mlx->y -= mlx->jump;
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
        // move.up = 1;
        printf("Up!\n");
    }
}

int check_down(t_mlx *mlx)
{
   if ((mlx->map.char_map[(mlx->y / 64) + 1][mlx->x / 64]) == '1')
    {
        printf("mur bas\n");
    }
    else
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
        mlx->y += mlx->jump;
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x,mlx->y);	
        printf("Down!\n");
    }
}
int check_left(t_mlx *mlx)
{
   if ((mlx->map.char_map[mlx->y / 64][(mlx->x / 64) - 1]) == '1')
    {
        printf("mur gauche\n");
    }
    else
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
        mlx->x -= mlx->jump;
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
        printf("Left!\n");
    }
}
int check_right(t_mlx *mlx)
{
   if ((mlx->map.char_map[mlx->y / 64][(mlx->x / 64) + 1]) == '1')
    {
        printf("mur droit\n");
    }
    else
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
        mlx->x += mlx->jump;
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
        printf("Right!\n");
}
}