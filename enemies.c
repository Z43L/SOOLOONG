#include "so_long.h"
Coordinates ft_movighost(char **map, int x, int y) {
    Coordinates new_coords = {x, y};
    int directions[4][2] = {
        {0, 1},  // Derecha
        {1, 0},  // Abajo
        {0, -1}, // Izquierda
        {-1, 0}  // Arriba
    };

    int moved = 0;

    // Intentar moverse en una dirección aleatoria hasta que se logre un movimiento válido
    while (!moved) {
         // Simula el paso del tiempo
        medir_tiempo(0.05);
        int rand_index = custom_rand() % 4; // Escoge una dirección aleatoria
        int new_x = x + directions[rand_index][0];
        int new_y = y + directions[rand_index][1];

        // Verifica que el nuevo movimiento esté dentro del mapa y no sea una pared
        if (map[new_x][new_y] == '0') {
            new_coords.x = new_x;
            new_coords.y = new_y;
            moved = 1;
        }
    }

    return new_coords;
}

int ft_sitpillo(player player, ghost ghost, comestibles comestibles ,double tiempo)
{
    ghost.posicion_inicial = ghostpositioni(fd, ghost);
    if(comestibles.positions == player.position)
    {
        while(medir_tiempo(3))
        {
            if(player.position == ghost.position)
            {
                ghost.position = ghost.posicion_inicial;
                return 1;
            }
            else
                return 0;
        }
    }
}
char ghostpositioni(int fdd, ghost ghost)
{
    char y;
    char *line;
    fdd = open(fd, O_RDONLY);

    line = ft_get_next_line(fd);

    while(line = ft_get_next_line(fd) != 'C')
    {
        if(line == 'C')
            return y;
        free(line);
    }
    return line;
}