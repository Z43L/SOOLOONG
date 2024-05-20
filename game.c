#include "so_long.h"

int ft_simpilla(ghost ghost, player player)
{
    if(ghost.x == player.x  && ghost.y == player.y )
        return 1;
    else
        return 0;
}

int ft_iwin(player player,dramap dramap)
{
    int longitud;
    char *line;
    const char *filename;
    filename = "mapa.bert";
    line = ft_buscexit(dramap , filename);
    longitud = ft_strlen(line - 1);
    if (player.x == line[longitud])
    {
        printf("se acabo la partida llegaste al final");
        return 1;
    }
    return 0;
}

char *ft_buscexit(dramap dramap, const char *filename)
{

    char *line;
    int fdd;
    int longitud;
    fdd = open(filename, O_RDONLY); 
    dramap.P = 'P';
    line = ft_get_next_line(fdd); 
    longitud = ft_strlen(line );
    while(line[longitud]  != dramap.P) 
    {
        if (line[longitud] == dramap.P)
        {
            return line;
        }
        
        free(line);
        line = NULL;
    }
    
    return NULL; 
}

