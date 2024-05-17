
## estructuras
```C
typedef struct t_comestibles{
	int  x;
	int  y;
	int  contador;
}   comestibles 
```
# ft_simpilla
## funcionamiento
- contendra la logica para que en el momento que te pille un fantasma sea gameover 
-  la idea es que tenga un contador de vida = 1 el player y que en el momento en que la posicion del jugador y la del fantasma sea la misma jugador muere 
- pero que si el jugador a cogido una fresa tiene 30 segundos para comerse al fantasma asi que usare la misma logica de antes pero a la inversa
- debe retorna 1 si me pilla y el juego acaba o 0 si me como un fantasma
## variables
- ghost 
- player
- vida
-  fruta 
- tiempo
## declaracion de la funcion 

```C
int ft_simpilla(ghost ghost, player player, map mapaa)
{
    if(ghost.x == mapaa.map && player.x == mapaa.map 
        || ghost.y == mapaa.map && player.y == mapaa.map)
        return 1;
    else
        return 0;
}
```


# ft_iwin
## funcionamiento
- el objetivo es crear una funcion que en el momento en que se hayan comido todas los comestibles el jugador y llege al final del mapa el juego acabe
- o que si  cruza la meta el juege acabe y se cuente los puntos que a recolectado llamando a otra funcion que se encarge de sumar los puntos ft_sumpuntos los punto se conseguiran por cada comestible comido o por matar fantasma
- esta funcion retornara 0 si el usuario llega a la meta y devolvera el numero de puntos recolectados
## variables
- player
- comestibles
- ghost
## declaracion de la funcion

```C
int ft_iwin(player player, ghost ghost, comestibles comestibles,dramap dramap)
{

    char line;

    line = ft_buscexit(dramap , fd);
    if (player.x == line)
    {
        printf("se acabo la partida llegaste al final");
        return 1;
    }
    return 0;
}
```

# ft_buscexit
## funcionamiento
- esta función es para buscar la salida usando get_next_line
# variables
- fd
- drama.P
- line
- exit



```C
char *ft_buscexit(dramap dramap, int fdd)
{
    char exitt;
    char line;
    fdd = open(fdd, O_RDONLY); 
    dramap.P = 'P';
    line = ft_get_next_line(fdd); 

    while((line = ft_get_next_line(fdd)) != dramap.P) 
    {
        if (line = dramap.P)
        {
            return line;
        }

        free(line);
        line = NULL; 
    }

    return NULL; 
}
```
