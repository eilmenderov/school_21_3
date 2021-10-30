#include "head_so_long.h"

static void	ft_change_pos(t_data *data, size_t *pos, t_map *map, int fl)
{
	map->field[data->p_y][data->p_x] = NONE;
	mlx_put_image_to_window(data->mlx, data->win, data->pic->none,
		data->p_x * PIC_SIZE, data->p_y * PIC_SIZE);
	if (fl == 1)
		*pos = *pos + 1;
	else if (fl == -1)
		*pos = *pos - 1;
	map->field[data->p_y][data->p_x] = HERO;
	mlx_put_image_to_window(data->mlx, data->win, data->pic->none,
		data->p_x * PIC_SIZE, data->p_y * PIC_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->pic->hero,
		data->p_x * PIC_SIZE, data->p_y * PIC_SIZE);
}

static int	ft_check_new_pos(t_map *map, size_t x, size_t y)
{
	if (map->field[y][x] == WALL)
		return (1);
	if (map->field[y][x] == EXIT && map->earn_coins >= map->coin)
	{
		map->moves += 1;
		printf("Movements done %zu\nYou WIN!!!\n", map->moves);
		ft_close(map->data);
	}
	if (map->field[y][x] == EXIT && map->earn_coins != map->coin)
		return (1);
	if (map->field[y][x] == COIN)
		map->earn_coins += 1;
	map->moves += 1;
	printf("Movements done %zu\n", map->moves);
	return (0);
}

void	ft_step(t_data *data, int key, t_map *map)
{
	if (key == W_KEY && data->p_y != 0
		&& !ft_check_new_pos(map, data->p_x, data->p_y - 1))
		ft_change_pos(data, &data->p_y, map, -1);
	if (key == S_KEY && data->p_y != map->height - 1
		&& !ft_check_new_pos(map, data->p_x, data->p_y + 1))
		ft_change_pos(data, &data->p_y, map, 1);
	if (key == A_KEY && data->p_x != 0
		&& !ft_check_new_pos(map, data->p_x - 1, data->p_y))
		ft_change_pos(data, &data->p_x, map, -1);
	if (key == D_KEY && data->p_x != map->width - 1
		&& !ft_check_new_pos(map, data->p_x + 1, data->p_y))
		ft_change_pos(data, &data->p_x, map, 1);
}
