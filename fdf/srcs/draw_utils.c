#include "head_fdf.h"

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
	mlx_string_put(mlx, win, 15, y += 35, COLOR_TEXT, "Corr_Z: 1/3");
	mlx_string_put(mlx, win, 15, y += 35, COLOR_TEXT, "Line/Points - N/M");
	mlx_string_put(mlx, win, 15, y += 35, COLOR_TEXT, "Exit - ESC");
}

int	ft_abs(int a)
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
