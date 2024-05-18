#include "so_long.h"

char **ft_compiniciales(int fd, map map)
{
    // Check if the map file exists
    if (fd == -1)
    {
        return (NULL);
    }

    // Initialize the map
    map.map = NULL;
    map.y = 0;

    // Read the map file line by line
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        // Check if all lines have the same length
        if (ft_compx("mapa.bert"== 1)
        {
            free2DArray(map.map, map.y);
            free(line);
            return (NULL);
        }

        // Copy the line into the map
        map.map = ft_map(map.map, line, map.y);

        // Increment the number of rows
        map.y++;

        // Free the line
        free(line);
    }

    // Close the map file
    close(fd);

    // Return the map
    return (map.map);
}

void	*new_window(void *mlx, int width, int height, char *title)
{
	void	*mlx;
	

    
	mlx = mlx_init();
    mlx_win = new_window(mlx,640,480, "hemlo world");
    mlx_loop(mlx);
    mlx_destroy_window(mlx, mlx_win);
    mlx_terminate(mlx);
    return 0;
}
