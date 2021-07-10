#include "head_fdf_bonus.h"

void	ft_isometric(int *x, int *y, int z)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(ANGLE);
	*y = (temp_x + temp_y) * sin(ANGLE) - z;
}

void	ft_print_menu(t_data *data, int y)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	mlx_string_put(mlx, win, 65, y += 20, COLOR_TEXT, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, COLOR_TEXT, "Zoom: NUM +/-");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Corr_Z: 1/3");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Rotate:");
	mlx_string_put(mlx, win, 50, y += 25, COLOR_TEXT, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 50, y += 25, COLOR_TEXT, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 50, y += 25, COLOR_TEXT, "Z-Axis - 7/9");
	mlx_string_put(mlx, win, 40, y += 25, COLOR_TEXT, "Try - A, B, G");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Projection");
	mlx_string_put(mlx, win, 50, y += 25, COLOR_TEXT, "Isometric: I");
	mlx_string_put(mlx, win, 50, y += 25, COLOR_TEXT, "Parallel:  P");
	mlx_string_put(mlx, win, 15, y += 35, COLOR_TEXT, "Lock/Unlock - U");
	mlx_string_put(mlx, win, 15, y += 25, COLOR_TEXT, "Line/Points - N");
	mlx_string_put(mlx, win, 15, y += 25, COLOR_TEXT, "Add Treungl - T");
	mlx_string_put(mlx, win, 15, y += 25, COLOR_TEXT, "Exit - ESC");
}

int	ft_ABS(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	ft_comper(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((unsigned char *)b)[len] = (unsigned char)c;
	}
	return (b);
}
