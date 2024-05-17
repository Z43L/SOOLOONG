# structuras
```C
typedef struct t_gosht{
	int x;
	int y;
	int vida;
	t_mapa map;
	char  **posicion_inicial;
}   ghost
```

```C
typedef struct {
    int x;
    int y;
} Coordinates;
```

# ft_movighost
## funcionamiento
- se va a encargar de gestionar el algoritmo de movimiento del fantasma que se tendra que mover de un lado para otro subir bajar y moverse por el mapa siempre en el espacio de movimiento y nunca por la pared para ello similar al del ft_detecwall pero en este caso nadie va a controlar al fantasma por lo que se complica un poco
# variables
- mapa
- x
- y 
- cero -> zona por donde se meve en el mapa
# retorno 
Podría retornar:

1. **Las nuevas coordenadas del fantasma** : Esto permitiría a la función que llama a `ft_movighost` actualizar la posición del fantasma en el mapa.
2. **Un estado indicando el éxito o fallo del movimiento**: Esto podría ser útil para manejar casos donde el fantasma no puede moverse (por ejemplo, si está rodeado de paredes).
# declaracion Funcion
```C
Coordinates ft_movighost(char **map, int x, int y) {
    Coordinates new_coords = {x, y};
    int directions[4][2] = {
        {0, 1},  // Derecha
        {1, 0},  // Abajo
        {0, -1}, // Izquierda
        {-1, 0}  // Arriba
    };

    int moved = 0;

    // Intentar moverse en una dirección aleatoria hasta que se logre un movimiento válido
    while (!moved) {
        increment_counter(); // Simula el paso del tiempo
        int rand_index = custom_rand() % 4; // Escoge una dirección aleatoria
        int new_x = x + directions[rand_index][0];
        int new_y = y + directions[rand_index][1];

        // Verifica que el nuevo movimiento esté dentro del mapa y no sea una pared
        if (map[new_x][new_y] == '0') {
            new_coords.x = new_x;
            new_coords.y = new_y;
            moved = 1;
        }
    }

    return new_coords;
}
```

# ft_sitpillo
## funcionamiento
- va a a consistir en una sencilla funcion en la que si el jugador se come un comestible especial  va a tener 30 segundos para poder matar al fantasma
## variables
- player 
- comestibles
- ghost
- tiempo
## retorno 
devolera 1 si el player se come al fantasma y 0 si no
## declaracion funcion
```C
int ft_sitpillo(t_player player, t_ghost ghost, t_comestibles , tiempo)
```

# ft_spawm
## funcionamiento
si la funcion ft_sitpillo devuelve 1 entoces se ejecutara esta que consistira en reestablecer la posicion del fantasma a la inicial para ello igualaremos la variable posicion de las cordenadas a la posicion inicial
# variables
- posicion_inicial**
- ghost
- mapa**
- cordenates
# retorno 
deve devover un char ** con la posicion x e y

# declaracion funcion
```C
char **ft_spwm(t_mapa map, t_ghost ghost, t_cordenates cordenates);
```