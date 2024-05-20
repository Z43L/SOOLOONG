#include "so_long.h"

int ft_compx(const char *filename)
{
    int fdd;
    char *line;
    fdd = open(filename, O_RDONLY);
    size_t longitud;
    line = ft_get_next_line(fdd);
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
            return 0;
        }
    }
    return 0;
}


int ft_county(const char *filename)
{
    int fdd;
    int y;
    char *line;
    fdd = open(filename, O_RDONLY);

    line = ft_get_next_line(fdd);

    while(line != NULL)
    {
        y++;
        free(line);
    }
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

char **ft_mapa(const char *filename, map mapa,int y)
{
    int fdd;
    int i;
    char *line;
    fdd = open(filename, O_RDONLY);
    i  = 0;
    int x;
    x = 0;
    line = ft_get_next_line(fdd);
    while(line != NULL)
    {
        mapa.map = malloc(sizeof(char*) * y);
        while ( i < y)
        {
            mapa.map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
            mapa.map[i]=ft_strdup(line);
            free(line);
            x++;
        }
    }
    return mapa.map;
}