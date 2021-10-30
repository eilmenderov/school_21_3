#include "head_so_long.h"

void	ft_print(t_data *data)
{
	int	i;

	printf("============== data ==============\n");
	printf("mlx: %p   win: %p   img: %p\n", data->mlx, data->win, data->img);
	printf("============== map ===============\n");
	printf("width:  %zu   max_width:  %d\n", data->map->width, data->map->max_width);
	printf("height: %zu   max_height: %d\n", data->map->height, data->map->max_height);
	printf("player: %zu coins: %zu moves: %zu\n", data->map->hero, data->map->coin, data->map->moves);
	printf("============== field =============\n");
	i = 0;
	while (data->map->field[i])
	{
		printf("%s\n", data->map->field[i]);
		i++;
	}
	printf("============== end ===============\n");
}
