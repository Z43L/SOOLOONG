# ft_compx
## estructuras
```
typedef struct t_map{
	char **map;
	char *line;
	int   x;
	int   y;
	t_player player;
	t_ghost ghost;
	t_comestibles comestibles;
<<<<<<< HEAD
=======
	Int rows;
>>>>>>> bc798072c51a4dc323eba71b2463e2ebbe319602
}

```


## funcionamiento
- comprobara que la longitud de cada linea del mapa sea la misma y que si en algun momento cambia retornara 1 y el programa no funcionara y si esta todo bien retornara 0 para ello usaremos gnl para leer cada linea del archivo y haciendo una condicion de que si con ft_strlen es distinto que devuelva 1
## variables
- fd -> archivo con el mapa
-  line -> donde se almacenara el resultado de gnl
## declaracion de la funcion
```
int ft_compx(int fd)
```

<<<<<<< HEAD
=======
# ft_county(fd)
## funcionamiento
- la idea es crea un bucle while mientra gnl != NULL y++
- esta función aunque parezca insignificante la usaremos más a delante para hacer el malloc al mapa completo
```
mapa = y *(malloc(sizeof (char) * gnl ))
```
## variables
- fd
- line
- y
## declaración función
```
int ft_county(int fd)
```

# ft_freemap
 funcionamiento
Esta función deberá de encargarse de hacer un free al mapa siempre y cuando sea necesario
## variables
- Mapa
- rows
# declararon función
```
void free2DArray(int** map, int rows)
```



>>>>>>> bc798072c51a4dc323eba71b2463e2ebbe319602
