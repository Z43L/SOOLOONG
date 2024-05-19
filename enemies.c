#include "so_long.h"
coordinates ft_movighost(char **map, int x, int y)
{
    coordinates new_coords = {x, y};
    int directions[4][2] =
    {
        {0, 1},  // Derecha
        {1, 0},  // Abajo
        {0, -1}, // Izquierda
        {-1, 0}  // Arriba
    };

    int moved = 0;

    // Intentar moverse en una dirección aleatoria hasta que se logre un movimiento válido
    while (!moved)
    {
         // Simula el paso del tiempo
        medir_tiempo(0.05);
        int rand_index = custom_rand() % 4; // Escoge una dirección aleatoria
        int new_x = x + directions[rand_index][0];
        int new_y = y + directions[rand_index][1];

        // Verifica que el nuevo movimiento esté dentro del mapa y no sea una pared
        if (map[new_x][new_y] == '0')
        {
            new_coords.x = new_x;
            new_coords.y = new_y;
            moved = 1;
        }
    }

    return new_coords;
}

int ft_sitpillo(player *player, ghost *ghost, double tiempo)
{
    const char *filename;
    filename = "map.bert";
    ghost->posicion_inicial = ghostpositioni(filename, *ghost);
    if(player->comeme->positions == player->position)
    {
        while(medir_tiempo(3))
        {
            if(player->position == ghost->position)
            {
                ghost->position = ghost->posicion_inicial;
                return 1;
            }
            else
                return 0;
        }
    }
}
char **ghostpositioni(const char *filename, ghost ghost)
{
    int y;
    int x;
    char **line;
    char *read;
    int fdd;
    fdd = open(filename, O_RDONLY);

    read = ft_get_next_line(fdd);

    while(read != 'C')
    {
        line[y] = ft_split(read, '\n');
        x = ft_strlen(line[y]);
        if(read == 'C')
            return line[y][x];
        y++;
        free(read);
    }
    return line[x][y];
}