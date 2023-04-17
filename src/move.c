#include "../includes/so_long.h"
//str[y][x]

int check_up(t_mlx *mlx)
{
    if ((mlx->map.char_map[(mlx->y / 64) - 1][mlx->x / 64]) == '1')//empeche foncer mur, d'aller dans else
    {
        printf("mur haut\n");
    }
    else if (((mlx->map.char_map[(mlx->y / 64) - 1][mlx->x / 64]) == 'E') && (mlx->game.coins_count < mlx->game.coins))
    {
        printf("pas encore\n");
    }
    else
    {
        
		if((mlx->map.char_map[(mlx->y / 64) - 1][mlx->x / 64]) == 'C')
        {
            mlx->game.coins_count++;
            printf("tichiiin\n");
        }
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
        mlx->y -= mlx->jump;
		mlx->game.steps++;
		print_steps(mlx);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
        // move.up = 1;
        //printf("Up!\n");
        
        if(((mlx->x == mlx->exit_x) && (mlx->y == mlx->exit_y)) && (mlx->game.coins_count == mlx->game.coins))
        {
            mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
            printf("exiit!\n");
        }
    }
}

int check_down(t_mlx *mlx)
{
   if ((mlx->map.char_map[(mlx->y / 64) + 1][mlx->x / 64]) == '1')
    {
        printf("mur bas\n");
    }
	else if (((mlx->map.char_map[(mlx->y / 64) + 1][mlx->x / 64]) == 'E')&& (mlx->game.coins_count < mlx->game.coins))
    {
        printf("not yet\n");
    }
    else
    {
        if ((mlx->map.char_map[(mlx->y / 64) + 1][mlx->x / 64]) == 'C')
        {
            mlx->game.coins_count++;
            printf("tichiiin\n");
        }
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
        mlx->y += mlx->jump;
		mlx->game.steps++;
		print_steps(mlx);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x,mlx->y);	
        printf("Down!\n");
        if(((mlx->x == mlx->exit_x) && (mlx->y == mlx->exit_y))&& (mlx->game.coins_count == mlx->game.coins))
        {
            mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
            printf("exiit!\n");
        }
    }
}
int check_left(t_mlx *mlx)
{
   if ((mlx->map.char_map[mlx->y / 64][(mlx->x / 64) - 1]) == '1')
    {
        printf("mur gauche\n");
    }
	else if (((mlx->map.char_map[mlx->y / 64][(mlx->x / 64) - 1]) == 'E')&& (mlx->game.coins_count < mlx->game.coins))
    {
        printf("not yeeet\n");
    }
    else
    {
        if ((mlx->map.char_map[mlx->y / 64][(mlx->x / 64) - 1]) == 'C')
        {
            mlx->game.coins_count++;
            printf("tichiiin\n");
        }
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
        mlx->x -= mlx->jump;
		mlx->game.steps++;
		print_steps(mlx);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
        printf("Left!\n");
        if(((mlx->x == mlx->exit_x) && (mlx->y == mlx->exit_y))&& (mlx->game.coins_count == mlx->game.coins))
        {
            mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
            printf("exiit!\n");
        }
    }
}
int check_right(t_mlx *mlx)
{
   if ((mlx->map.char_map[mlx->y / 64][(mlx->x / 64) + 1]) == '1')
    {
        printf("mur droit\n");
    }
   else if (((mlx->map.char_map[mlx->y / 64][(mlx->x / 64) + 1]) == 'E')&& (mlx->game.coins_count < mlx->game.coins))
    {
        printf("naaaaa pas encore\n");
    }
    else
    {
        if ((mlx->map.char_map[mlx->y / 64][(mlx->x / 64) + 1]) == 'C')
        {
            mlx->game.coins_count++;
            printf("tichiiin\n");
        }
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.background_ptr, mlx->x, mlx->y);
        mlx->x += mlx->jump;
		mlx->game.steps++;
		print_steps(mlx);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window_ptr, mlx->decor.player_ptr, mlx->x, mlx->y);	
        printf("Right!\n");
        if(((mlx->x == mlx->exit_x) && (mlx->y == mlx->exit_y)) && (mlx->game.coins_count == mlx->game.coins))
        {
            mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window_ptr);
            printf("exiit!\n");
        }
	}
}