# ft_compiniciales
## funcionamiento
Se va a encargar de que todas las filas tengan la misma longitud  de contar las y e de comprobar que el mapa ensista y de copiarlo en map.map fila a fila
## funciones a usar
- ft_compx
- ft_county
- free2DArray
- ft_map**

## retorno
Va a retornar un doble puntero con map.map
## Declaración de la funcion

```C
char **ft_compiniciales(int fd, map map)
```

# ft_initgame
## funcionamiento

Va a crear la Window del juego comenzará toda la interfaz gráfica  y dibujamos el mapa con las imagenes y colocamos los personajes en su posición
## funciones a usar
- mlx_init()
- new_window(mlx,640,480)
- render_map_while()
- render_player
- render_enemy
## Retorno

Retornar la posicion del enemigo y el fantasma
## declaracion de la funcion

```C
Int ft_initgame(player player, ghost ghost ,map map)
```

# ft_startrun
Esta función  vamos a iniciar el movimiento del player  y del ghost le vamos a pasar un condicional de que ft_sitpilla el player se convierte en cazador con ft_sitepillo si se coinciden en la misma posición  el fantasma 👻  lo reiniciamos ala ft_ghostpositoni  sino si el ghost se come al player se acaba el juego 
## variables
- player player
- ghost ghost
- Coordinates* position;
- map map
- int i;