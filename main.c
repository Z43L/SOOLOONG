#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
    mlx_win = new_window(mlx,640,480, "hemlo world");
    mlx_loop(mlx);
    
}
