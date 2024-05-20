#include "so_long.h"

void draw_sprite(void *mlx, void *mlx_win, void *sprite, int x, int y)
{
    mlx_put_image_to_window(mlx, mlx_win, sprite, x * SIZE, y * SIZE);
}


void draw_map(lienzo *lienzo)
{
    int y = 0;
    while (y < lienzo->map.height)
    {
        int x = 0;
        while (x < lienzo->map.width) {
            char tile = lienzo->map.map[y][x];
            void *sprite = NULL;

            if (tile == '1') {
                sprite = lienzo->map.wall_sprite;
            } else if (tile == '0') {
                sprite = lienzo->map.floor_sprite;
            } else if (tile == 'P') {
                sprite = lienzo->player->sprites[0]; // Suponiendo que el primer sprite es el del jugador
            } else if (tile == 'E') {
                sprite = lienzo->map.exit_sprite;
            } else if (tile == 'C') {
                sprite = lienzo->map.collectible_sprite;
            }

            if (sprite) {
                draw_sprite(lienzo->mlx, lienzo->mlx_win, sprite, x, y);
            }
            x++;
        }
        y++;
    }
}
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