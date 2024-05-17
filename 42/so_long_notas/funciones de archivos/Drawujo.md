
# Ft_render_map_while
## funcionamiento

Sirve para renderizar el mapa con las imagenes

## declaración de funcion
```C
void render_map_while(lienzo lienzo, map mapa) {
    int y = 0;
    int x = 0;

    while (y < mapa.alto) {
        while (x < mapa.ancho) {
            if (mapa.mapa[y][x] == 1) {
                lienzo.img[0] = "img/wall.png";
            } else if (mapa.mapa[y][x] == 'E') {
                lienzo.img[1] = "img/exit.png";
            } else {
                lienzo.img[0] = NULL;
                lienzo.img[1] = NULL;
            }
            // Dibujar la imagen correspondiente en la posición (x, y)
            x++;
        }
        x = 0;
        y++;
    }
}
```

## ft_render_player && ft_render_ghost

```C
void render_player(lienzo lienzo, player player)
{
    lienzo.img[2] = "img/player.png";
    lienzo.x = player.x;
    lienzo.y = player.y;
}

void render_enemy(lienzo lienzo , ghost ghost)
{
    lienzo.img[3] = "img/ghost.png";
    lienzo.x = ghost.x;
    lienzo.y = ghoat.y;

}
```
