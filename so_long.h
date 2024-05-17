
#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include "lib/ft_get_next_line/get_next_line.h"
#include "lib/LIBFT/libft.h"
#include "lib/minilibx-linux/mlx.h"
#include "lib/FT_PRINTF/ft_printf.h"
#define fd "mapa.bert"
#define MAP_WIDTH 24
#define MAP_HEIGHT 20

typedef struct t_keys{
    char a;
    char s;
    char w;
    char d;
    char q;
} keys;

typedef struct t_gosht{
    int x;
    int y;
    int vida;
    map;
    char  **posicion_inicial;
    Coordinates* position;
}   ghost;

typedef struct t_coodinates{
    int x;
    int y;
} Coordinates;

typedef struct t_mapa{
    char **map;
    char *line;
    int   x;
    int   y;
    player player;
    ghost;
    comestibles *comestibles;
    int rows;
    int wall;
    Coordinates* position;
} map;

typedef struct t_drawmap{
    char P;
    char E;
    char C;
    int cero;
    int uno;
}   dramap;


typedef struct t_player{
    int x;
    int y;
    int vida;
    keys;
    map;
    Coordinates* position;
}   player;

typedef struct t_comestibles{
    Coordinates* positions;
    int count;
}   comestibles ;

int ft_compx(int fdd);
int ft_county(int fdd);
int custom_rand();
double medir_tiempo(double duracion_segundos);
double calcular_frecuencia_cpu();
unsigned long long read_tsc(void);
void *ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
