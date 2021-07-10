#include "head_fdf_bonus.h"

static void	ft_key_helper(int key, t_data *data)
{
	if (key == 91)
		data->shift_y -= 10;
	if (key == 84)
		data->shift_y += 10;
	if (key == 86)
		data->shift_x -= 10;
	if (key == 88)
		data->shift_x += 10;
	if (key == 69)
		data->zoom += 1;
	if (key == 78)
		data->zoom -= 1;
	if (key == 82)
	{
		data->angle_x = 0;
		data->angle_y = 0;
	}
	if (key == 87)
	{
		data->angle_x = M_PI / 2;
		data->angle_y = M_PI / 2;
	}
}

static void	ft_init_data(t_data *data)
{
	data->heig = 0;
	data->widt = 0;
	data->erfl = 0;
	data->x = 0;
	data->x1 = 0;
	data->y = 0;
	data->y1 = 0;
	data->c = 0;
	data->z_cor = 0;
	data->z_cof = Z_COF;
	data->maxz = MN_INT;
	data->minz = MX_INT;
	data->zoom = ZOOM;
	data->angle_x = ANGLE;
	data->angle_y = ANGLE;
	data->shift_x = CORECT;
	data->shift_y = CORECT;
	data->arr = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

static void	ft_clear_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->heig)
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

static int	ft_key(int key, t_data *data)
{
	if (key == 84 || key == 91 || key == 86 || key == 88 || key == 69
		|| key == 78 || key == 82 || key == 87)
		ft_key_helper(key, data);
	if (key == 92)
		data->angle_x += 0.1;
	if (key == 89)
		data->angle_x -= 0.1;
	if (key == 83)
		data->angle_y += 0.1;
	if (key == 85)
		data->angle_y -= 0.1;
	if (key == 126)
		data->z_cof += 1;
	if (key == 125)
		data->z_cof -= 1;
	if (key == 123)
		data->z_cor += 0.2;
	if (key == 124)
		data->z_cor -= 0.2;
	if (key == 53)
		exit (0);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data);
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
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1280, 720, "FdF_bonus");
	ft_draw(&data);
	mlx_key_hook(data.win_ptr, ft_key, &data);
	mlx_loop(data.mlx_ptr);
	ft_clear_data(&data);
	return (0);
}
