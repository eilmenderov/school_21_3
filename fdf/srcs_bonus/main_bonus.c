#include "head_fdf_bonus.h"

static void	ft_init_data(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->erfl = 0;
	data->b_lock = 1;
	data->line_point = 1;
	data->zoom = ZOOM;
	data->projection = 0;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->angle = 0.5853;
	data->pl_rad = 0;
	data->z_corr = 2;
	data->x_shift = 0;
	data->y_shift = 0;
	data->color = 0;
	data->treug = 0;
	data->maxz = MN_INT;
	data->minz = MX_INT;
	data->arr = NULL;
	data->mlx = NULL;
	data->win = NULL;
}

static void	ft_clear_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (data->arr[i])
		{
			free (data->arr[i]);
			data->arr[i] = NULL;
		}
		i++;
	}
	free (data->arr);
	data->arr = NULL;
}

static void	ft_key_helper(int key, t_data *data)
{
	if (key == 53)
		exit (0);
	else if (key == 89 && data->b_lock == 1)
		data->beta += 0.05;
	else if (key == 92 && data->b_lock == 1)
		data->beta -= 0.05;
	else if (key == 86 && data->b_lock == 1)
		data->gamma += 0.05;
	else if (key == 88 && data->b_lock == 1)
		data->gamma -= 0.05;
	else if (key == 35 && data->b_lock == 1)
	{
		data->projection = 1;
		data->gamma = 0;
		data->beta = 0;
		data->alpha = 0;
	}
	else if (key == 0 && data->b_lock == 1)
		data->alpha = data->alpha + (M_PI / 2);
	else if (key == 11 && data->b_lock == 1)
		data->beta = data->beta + (M_PI / 2);
	else
		ft_key_help_p2(key, data);
	return ;
}

static int	ft_key(int key, t_data *data)
{
	if (key == 83)
		data->z_corr *= 0.97;
	else if (key == 85)
		data->z_corr /= 0.97;
	else if (key == 125)
		data->y_shift += 15;
	else if (key == 126)
		data->y_shift -= 15;
	else if (key == 123)
		data->x_shift -= 15;
	else if (key == 124)
		data->x_shift += 15;
	else if (key == 78 && data->b_lock == 1)
		data->zoom -= 1;
	else if (key == 69 && data->b_lock == 1)
		data->zoom += 1;
	else if (key == 91 && data->b_lock == 1)
		data->alpha += 0.05;
	else if (key == 84 && data->b_lock == 1)
		data->alpha -= 0.05;
	else
		ft_key_helper(key, data);
	data->rad_z = 0.8 + data->pl_rad;
	draw_image(data, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	ft_init_data(&data);
	ft_read_map(&data, av[1]);
	if (data.erfl)
	{
		ft_clear_data(&data);
		return (0);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FdF_bonus");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &(data.bit_per_pixel),
			&(data.size_line), &(data.endian));
	draw_image(&data, 0, 0);
	mlx_hook(data.win, 2, 0, ft_key, &data);
	mlx_loop(data.mlx);
	ft_clear_data(&data);
	return (0);
}
