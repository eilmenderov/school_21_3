#include "head_fdf.h"

static void	ft_put_pixel(t_data *data, int x, int y)
{
	int	i;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * data->bit_per_pixel / 8) + (y * data->size_line);
		data->addr[i] = data->cur_c;
		data->addr[++i] = data->cur_c >> 8;
		data->addr[++i] = data->cur_c >> 16;
	}
}

static void	ft_draw_line(t_data *data, int sx, int sy)
{
	int	x;
	int	y;
	int	tmp[2];

	x = ft_ABS(data->end_x - data->st_x);
	y = ft_ABS(data->end_y - data->st_y);
	sx = ft_comper(data->st_x, data->end_x);
	sy = ft_comper(data->st_y, data->end_y);
	tmp[0] = x - y;
	while (data->cur_x != data->end_x || data->cur_y != data->end_y)
	{
		data->cur_c = ft_get_color(data, x, y);
		ft_put_pixel(data, data->cur_x, data->cur_y);
		tmp[1] = tmp[0] * 2;
		if (tmp[1] > -y)
		{
			tmp[0] -= y;
			data->cur_x += sx;
		}
		if (tmp[1] < x)
		{
			tmp[0] += x;
			data->cur_y += sy;
		}
	}
}

static void	ft_what_draw(t_data *data, int x, int y)
{
	if (data->height == 1 && data->width == 1)
	{
		ft_pool_st(data, x, y);
		ft_put_pixel(data, data->cur_x, data->cur_y);
	}
	if (data->line_point == 0 && data->height * data->width != 1)
	{
		ft_draw_line(data, 0, 0);
		if (data->treug == 1 && x < data->width - 1 && y < data->height - 1)
		{
			ft_pool_st(data, x, y);
			ft_pool_end(data, x + 1, y + 1);
			ft_draw_line(data, 0, 0);
		}
	}
	if (data->line_point == 1 && data->height * data->width != 1)
	{
		data->cur_c = data->cur_c + data->color;
		ft_put_pixel(data, data->cur_x, data->cur_y);
		if (x == data->width - 2 || y == data->height - 2)
		{
			data->cur_c = data->end_c;
			ft_put_pixel(data, data->end_x, data->end_y);
		}
	}
}

static void	ft_draw_back(t_data *data)
{
	int	i;
	int	*img;
	int	tmp;

	tmp = WIDTH * HEIGHT;
	ft_memset(data->addr, 0, tmp * (data->bit_per_pixel / 8));
	img = (int *)(data->addr);
	i = 0;
	while (i < tmp)
	{
		if (i % WIDTH < MENU_WIDTH)
			img[i] = MENU_BACKGROUND;
		else
			img[i] = BACKGROUND;
		i++;
	}
	if (data->height == 1 && data->width == 1)
		ft_what_draw(data, 0, 0);
}

void	draw_image(t_data *data, int x, int y)
{
	ft_draw_back(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x != data->width - 1)
			{
				ft_pool_st(data, x, y);
				ft_pool_end(data, x + 1, y);
				ft_what_draw(data, x, y);
			}
			if (y != data->height - 1)
			{
				ft_pool_st(data, x, y);
				ft_pool_end(data, x, y + 1);
				ft_what_draw(data, x, y);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_print_menu(data, 0);
}
