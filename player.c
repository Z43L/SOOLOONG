#include "so_long.h"
int ft_moviplay(map *map, int x , int y)
{
    if (map->map[map->player.y + y][map->player.x +x] == '1')
        return 0;
    if (map->map[map->player.y + y][map->player.x +x] == 'E')
        return 0;

    if (map->map[map->player.y + y][map->player.x +x] == 'C')
    {
        map->comestibles--;
        map->map[map->player.y + y][map->player.x + x] = '0';
    }
    map->map[map->player.y][map->player.x] = '0';
    map->player.x += x;
    map->player.y +=y;
    map->map[map->player.y][map->player.x] = 'P';
    return 1;
}