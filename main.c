#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

char **ft_compiniciales(map *map, const char *filename) {
    int county;
    int compx;
    filename = "mapa.bert";
    printf("Compiniciales: Iniciando...\n");

    compx = ft_compx(filename);
    printf("Compiniciales: Valor de compx = %d\n", compx);
    if (compx == 1) {
        printf("Compiniciales: Error en ft_compx\n");
        exit(1);
    }

    county = ft_county(filename);
    printf("Compiniciales: Valor de county = %d\n", county);

    map->map = ft_mapa(*map,county,  filename);
    if (map->map == NULL) {
        printf("Compiniciales: Error en ft_mapa\n");
        exit(1);
    }
    map->rows = county; // Asegurarse de que map->rows está correctamente configurado
    map->y = county;
    map->x = ft_strlen(map->map[0]); // Asumimos que todas las líneas tienen la misma longitud
    printf("Compiniciales: Mapa inicializado correctamente\n");

    return map->map;
}


void ft_initgame(player *player, ghost *ghost, map *map, lienzo *lienzo) {
    printf("InitGame: Iniciando...\n");

    // Inicializar MiniLibX
    lienzo->mlx = mlx_init();
    if (lienzo->mlx == NULL) {
        printf("InitGame: Error en mlx_init\n");
        exit(1);
    }
    printf("InitGame: mlx inicializado correctamente\n");

    // Crear una nueva ventana con tamaño fijo
    int window_width = 800; // Ancho fijo de la ventana
    int window_height = 600; // Alto fijo de la ventana
    lienzo->mlx_win = mlx_new_window(lienzo->mlx, window_width, window_height, "PACMAN");
    if (lienzo->mlx_win == NULL) {
        printf("InitGame: Error en mlx_new_window\n");
        exit(1);
    }
    printf("InitGame: Ventana creada correctamente (width=%d, height=%d)\n", window_width, window_height);

    // Renderizar el mapa, los enemigos y el jugador
    render_map_while(lienzo, *map);
    render_enemy(lienzo, *ghost);
    render_player(lienzo, *player);

    printf("InitGame: Juego inicializado correctamente\n");
}


int ft_startrun(player *player, ghost *ghost, map *map, comestibles *comestibles) {
    printf("StartRun: Iniciando...\n");
    int pillada;
    ft_moviplay(*map, *player, player->x, player->y);
    ghostpositioni(*ghost);
    ft_movighost(map->map, ghost->x, ghost->y);
    ft_sitpillo(player, ghost, comestibles);
    pillada = ft_simpilla(*ghost, *player, *map);
    return pillada;
}

int main(void) {
    printf("Main: Iniciando programa...\n");

    // Inicialización del jugador
    player player = {
        .pos = {0, 0},
        .win_pos = {0, 0},
        .moving = 0,
        .next = NULL,
        .sprites = {NULL, NULL, NULL, NULL} // Añade las imágenes del jugador aquí
    };

    // Inicialización del fantasma
    ghost ghost = {
        .pos = {0, 0},
        .win_pos = {0, 0},
        .moving = 0,
        .next = NULL,
        .sprite = NULL // Añade la imagen del fantasma aquí
    };

    // Inicialización del mapa
    map map = {
        .x = 24, // tamaño inicial basado en el mapa proporcionado
        .y = 20, // tamaño inicial basado en el mapa proporcionado
        .map = NULL
    };

    // Inicialización del lienzo
    lienzo lienzo = {
        .mlx = NULL,
        .mlx_win = NULL,
        .img_width = SIZE, // Tamaño de imagen actualizado
        .img_height = SIZE, // Tamaño de imagen actualizado
        .map = map,
        .player = &player,
        .ghost = &ghost
    };

    // Inicializar el mapa
    char *filename = "mapa.bert";
    lienzo.map.map = ft_compiniciales(&lienzo.map, filename);
    if (lienzo.map.map == NULL) {
        perror("Error al inicializar el mapa");
        return 1;
    }

    // Inicializar el juego
    ft_initgame(&player, &ghost, &lienzo.map, &lienzo);

    // Renderizar el juego
    render_map_while(&lienzo, lienzo.map);
    ft_redraw_player(&lienzo);
    ft_redraw_ghost(&lienzo);

    // Inicia el bucle de eventos de MiniLibX
    printf("Main: Iniciando bucle de eventos de MiniLibX...\n");
    mlx_loop(lienzo.mlx);

    // Liberar memoria antes de salir
    printf("Main: Liberando memoria...\n");
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

    printf("Main: Memoria liberada y finalizando...\n");
    return 0;
}