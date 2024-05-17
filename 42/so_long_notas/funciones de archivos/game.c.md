
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
int ft_simpilla(t_ghost ghost, t_player player)

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
int ft_iwin(t_player player, t_ghost ghost, t_comestibles comestibles)
```

# ft_sumpuntos
## funcionamiento
- el plan que tengo para esta funcion es simple es que siempre que el jugador se encuentre con un comestible que sume puntos a contador
- como es muy facil esta funcion la vamos a complicar un poco vamos a hacer que los comestibles salgan en posiciones seudo aleatorias  pero siempre dentro del mapa para ello utilizaremos gnl para ver en que posicion hay un 0 y con algun algoritmo de aletoridad que valla generando un comestible cada 2 segundos
- debe retornar contador
# variables
- comestibles
- contador
- tiempo

```C
int ft_sumpuntos(t_comestibles comestibles)
```