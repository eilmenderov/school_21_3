#include "head_so_long.h"

int	ft_keys(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	(void)data;
	// if (key == 13 || key == 1 || key == 2 || key == 0)
	// 	ft_step(data, key);
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

int	ft_close(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

void	ft_put_img(size_t x, size_t y, t_data *data, t_map *map)
{
	size_t	i;
	size_t	j;

	i = x / PIC_SIZE;
	j = y / PIC_SIZE;
	if (map->field[j][i] != '1')
		mlx_put_image_to_window(data->mlx, data->win, data->pic->none, x, y);
	if (map->field[j][i] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->pic->wall, x, y);
	else if (map->field[j][i] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->pic->hero, x, y);
	else if (map->field[j][i] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->pic->exit, x, y);
	else if (map->field[j][i] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->pic->coin, x, y);
}

void	ft_draw_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			ft_put_img(x, y, data, data->map);
			x += PIC_SIZE;
		}
		y += PIC_SIZE;		
	}
}

void	ft_start_game(t_data *data)
{
	ft_draw_map(data);
	mlx_key_hook(data->win, ft_keys, data);
	mlx_hook(data->win, 17, 0l, ft_close, data);
	mlx_string_put(data->mlx, data->win, 27, 37, 0x0000000f, "0");
	printf("Movements done %s\n", "0");
	mlx_loop(data->mlx);
}
