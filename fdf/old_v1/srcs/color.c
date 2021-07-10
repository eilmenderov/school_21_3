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

static int	get_light(int start, int end, double perc)
{
	return ((int)((1 - perc) * start + perc * end));
}

static int	get_color(t_data *data)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	if (data->c == data->end_c)
		return (data->c);
	if (data->d_x > data->d_y)
		perc = ft_percent(data->st_x, data->end_x, data->c);
	else
		perc = ft_percent(data->st_y, data->end_y, data->c);
	r = get_light((data->st_c >> 16) & 0xFF, (data->end_c >> 16) & 0xFF, perc);
	g = get_light((data->st_c >> 8) & 0xFF, (data->end_c >> 8) & 0xFF, perc);
	b = get_light(data->st_c & 0xFF, data->end_c & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}
