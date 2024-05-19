#include "so_long.h"
#include <unistd.h>
void read_map(const char *filename, map map)
{
    int fdd;
    int i, j;
    char buf[1];

    fdd = open(filename, O_RDONLY);
    if (fdd == -1) {
        write(2, "Error opening file\n", 19);
        exit(EXIT_FAILURE);
    }

    i = 0;
    j = 0;
    while (read(fdd, buf, 1) > 0) {
        if (buf[0] == '0' || buf[0] == '1') {
            map.map[i][j++] = buf[0] - '0';
            if (j == MAP_WIDTH) {
                j = 0;
                i++;
            }
        }
    }

    close(fdd);
}

void add_position(coordinates **positions, int *count, int x, int y)
{
    *positions = ft_realloc(*positions, (*count) * sizeof(coordinates), ((*count) + 1) * sizeof(coordinates));
    (*positions)[*count].x = x;
    (*positions)[*count].y = y;
    (*count)++;
}

coordinates *find_free_positions(int *count, map map)
{
    int x, y;

    *count = 0;
    coordinates *free_positions = NULL;
    y = 0;
    while (y < MAP_HEIGHT) {
        x = 0;
        while (x < MAP_WIDTH) {
            if (map.map[y][x] == 0)
            {
                add_position(&free_positions, count, x, y);
            }
            x++;
        }
        y++;
    }
    return free_positions;
}

void place_comestible(comestibles *comestibles,map map) {
    int free_count;
    coordinates *free_positions;
    

    free_positions = find_free_positions(&free_count, map);

    if (free_count == 0) {
        write(1, "No free positions available!\n", 29);
        free(free_positions);
        return;
    }

    medir_tiempo(0.1);
    int random_index = custom_rand() % free_count;

    coordinates new_comestible = free_positions[random_index];

    comestibles->positions = ft_realloc(comestibles->positions, comestibles->count * sizeof(coordinates), (comestibles->count + 1) * sizeof(coordinates));
    comestibles->positions[comestibles->count] = new_comestible;
    comestibles->count++;

    free(free_positions);
}
int ft_sumpuntos(comestibles *comestibles, map map)
{
    while (1)
    {
        place_comestible(comestibles, map);
        comestibles->count++;

        ft_putnbr_fd(comestibles->count, 1);

        ft_putnbr_fd(comestibles->count, 1);
        medir_tiempo(3.0);
       
    }

    return comestibles->count;
}
