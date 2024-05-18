
#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include "lib/ft_get_next_line/get_next_line.h"
#include "lib/LIBFT/libft.h"
#include "lib/minilibx-linux/mlx.h"
#include "lib/FT_PRINTF/ft_printf.h"

#define MAP_WIDTH 24
#define MAP_HEIGHT 20

typedef struct s_player player;
typedef struct s_map map;
typedef struct s_comestibles comestibles;
typedef struct s_ghost ghost;
typedef struct s_lienzo lienzo;
typedef struct s_keys keys;
typedef struct s_coodinates Coordinates;
typedef struct s_drawmap dramap;


struct t_keys
    {
    char a;
    char s;
    char w;
    char d;
    char q;
};

struct t_gosht{
    int x;
    int y;
    int vida;
    map *map;
    char  **posicion_inicial;
    Coordinates* position;
};

struct s_coodinates{
    int x;
    int y;
};

struct t_mapa{
    char **map;
    char *line;
    int   x;
    int   y;
    player *player;
    ghost *ghost;
    comestibles *comestibles;
    int rows;
    int wall;
    Coordinates* position;
};

struct t_drawmap{
    char P;
    char E;
    char C;
    int cero;
    int uno;
};


struct t_player{
    int x;
    int y;
    int vida;
    keys* keys;
    map* map;
    Coordinates* position;
    int is_hunter;
};

 struct t_comestibles{
    Coordinates* positions;
    int count;
};

struct t_lienzo
{
    void *mlx;
    void *mlx_win;
    void *img;
    int weight;
    int height;
    char *addr;
    int bits_per_pixel;
    int line_lenght;
    map* map;
    Coordinates* position;

};

int ft_compx(int fdd);
int ft_county(int fdd);
int custom_rand();
double medir_tiempo(double duracion_segundos);
double calcular_frecuencia_cpu();
unsigned long long read_tsc(void);
void *ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
