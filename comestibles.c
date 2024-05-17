#include "so_long.h"
void read_map(const char *filename, map map)
{
    int fdd;
    int i, j;
    char buf[1];

    fdd = open(filename, O_RDONLY);
    if (fd == -1) {
        write(2, "Error opening file\n", 19);
        exit(EXIT_FAILURE);
    }

    i = 0;
    j = 0;
    while (read(fd, buf, 1) > 0) {
        if (buf[0] == '0' || buf[0] == '1') {
            map.map[i][j++] = buf[0] - '0';
            if (j == MAP_WIDTH) {
                j = 0;
                i++;
            }
        }
    }

    close(fd);
}

void add_position(Coordinates **positions, int *count, int x, int y)
{
    *positions = ft_realloc(*positions, (*count) * sizeof(Coordinates), ((*count) + 1) * sizeof(Coordinates));
    (*positions)[*count].x = x;
    (*positions)[*count].y = y;
    (*count)++;
}

Coordinates *find_free_positions(int *count, map map)
{
    int x, y;

    *count = 0;
    Coordinates *free_positions = NULL;
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
    Coordinates *free_positions;
    

    free_positions = find_free_positions(&free_count, map);

    if (free_count == 0) {
        write(1, "No free positions available!\n", 29);
        free(free_positions);
        return;
    }

    medir_tiempo(0.1);
    int random_index = custom_rand() % free_count;

    Coordinates new_comestible = free_positions[random_index];

    comestibles->positions = ft_realloc(comestibles->positions, comestibles->count * sizeof(Coordinates), (comestibles->count + 1) * sizeof(Coordinates));
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

        write(1, "Comestibles placed: ", 20);
        ft_putnbr(comestibles->count);
        write(1, "\n", 1);

        write(1, "Current score: ", 15);
        ft_putnbr(comestibles->count);
        write(1, "\n", 1);

        sleep(2);
    }

    return comestibles->count;
}
