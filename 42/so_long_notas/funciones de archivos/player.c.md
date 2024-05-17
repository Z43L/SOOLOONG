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
int ft_moviplay(t_mapa map, t_keys key)
```

# ft_detewall
## funcionamiento
- va a aconsistir en que si la posicion de ft_moviplay (vaya mapa x y ) que si la x +1 == 1 (vaya pared) hacemos un return vacio para que no haga nada y asi igual con la y 
## variables
- mapa**
- pared
## retorno 
```C
return ;
```

## Declaracion de la funcion

```C
void ft_detewall(t_mapa map)
```

