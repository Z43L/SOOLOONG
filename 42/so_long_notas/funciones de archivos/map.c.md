
## estructuras
```C
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

# ft_compx
## funcionamiento
- comprobara que la longitud de cada linea del mapa sea la misma y que si en algun momento cambia retornara 1 y el programa no funcionara y si esta todo bien retornara 0 para ello usaremos gnl para leer cada linea del archivo y haciendo una condicion de que si con ft_strlen es distinto que devuelva 1
## variables
- fd -> archivo con el mapa
-  line -> donde se almacenara el resultado de gnl
## declaracion de la funcion
```C
int ft_compx(int fdd)
{
    char *line;
    fdd = open(fd, O_RDONLY);
    int longitud;
    line = ft_get_next_line(fd);
    longitud = ft_strlen(line);
    while(line = ft_get_next_line(fd) != NULL)
    {
        if(ft_strlen(line) != longitud)
        {
            free(line);
            return 1;
        }
        else
        {
            free(line);
            return 0;
        }
    }
}
```

<<<<<<< HEAD
=======
# ft_county(fd)
## funcionamiento
- la idea es crea un bucle while mientra gnl != NULL y++
- esta función aunque parezca insignificante la usaremos más a delante para hacer el malloc al mapa completo
```
        mapa.map = malloc(sizeof(char*) * y);
```
## variables
- fd
- line
- y
## declaración función
```C

int ft_county(int fdd)
{
    int y;
    char *line;
    fdd = open(fd, O_RDONLY);

    line = ft_get_next_line(fd);

    while(line = ft_get_next_line(fd) != NULL)
    {
        y++;
        free(line);
    }
    return y;
}
```


# ft_freemap
 funcionamiento
Esta función deberá de encargarse de hacer un free al mapa siempre y cuando sea necesario
## variables
- Mapa
- rows
# declararon función
```C
void free2DArray(map mapa)
{
    int i;

    i=0;
    if(mapa.map  == NULL)
    {
        return NULL;
    }
    while(mapa.rows > i)
    {
        free(mapa.map[i]);
        i++;
    }
    free(mapa.map);

}
```



# ft_mapa**
## funcionamiento
- sirve para  malloquear el mapa y copiar el mapa.bert a map.mapa 
## variables
- fd
- line
- Mapa
## declaración función
```C
char **ft_mapa(int fdd, map mapa,int y)
{
    int i;
    char *line;
    fdd = open(fd, O_RDONLY);
    i  = 0;

    while(line = ft_get_next_line(fd) != NULL)
    {
        mapa.map = malloc(sizeof(char*) * y);
        while ( i < y)
        {
            mapa.map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
            mapa.map[i]=ft_strdup(line);
            free(line);
            i++;
        }
    }
    return mapa.map;
}
```

