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
	void	*win;

	win = mlx_new_window(mlx, width, height, title);
	return (win);
}

int ft_initgame(player player, ghost ghost, map map)
{
    // Initialize the graphical interface
    void *mlx = mlx_init();
    void *win = new_window(mlx, 640, 480, "So Long");

    // Render the map
    render_map_while(map, mlx, win);

    // Render the player and the enemy
    render_player(player, mlx, win);
    render_enemy(ghost, mlx, win);

    // Return the position of the enemy and the ghost
    return (ghost.x, ghost.y);
}

int ft_startrun(player player, ghost ghost, map map)
{
    // Start the player's movement
    ft_moviplay(map, player.key);

    // Start the ghost's movement
    ghost = ft_movienemy(map, ghost);

    // Check if the player has eaten a power pellet
    if (ft_sitpilla(player, ghost, map.comestibles, 30))
    {
        // The player becomes the hunter for 30 seconds
        player.is_hunter = 1;
    }

    // Check if the player and the ghost are in the same position
    if (player.x == ghost.x && player.y == ghost.y)
    {
        // If the player is the hunter, reset the ghost's position
        if (player.is_hunter)
        {
            ghost = ft_ghostposition(map);
        }
        // Otherwise, the player loses the game
        else
        {
            return (0); // Game over
        }
    }

    // Check if the ghost has eaten the player
    if (ghost.x == player.x && ghost.y == player.y)
    {
        return (0); // Game over
    }

    // Return 1 if the game is still running
    return (1);
}


int main()
{
    // Initialize the game variables
    player player;
    ghost ghost;
    map map;
    // Load the map
    int fd = open("map.ber", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening map file");
        return EXIT_FAILURE;
    }
    map.map = ft_compiniciales(fd, map);
    if (map.map == NULL)
    {
        perror("Error loading map");
        return EXIT_FAILURE;
    }
    // Initialize the game
    if (ft_initgame(player, ghost, map) == 0)
    {
        perror("Error initializing game");
        return EXIT_FAILURE;
    }
    // Start the game loop
    while (ft_startrun(player, ghost, map))
    {
        // Update the game state
        // ...
        // Render the game
        // ...
    }
    // Clean up
    free2DArray(map.map, map.y);
    close(fd);
    return EXIT_SUCCESS;
}