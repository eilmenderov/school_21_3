#include "head_fdf.h"

static double	ft_find_max(double x, double y, t_data *data)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	if (x > y)
		return (x);
	return (y);
}

static int	ft_find_color(int z, int z1, t_data *data)
{
	data->x = data->x * data->zoom;
	data->y = data->y * data->zoom;
	data->x1 = data->x1 * data->zoom;
	data->y1 = data->y1 * data->zoom;
	if (z + z1 > 0)
		return (BROW);
	if (z + z1 < 0)
		return (BLUE);
	return (GREEN);
}

static void	ft_isometric(int z, int z1, t_data *data)
{
	data->x = (data->x - data->y) * sin(data->angle_x);
	data->y = (data->x + data->y) * cos(data->angle_y) - z;
	data->x1 = (data->x1 - data->y1) * sin(data->angle_x);
	data->y1 = (data->x1 + data->y1) * cos(data->angle_y) - z1;
	data->x = data->x + data->shift_x;
	data->y = data->y + data->shift_y;
	data->x1 = data->x1 + data->shift_x;
	data->y1 = data->y1 + data->shift_y;
}

void	ft_draw_br(t_data *data)
{
	double	x_step;
	double	y_step;
	double	max;
	int		z;
	int		z1;

	z = data->arr[(int)data->y][(int)data->x] * data->z_cof;
	z1 = data->arr[(int)data->y1][(int)data->x1] * data->z_cof;
	data->c = ft_find_color(z, z1, data);
	ft_isometric(z, z1, data);
	x_step = data->x1 - data->x;
	y_step = data->y1 - data->y;
	max = ft_find_max(x_step, y_step, data);
	x_step /= max;
	y_step /= max;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		if (z != z1)
			data->c = data->c + COL_COR;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->c);
		data->x += x_step;
		data->y += y_step;
	}
}

void	ft_draw(t_data *data, int x, int y)
{
	while (y < data->heig)
	{
		x = 0;
		while (x < data->widt)
		{
			data->x = x;
			data->y = y;
			data->x1 = x + 1;
			data->y1 = y;
			if (x < data->widt - 1)
				ft_draw_br(data);
			data->x = x;
			data->y = y;
			data->x1 = x;
			data->y1 = y + 1;
			if (y < data->heig - 1)
				ft_draw_br(data);
			x++;
		}
		y++;
	}
}
