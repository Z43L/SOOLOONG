### 1. **Conceptualización del Proyecto**

**Objetivo:** Crear un clon del juego Pac-Man utilizando la infraestructura y restricciones del proyecto "so_long" de 42 School.

### 2. **Requisitos y Restricciones del Proyect **Requisitos y Restricciones del Proyecto**

Revisa los requisitos del proyecto "so_long". Asegúrate de cumplir con los siguientes aspectos:

- Uso de la biblioteca gráfica `minilibx` de 42.
- Implementación de un juego 2D con un personaje principal controlado por el jugador.
- Diseño de un mapa jugable cargado desde un archivo.
- Manejo de eventos del teclado para controlar al personaje.
- Condiciones de victoria y derrota.

### 3. **Estructura del Proyect **Estructura del Proyecto**

#### Archivos Principales

- **main.c** : Punto de entrada del programa.
- **game.c** : Contendrá la lógica del juego.
- **map.c** : Funciones para cargar y gestionar el mapa.
- **player.c** : Funciones relacionadas con el control y movimiento del personaje principal.
- **enemies.c** : Funciones para gestionar los fantasmas enemigos.
- **render.c** : Funciones para dibujar los elementos en pantalla.
- **events.c** : Funciones para manejar los eventos del teclado.

#### Recursos

- **sprites/** : Carpeta para almacenar las imágenes de Pac-Man, los fantasmas, las paredes, las pastillas, etc.
- **maps/** : Carpeta para almacenar los archivos de mapa en formato `.ber`.

### 4. **Diseño del Juego**

#### Mapa

El mapa de Pac-Man se puede representar con una matriz 2D. Cada celda de la matriz representa un tipo de elemento (pared, camino, pastilla, superpastilla, jugador, fantasma). Ejemplo de mapa en un archivo `.ber`:

```
111111111111
100000000001
101111111101
101000000101
101011110101
101000010101
111111111111

```
#### Jugador y Fantasmas

- **Pac-Man (Jugador):** Controlado por el jugador, se mueve por el laberinto comiendo pastillas y evitando fantasmas.
- **Fantasmas (Enemigos):** Se mueven automáticamente y deben perseguir a Pac-Man. Puedes implementar un movimiento básico al principio y luego mejorar la inteligencia de los enemigos.

### 5. **Implementación**

#### Inicialización del Juego

- Cargar el mapa desde un archivo.
- Inicializar las estructuras de datos para el jugador y los fantasmas.
- Configurar la ventana y otros recursos gráficos utilizando `minilibx`.

#### Renderizado

- Dibujar el mapa.
- Dibujar a Pac-Man y los fantasmas en sus posiciones actuales.
- Actualizar la pantalla en cada ciclo del juego.

#### Control del Jugador

- Detectar las pulsaciones del teclado para mover a Pac-Man.
- Actualizar la posición del jugador y verificar colisiones con paredes y pastillas.

#### Movimiento de Fantasmas

- Implementar un algoritmo básico para el movimiento de los fantasmas (puedes comenzar con movimiento aleatorio o siguiendo caminos predefinidos)
- Mejorar gradualmente la inteligencia de los fantasmas.

#### Condiciones de Victoria y Derrota

- El jugador gana cuando ha comido todas las pastillas.
- El jugador pierde si es atrapado por un fantasma.

### 6. **Mejoras Adicionales **Mejoras Adicionales**

- **Sonidos y Efectos:** Añadir sonidos al comer pastillas y al ser atrapado por un fantasma.
- **Superpastillas:** Implementar superpastillas que permitan a Pac-Man comer fantasmas temporalmente.
- **Niveles:** Crear múltiples niveles con dificultad creciente.