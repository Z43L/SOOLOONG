
# numeros speudoaleatorios
```C
static unsigned int counter = 0; // Simula un contador de tiempo

// Función para incrementar el contador (simulando el paso del tiempo)
void increment_counter() {
    counter++;
}

// Función para obtener el valor del contador (simulando obtener el tiempo actual)
unsigned int custom_time() {
    return counter;
}

// Generador de números pseudoaleatorios
static unsigned int rand_seed = 123456789; // Semilla inicial

int custom_rand() {
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}
```



# ft_time
## funcionamiento
- lo que hace esta funcion es simular el tiempo en segundos basadonos en el tiempo que al procesador le cuesta recorrer un while de 1 a 1000000.0 en tonces se le suma 1 segundo a tiempo de inicio  luego se vuelve a hacer otra vez y esa se le igual a end y retornamos el comienzo - el final y lo dividimos entre el tiempo de espara para retornar la frecuencia de la cpu  y una vez la tengamos podemos ir calcular el tiempo que es mas o menos como antes pero este viaje retornamos start - end / frecuencia de cpu

## declaracion funcion
```C
// Función para leer el contador de ciclos del procesador

unsigned long long read_tsc(void) {

unsigned int lo, hi;

asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));

return ((unsigned long long)hi << 32) | lo;

}

  

// Función para calcular la frecuencia del procesador

double calcular_frecuencia_cpu() {

unsigned long long start, end;

double tiempo_espera = 1.0; // Esperar 1 segundo

volatile double tiempo_inicio = 0.0;

  

start = read_tsc();

  

// Esperar un tiempo utilizando un bucle while

while (tiempo_inicio < 1000000000.0) {

tiempo_inicio += 1.0;

}

  

end = read_tsc();

  

return (end - start) / tiempo_espera;

}

  

// Función principal para medir el tiempo en segundos

double medir_tiempo(double duracion_segundos) {

unsigned long long start, end;

double frecuencia_cpu = calcular_frecuencia_cpu();

volatile double tiempo_transcurrido = 0.0;

  

start = read_tsc();

  

// Esperar un tiempo utilizando un bucle while

while (tiempo_transcurrido < frecuencia_cpu * duracion_segundos) {

tiempo_transcurrido += 1.0;

}

  

end = read_tsc();

  

return (end - start) / frecuencia_cpu;

}
```
