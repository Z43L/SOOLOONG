#include "so_long.h"

int ft_compx(const char *filename)
{
    filename = "mapa.bert";
    int fdd;
    char *line;
    fdd = open(filename, O_RDONLY);
    size_t longitud;
    line = get_next_line(fdd);
    longitud = ft_strlen(line);
    while(line  != NULL)
    {
        if(ft_strlen(line) != longitud)
        {
            free(line);
            return 1;
        }
        else
        {
            free(line);
            return longitud;
        }
    }
    close(fdd);
    return longitud;
}


int ft_county(const char *filename)
{
    int fdd;
    int y;
    char *line;

    fdd = open(filename, O_RDONLY);
    y = 0;
    line = get_next_line(fdd);
   
    while(line != NULL)
    {
        y++;
        free(line);
        line = get_next_line(fdd);
    }
    close(fdd);
    return y;
}

void free2DArray(map mapa)
{
    int i;

    i=0;
    if(mapa.map  == NULL)
    {
        return ;
    }
    while(mapa.rows > i)
    {
        free(mapa.map[i]);
        i++;
    }
    free(mapa.map);

}
char **ft_mapa(const char *filename, map *mapa, int y)
{
    int i = 0;
    char *line;
    int fdd = open(filename, O_RDONLY);
    mapa->map = NULL;

    if (fdd < 0)
    {
        perror("Error opening file");
        return NULL;  // Handle error case
    }

    printf("Number of lines: %d\n", y);
    mapa->map = malloc(sizeof(char*) * y);
    printf("y vale %d\n", y);
    mapa->map[y] = NULL;
    if (mapa->map == NULL)
    {
        perror("Error allocating memory for map rows");
        close(fdd);
        return NULL;  // Handle memory allocation error
    }

    while ((line = get_next_line(fdd)) != NULL)
    {
        const int x = ft_strlen(line);
        printf("Line: %s Length: %d Address: %p\n", line, x, line);

        mapa->map[i] = malloc(sizeof(char) * (x + 1));

        if (mapa->map[i] == NULL)
        {
            perror("Error allocating memory for map row");
            free(line);
            break;  // Handle error
        }

        strcpy(mapa->map[i], line);  // Copy the line to the map
        free(line);
        i++;
    }

    close(fdd);  // Close the file after reading it
    printf("Map loaded successfully\n");
    return mapa->map;
}
