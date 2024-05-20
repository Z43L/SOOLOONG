#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

char **ft_compiniciales(map *map, const char *filename) {
    int county;
    int compx;
    filename = "mapa.bert";
    ft_printf("Compiniciales: Iniciando...\n");

    compx = ft_compx(filename);
    ft_printf("Compiniciales: Valor de compx = %d\n", compx);
    if (compx == 1) {
        ft_printf("Compiniciales: Error en ft_compx\n");
        exit(1);
    }

    county = ft_county(filename);
    ft_printf("Compiniciales: Valor de county = %d\n", county);

    map->map = ft_mapa(filename,*map ,county);
    if (map->map == NULL) {
        ft_printf("Compiniciales: Error en ft_mapa\n");
        exit(1);
    }
    map->rows = county;
    map->y = county;
    map->x = ft_strlen(map->map[0]);
    ft_printf("Compiniciales: Mapa inicializado correctamente\n");

    return map->map;
}


int ft_initgame(player *player, ghost *ghost, map *map, lienzo *lienzo) {
    ft_printf("InitGame: Iniciando...\n");

    // Inicializar MiniLibX
    lienzo->mlx = mlx_init();
    if (lienzo->mlx == NULL) {
        ft_printf("InitGame: Error en mlx_init\n");
        exit(1);
    }
    ft_printf("InitGame: mlx inicializado correctamente\n");

    // Crear una nueva ventana con tamaño fijo
    int window_width = 800; // Ancho fijo de la ventana
    int window_height = 600; // Alto fijo de la ventana
    lienzo->mlx_win = mlx_new_window(lienzo->mlx, window_width, window_height, "PACMAN");
    if (lienzo->mlx_win == NULL) {
        ft_printf("InitGame: Error en mlx_new_window\n");
        exit(1);
    }
    ft_printf("InitGame: Ventana creada correctamente (width=%d, height=%d)\n", window_width, window_height);

    // Renderizar el mapa, los enemigos y el jugador
    render_map_while(lienzo, *map);
    render_enemy(lienzo, *ghost);
    render_player(lienzo, *player);

    ft_printf("InitGame: Juego inicializado correctamente\n");
    return 0;
}


int ft_startrun(player *player, ghost *ghost, map *map) {
    char *filename;
    
    filename = "mapa.bert";
    ft_printf("StartRun: Iniciando...\n");
    int pillada;
    ft_moviplay(map,player->x, player->y);
    ghostpositioni(filename);
    ft_movighost(map->map, ghost->x, ghost->y);
    ft_sitpillo(player, ghost, 4.0);
    pillada = ft_simpilla(*ghost, *player);
    return pillada;
}


int main(void) {
    ft_printf("Main: Iniciando programa...\n");

    player player = {
        .pos = {{0, 1}},
        .win_pos = {{0, 0}},
        .moving = 0,
        .next = NULL,
        .sprites = {NULL, NULL, NULL, NULL} // Add the player's images here
    };

    ghost ghost = {
        .pos = {{0, 0}},
        .win_pos = {{0, 0}},
        .moving = 0,
        .next = NULL,
        .sprite = NULL // Add the ghost's image here
    };

    map map = {
        .x = 24,
        .y = 20,
        .map = NULL
    };

    lienzo lienzo = {
        .mlx = NULL,
        .mlx_win = NULL,
        .img_width = SIZE, // Updated image size
        .img_height = SIZE, // Updated image size
        .map = map,
        .player = &player,
        .ghost = &ghost
    };

    char *filename = "mapa.bert";
    lienzo.map.map = ft_compiniciales(&lienzo.map, filename);
    if (lienzo.map.map == NULL) {
        perror("Error al inicializar el mapa");
        return 1;
    }

    int inicio = ft_initgame(&player, &ghost, &lienzo.map, &lienzo);
    while ( inicio != 0)
    {
        render_map_while(&lienzo, lienzo.map);
        render_player(&lienzo, player);
        render_enemy(&lienzo, ghost);
    }
    

    ft_printf("Main: Iniciando bucle de eventos de MiniLibX...\n");
    mlx_loop(lienzo.mlx);

    ft_printf("Main: Liberando memoria...\n");
    if (player.position != NULL) free(player.position);
    if (ghost.position != NULL) free(ghost.position);
    if (lienzo.map.map != NULL) {
        int i = 0;
        while (i < lienzo.map.y) {
            if (lienzo.map.map[i] != NULL)
                free(lienzo.map.map[i]);
            i++;
        }
        free(lienzo.map.map);
    }

    ft_printf("Main: Memoria liberada y finalizando...\n");
    return 0;
}