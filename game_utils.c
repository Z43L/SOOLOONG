#include "so_long.h"

// Generador de números pseudoaleatorios
int custom_rand() 
{
    unsigned int rand_seed;

    rand_seed = 123456789;
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}

// Función para leer el contador de ciclos del procesador
unsigned long long read_tsc(void)
{
    unsigned int lo, hi;

    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));

    return ((unsigned long long)hi << 32) | lo;
}

// Función para calcular la frecuencia del procesador
double calcular_frecuencia_cpu()
{
    unsigned long long start, end;
    double tiempo_espera = 1.0; // Esperar 1 segundo
    volatile double tiempo_inicio = 0.0;

    start = read_tsc();

    // Esperar un tiempo utilizando un bucle while
    while (tiempo_inicio < 1000000000.0)
    {
        tiempo_inicio += 1.0;
    }

    end = read_tsc();

    return (end - start) / tiempo_espera;
}

// Función principal para medir el tiempo en segundos
double medir_tiempo(double duracion_segundos)
{
    unsigned long long start, end;
    double frecuencia_cpu = calcular_frecuencia_cpu();
    volatile double tiempo_transcurrido = 0.0;

    start = read_tsc();

    // Esperar un tiempo utilizando un bucle while
    while (tiempo_transcurrido < frecuencia_cpu * duracion_segundos)
    {
        tiempo_transcurrido += 1.0;
    }

    end = read_tsc();

    return (end - start) / frecuencia_cpu;
}

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;
    size_t min_size;

    if (!ptr)
        return malloc(new_size);
    if (!new_size)
    {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;
    min_size = old_size < new_size ? old_size : new_size;
    ft_bzero(new_ptr, new_size);
    while (min_size--)
    {
        ((unsigned char *)new_ptr)[min_size] = ((unsigned char *)ptr)[min_size];
    }
    free(ptr);
    return new_ptr;
}