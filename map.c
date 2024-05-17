#include "so_long.h"

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