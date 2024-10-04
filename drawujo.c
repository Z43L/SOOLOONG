#include "so_long.h"

void	ft_draw_player(lienzo *lienzo)
{
    mlx_put_image_to_window(lienzo->mlx, lienzo->mlx_win,
        lienzo->player->sprites[0], lienzo->player->y * TILE_SIZE, lienzo->player->x * TILE_SIZE);
}

void	ft_draw_collect_ghost(lienzo *lienzo)
{
    mlx_put_image_to_window(lienzo->mlx, lienzo->mlx_win,
        lienzo->ghost->sprite, lienzo->ghost->y * TILE_SIZE, lienzo->ghost->x * TILE_SIZE);
}


void	ft_draw_collect_exit(lienzo *data)
{
    int i;
    int j;

    i = 0;

    printf("\n");
    while (i <=19)
    {
        j = 0;

        while (data->map.map[i][j] != '\n' && data->map.map[i][j] != '\0')
        {
            if (data->map.map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->mlx_win, 
                data->map.collectible_sprite, j * TILE_SIZE, i * TILE_SIZE);
            /* else if (data->map.map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->mlx_win, 
                data->map.exit_sprite, j * TILE_SIZE, i * TILE_SIZE); */
			else if (data->map.map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_win, 
                data->map.wall_sprite, j * 64, i * 64);
            else if (data->map.map[i][j] == 'P')
                ft_draw_player(data);
            else if (data->map.map[i][j] == 'E')
                ft_draw_collect_ghost(data);
            else
                mlx_put_image_to_window(data->mlx, data->mlx_win, 
                data->map.floor_sprite, j * 64, i * 64);
            j++;
        }
        i++;
    }
}


/* void	ft_draw_floor_wall(lienzo *data)
{
    int i;
    int j;

    i = 0;
    while (data->map.map[i])
    {
        j = 0;
        while (data->map.map[i][j] != '\0')
        {
            
            j++;
        }
        i++;
    }
} */

/* 
void render_map_while(lienzo *lienzo, map map) {
    int y = 0;
    int x = 0;

    while (y < map.height) {
        while (x < map.width) {
            if (map.map[y][x] == '1') {
                lienzo->img = mlx_xpm_file_to_image(lienzo->mlx, "resource/pacman-art/pared.xpm", &(lienzo->player->x), &(lienzo->player->y));
            } else if (map.map[y][x] == 'E') {
                lienzo->img = mlx_xpm_file_to_image(lienzo->mlx, "resource/pacman-art/camino.xpm", &(lienzo->player->x), &(lienzo->player->y));
            } else {
                lienzo->img = NULL;
            }
            if (lienzo->img) {
                mlx_put_image_to_window(lienzo->mlx, lienzo->win, lienzo->img, map.position * 64, y * 64); // Assuming each tile is 64x64
            }
            x++;
        }
        x = 0;
        y++;
    }
}

void render_player(lienzo *lienzo, player player)
{
    lienzo->img = mlx_xpm_file_to_image(lienzo->mlx, "resource/pacman-art/pacman-right/1.png", &(lienzo->x), &(lienzo->y));
    if (lienzo->img) {
        mlx_put_image_to_window(lienzo->mlx, lienzo->win, lienzo->img, player.x * 64, player.y * 64); // Assuming each tile is 64x64
    }
}

void render_enemy(lienzo *lienzo, ghost ghost)
{
    lienzo->img = mlx_xpm_file_to_image(lienzo->mlx, "resource/pacman-art/ghosts/blinky.png", &(lienzo->x), &(lienzo->y));
    if (lienzo->img) {
        mlx_put_image_to_window(lienzo->mlx, lienzo->win, lienzo->img, ghost.x * 64, ghost.y * 64); // Assuming each tile is 64x64
    }
} */
