#include "so_long.h"

int ft_compx(const char *filename)
{
    filename = "mapa.bert";
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
    close(fdd);
    return 0;
}


int ft_county(const char *filename)
{
    int fdd;
    int y;
    char *line;

    fdd = open(filename, O_RDONLY);
    y = 0;
    line = ft_get_next_line(fdd);
   
    while(line != NULL)
    {
        y++;
        free(line);
        line = ft_get_next_line(fdd);
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

char **ft_mapa(const char *filename, map mapa, int y)
{
    int i = 0;
    char *line;
    int fdd = open(filename, O_RDONLY);

    mapa.map = malloc(sizeof(char*) * y);
    while((line = ft_get_next_line(fdd)) != NULL)
    {
        mapa.map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
        strcpy(mapa.map[i], line);
        free(line);
        i++;
    }
    return mapa.map;
}