#include "so_long.h"

int ft_simpilla(ghost ghost, player player, map mapaa)
{
    if(ghost.x == mapaa.map && player.x == mapaa.map 
        || ghost.y == mapaa.map && player.y == mapaa.map)
        return 1;
    else
        return 0;
}

int ft_iwin(player player, ghost ghost, comestibles comestibles,dramap dramap)
{
   
    char line;
    
    line = ft_buscexit(dramap , fd);
    if (player.x == line)
    {
        printf("se acabo la partida llegaste al final");
        return 1;
    }
    return 0;
}

char *ft_buscexit(dramap dramap, int fdd)
{
    char exitt;
    char line;
    fdd = open(fdd, O_RDONLY); 
    dramap.P = 'P';
    line = ft_get_next_line(fdd); 

    while((line = ft_get_next_line(fdd)) != dramap.P) 
    {
        if (line = dramap.P)
        {
            return line;
        }
        
        free(line);
        line = NULL; 
    }
    
    return NULL; 
}

