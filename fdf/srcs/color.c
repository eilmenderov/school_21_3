#include "head_fdf.h"

static double	ft_percent(int start, int end, int current)
{
	double	plac;
	double	dist;

	plac = current - start;
	dist = end - start;
	if (dist == 0)
		return (1.0);
	return ((plac / dist));
}

static unsigned int	ft_get_light(int start, int end, double percent)
{
	return ((unsigned int)((1 - percent) * start + percent * end));
}

unsigned int	ft_get_color(t_data *data, int x, int y)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	double			percent;

	if (data->cur_c == data->end_c)
		return (data->cur_c + data->color);
	if (x > y)
		percent = ft_percent(data->st_x, data->end_x, data->cur_x);
	else
		percent = ft_percent(data->st_y, data->end_y, data->cur_y);
	r = ft_get_light((data->st_c >> 16) & 0xFF, (data->end_c >> 16)
			& 0xFF, percent);
	g = ft_get_light((data->st_c >> 8) & 0xFF, (data->end_c >> 8)
			& 0xFF, percent);
	b = ft_get_light(data->st_c & 0xFF, data->end_c & 0xFF, percent);
	return (((r << 16) | (g << 8) | b) + data->color);
}

unsigned int	ft_get_default_color(int z, t_data *data)
{
	double	percent;

	percent = ft_percent(data->minz, data->maxz, z);
	if (percent < 0.2)
		return (COLOR_DEEP);
	else if (percent < 0.4)
		return (COLOR_RED);
	else if (percent < 0.6)
		return (COLOR_ZERO);
	else if (percent < 0.8)
		return (COLOR_WHITE);
	else
		return (COLOR_UP);
}

int	ft_on_off(int a)
{
	if (a == 0)
		return (1);
	return (0);
}
