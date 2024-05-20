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
    coordinates initial_position = ghostpositioni(filename);
    ghost->posicion_inicial->x = initial_position.x;
    ghost->posicion_inicial->y = initial_position.y;
    if(player->comeme->positions == player->position)
    {
        while(medir_tiempo(tiempo))
        {
            if(player->position == ghost->position)
            {
                ghost->position->x = ghost->posicion_inicial->x;
                ghost->position->y = ghost->posicion_inicial->y;

                return 1;
            }
            else
                return 0;
        }
    }
    return 0;
}
coordinates ghostpositioni(const char *filename)
{
    int y = 0;
    char *read;
    int fdd = open(filename, O_RDONLY);
    coordinates pos = {0, 0};

    if (fdd < 0) {
        perror("Error opening file");
        return pos;
    }

    while ((read = ft_get_next_line(fdd)) != NULL)
    {
        char **line = ft_split(read, '\n');
        for (int x = 0; line && line[x]; x++) {
            if (line[x][0] == 'C') {
                pos.x = x;
                pos.y = y;
                free(read);
                return pos;
            }
        }
        y++;
        free(read);
    }

    close(fdd);
    return pos;
}
