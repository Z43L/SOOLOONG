#include "so_long.h"

void render_map_while(lienzo *lienzo, map mapa) {
    int y = 0;
    int x = 0;

    while (y < mapa.height) {
        while (x < mapa.width) {
            if (mapa.map[y][x] == 1) {
                lienzo->img = "img/wall.png";
            } else if (mapa.map[y][x] == 'E') {
                lienzo->img = "img/exit.png";
            } else {
                lienzo->img = NULL;
                lienzo->img = NULL;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

void render_player(lienzo *lienzo, player player)
{
    lienzo->img = "img/player.png";
    lienzo->player->x = player.x;
    lienzo->player->y = player.y;
}

void render_enemy(lienzo *lienzo , ghost ghost)
{
    lienzo->img = "img/ghost.png";
    lienzo->ghost->x = ghost.x;
    lienzo->ghost->y = ghost.y;

}