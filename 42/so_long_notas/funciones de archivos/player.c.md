# estructuras
```C
typedef struct t_player{
	int x;
	int y;
	int vida;
	t_keys key;
	t_mapa map;
}   player
```

# ft_moviplay
## funcionamiento
-  esta va a consistir en la logica del movimiento va recibir el retorno de la funcion ft_pulsakey  y segun eso se ira moviendo en mapa[x]  [y]   de 1 en 1
## variables
- x
- y
- mapa**
- key
## retorno
- va a retornar el valor de mapa[x]  [y]
## declaracion funcion
```C
int ft_moviplay(map *map, int x , int y)
{
    if (map->map[map->player.y + y][map->player.x +x] == '1')
        return 0;
    if (map->map[map->player.y + y][map->player.x +x] == 'E')
        return 0;

    if (map->map[map->player.y + y][map->player.x +x] == 'C')
    {
        map->comestibles--;
        map->map[map->player.y + y][map->player.x + x] = '0';
    }
    map->map[map->player.y][map->player.x] = '0';
    map->player.x += x;
    map->player.y +=y;
    map->map[map->player.y][map->player.x] = 'P';
    return 1;
}
```


