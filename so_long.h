
#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include "lib/ft_get_next_line/get_next_line.h"
#include "lib/LIBFT/libft.h"
#include "lib/minilibx-linux/mlx.h"
#include "lib/FT_PRINTF/src/ft_printf.h"

#define MAP_WIDTH 24
#define MAP_HEIGHT 20
#define SIZE 8
#define TILE_SIZE 32

typedef struct t_mapa map;
typedef struct t_player player;
typedef struct t_comestibles comestibles;
typedef struct t_lienzo lienzo;
typedef struct t_drawmap dramap;
typedef struct t_gosht ghost;
typedef struct t_coodinates coordinates;
typedef struct t_keys keys;

struct t_coodinates {
    int x;
    int y;
};

struct t_keys {
    char a;
    char s;
    char w;
    char d;
    char q;
};

struct t_gosht {
    int x;
    int y;
    int vida;
    int moving;
    map *mapa;
    struct t_gosht *next; // Updated to use t_gosht to match the typedef
    coordinates *posicion_inicial;
    coordinates *position;
    void *sprite;
    coordinates pos[2];
    coordinates win_pos[2];
};

struct t_mapa {
    char **map;
    char *line;
    int x;
    int y;
    int height;
    int width;
    player *player;
    ghost *ghost;
    comestibles *comestibles;
    int rows;
    int wall;
    coordinates *position;
    coordinates pos;
    coordinates win_pos;
    void *wall_sprite;
    void *floor_sprite;
    void *exit_sprite;
    void *collectible_sprite;
};

struct t_drawmap {
    char P;
    char E;
    char C;
    int cero;
    int uno;
};

struct t_player {
    int x;
    int y;
    int vida;
    int moving;
    struct t_player *next;
    void *sprites[4];
    coordinates pos[2];
    coordinates win_pos[2];
    keys keys;
    map *map;
    comestibles *comeme;
    coordinates *position;
};

struct t_comestibles {
    coordinates *positions;
    int x;
    int y;
    int count;
};

struct t_lienzo {
    void *mlx;
    void *mlx_win;
    void *win;
    char *img;
    int img_width;
    int img_height;
    char *addr;
    int bits_per_pixel;
    int line_lenght;
    map map;
    player *player;
    ghost *ghost;

};


char *ft_buscexit(dramap dramap, const char *filename);
int ft_compx(const char *filename);
int ft_county(const char *filename);
int custom_rand();
double medir_tiempo(double duracion_segundos);
double calcular_frecuencia_cpu();
void *ft_realloc(void *ptr, size_t old_size, size_t new_size);
void free2DArray(map mapa);
char **ft_mapa(const char *filename, map mapa,int y);
coordinates ghostpositioni(const char *filename);
int ft_sitpillo(player *player, ghost *ghost, double tiempo);
coordinates ft_movighost(char **map, int x, int y); 
void render_map_while(lienzo *lienzo, map mapa);
void render_player(lienzo *lienzo, player player);
void render_enemy(lienzo *lienzo , ghost ghost);
int ft_simpilla(ghost ghost, player player);
int ft_moviplay(map *map, int x , int y);
int renderr_game(lienzo *lienzo, map mapa, player player, ghost ghost);
int ft_initgame( map *map, lienzo *lienzo);
int ft_startrun(player *player, ghost *ghost, map *map);
void draw_map(lienzo *lienzo);
#endif
