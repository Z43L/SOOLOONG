#include "so_long.h"
/* int ft_moviplay(map *map, int x , int y)
{
    if (map->map[map->player->y + y][map->player->x +x] == '1')
        return 0;
    if (map->map[map->player->y + y][map->player->x +x] == 'E')
        return 0;

    if (map->map[map->player->y + y][map->player->x +x] == 'C')
    {
        map->comestibles--;
        map->map[map->player->y + y][map->player->x + x] = '0';
    }
    map->map[map->player->y][map->player->x] = '0';
    map->player->x += x;
    map->player->y +=y;
    map->map[map->player->y][map->player->x] = 'P';
    return 1;
} */

int **pos_player(player player, map map)
{
    int oopen;
    oopen = open(map.filename, O_RDONLY);
    while(!ft_strchr(get_next_line(oopen), 'P'))
    {
        
    }
}

int key_hook(int keycode, player *game)
{
    if (keycode == KEY_W)
        move_up(game);
    else if (keycode == KEY_A)
        move_left(game);
    else if (keycode == KEY_S)
        move_down(game);
    else if (keycode == KEY_D)
        move_right(game);
    /* else if (keycode == KEY_ESC)
        close_game(game); */
    return (0);
}

int move_up(player *game)
{
    if (game->map->map[game->y - 1][game->x] != '1')
    {
        game->map->map[game->y][game->x] = '0';
        game->y--;
        game->map->map[game->y][game->x] = 'P';
    }
    return (0);
}

int move_left(player *game)
{
    if(game->map->map[game->y ][game->x -1] != '1')
    {
        game->map->map[game->y][game->x] = '0';
        game->x--;
        game->map->map[game->y][game->x] = 'P';
    }
    return (0);
}
int move_down(player *game)
{
    if (game->map->map[game->y + 1][game->x] != '1')
    {
        game->map->map[game->y][game->x] = '0';
        game->y++;
        game->map->map[game->y][game->x] = 'P';
    }
    return (0);
}
int move_right(player *game)
{
    if (game->map->map[game->y ][game->x + 1] != '1')
    {
        game->map->map[game->y][game->x] = '0';
        game->x++;
        game->map->map[game->y][game->x] = 'P';
    }
    return (0);
}