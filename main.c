#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

char **ft_compiniciales(map *map, const char *filename) {
    int county;
    int compx;

    ft_printf("Compiniciales: Iniciando...\n");

    compx = ft_compx(filename);
    ft_printf("Compiniciales: Valor de compx = %d\n", compx);
    if (compx == 1) {
        ft_printf("Compiniciales: Error en ft_compx\n");
        exit(1);
    }

    county = ft_county(filename);
    ft_printf("Compiniciales: Valor de county = %d\n", county);

    // Asignar mapa con filas basadas en county
    map->map = ft_mapa(filename, map, county);
    if (map->map == NULL) {
        ft_printf("Compiniciales: Error en ft_mapa\n");
        exit(1);
    }

    // Asignar dimensiones del mapa
    map->rows = county;
    map->y = county;
    map->x = ft_strlen(map->map[0]);  // Ancho del mapa

    ft_printf("Compiniciales: Mapa inicializado correctamente\n");
    return map->map;
}

int ft_initgame(map *map, lienzo *lienzo) {
    ft_printf("InitGame: Iniciando...\n");

    // Inicializar MiniLibX
    lienzo->mlx = mlx_init();
    if (lienzo->mlx == NULL) {
        ft_printf("InitGame: Error en mlx_init\n");
        exit(1);
    }
    ft_printf("InitGame: mlx inicializado correctamente\n");

    // Asegurar el cálculo correcto del tamaño de la ventana
    map->width = ft_strlen(map->map[0]);
    map->height = map->y;  // Basado en la cantidad de filas

    int window_width = map->width * TILE_SIZE;
    int window_height = map->height * TILE_SIZE;
    
    lienzo->mlx_win = mlx_new_window(lienzo->mlx, window_width, window_height, "PACMAN");
    if (lienzo->mlx_win == NULL) {
        ft_printf("InitGame: Error en mlx_new_window\n");
        exit(1);
    }
    ft_printf("InitGame: Ventana creada correctamente (width=%d, height=%d)\n", window_width, window_height);
    mlx_key_hook(lienzo->mlx_win, handle_keypress, &lienzo);
    // Cargar sprites
    lienzo->map.wall_sprite = mlx_xpm_file_to_image(lienzo->mlx, "sprites/Other/Walls/wall.xpm", &lienzo->img_width, &lienzo->img_height);
    if (lienzo->map.wall_sprite == NULL) {
        ft_printf("InitGame: Error cargando pared.xpm\n");
        exit(1);
    }

    lienzo->map.floor_sprite = mlx_xpm_file_to_image(lienzo->mlx, "sprites/Other/Walls/black.xpm", &lienzo->img_width, &lienzo->img_height);
    if (lienzo->map.floor_sprite == NULL) {
        ft_printf("InitGame: Error cargando camino.xpm\n");
        exit(1);
    }

    map->exit_sprite = mlx_xpm_file_to_image(lienzo->mlx, "sprites/Other/Portal/portal.xpm", &lienzo->img_width, &lienzo->img_height);
    if (map->exit_sprite == NULL) {
        ft_printf("InitGame: Error cargando camino.xpm\n");
        exit(1);
    }

    map->collectible_sprite = mlx_xpm_file_to_image(lienzo->mlx, "sprites/Other/Pacdots/pacdot_food.xpm", &lienzo->img_width, &lienzo->img_height);
    if (map->collectible_sprite == NULL) {
        ft_printf("InitGame: Error cargando 1.xpm\n");
        exit(1);
    }

    lienzo->player->sprites[0] = mlx_xpm_file_to_image(lienzo->mlx, "resource/pacman-art/1.xpm", &lienzo->img_width, &lienzo->img_height);
    if (lienzo->player->sprites[0] == NULL) {
        ft_printf("InitGame: Error cargando player.xpm\n");
        exit(1);
    }
    lienzo->ghost->sprite = mlx_xpm_file_to_image(lienzo->mlx, "sprites/Ghosts/B/ghost_up1.xpm", &lienzo->img_width, &lienzo->img_height);
    if (lienzo->ghost->sprite == NULL) {
        ft_printf("InitGame: Error cargando player.xpm\n");
        exit(1);
    }

    // Dibujar los elementos del juego
    ft_draw_collect_exit(lienzo);
    ft_draw_collect_ghost(lienzo);
    /* ft_draw_floor_wall(lienzo); */
    ft_draw_player(lienzo);

    // Mantener la ventana abierta
    
    ft_printf("InitGame: Juego inicializado correctamente\n");
    return 0;
}

int ft_startrun(player *player, ghost *ghost, map *map) {
    char *filename = "mapa.bert";
    ft_printf("StartRun: Iniciando...\n");
    int pillada;


    ghostpositioni(filename);
    ft_movighost(map->map, ghost->x, ghost->y);
    ft_sitpillo(player, ghost, 4.0);
    pillada = ft_simpilla(*ghost, *player);

    return pillada;
}
int handle_keypress(int keycode, lienzo *lienzo)
{
    if (keycode == 53) // Tecla Esc para salir
    {
        mlx_destroy_window(lienzo->mlx, lienzo->mlx_win);
        exit(0);
    }
    return 0;
}
int main(void) {
    ft_printf("Main: Iniciando programa...\n");
    
    player player = {
        .pos = {{0, 1}},
        .win_pos = {{0, 0}},
        .moving = 0,

    };

    ghost ghost = {
        .pos = {{0, 0}},
        .win_pos = {{0, 0}},
        .moving = 0,

    };

    map map = {
        .map = ft_mapa("mapa.bert", &map, ft_county("mapa.bert")),
        .x = 0,
        .y = 0,
        .width = 1,
        .height = 1,
    };

    lienzo lienzo = {
        .img_width = SIZE,
        .img_height = SIZE,
        .map = map,
        .player = &player,
        .ghost = &ghost
    };


    char *filename = "mapa.bert";
    lienzo.map.map = ft_compiniciales(&lienzo.map, filename);
    if (lienzo.map.map == NULL) {
        perror("Error al inicializar el mapa");
        return 1;
    } else {
        ft_printf("Mapa cargado correctamente\n");
    }

    // Iniciar el juego
    ft_initgame(&lienzo.map, &lienzo);
    mlx_hook(player.win_pos, 2, 0, key_hook, &player);

    ft_printf("Main: Iniciando bucle de eventos de MiniLibX...\n");
    mlx_loop(lienzo.mlx);
    // Liberar memoria al final
    ft_printf("Main: Liberando memoria...\n");
    if (lienzo.map.map != NULL) {
        int i = 0;
        while (i < lienzo.map.y) {
            if (lienzo.map.map[i] != NULL) {
                free(lienzo.map.map[i]);
            }
            i++;
        }
        free(lienzo.map.map);
    }
    ft_printf("Main: Memoria liberada y finalizando...\n");

    return 0;
}
