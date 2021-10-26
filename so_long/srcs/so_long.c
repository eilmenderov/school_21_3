/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:09:35 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 16:48:18 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_so_long.h"

void	ft_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	ft_init_structs(t_data *data, t_map *map)
{
	// ft_init_data(data); // add texture and filled mlx window
	data->map  = map;
}

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

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->field[i])
	{
		free(data->map->field[i]);
		i++;
	}
	free(data->map->field);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac != 2)
		ft_error("incorrect arguments, need only one");
	map.data = &data;
	ft_parser(&map, av);
	ft_init_structs(&data, &map);
	ft_print(&data);
	// ft_start_game(&data);
	ft_free_data(&data);
	sleep(10);
	return (0);
}
