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

void	ft_load_xmp(void *mlx, void **img, char *file)
{
	int	fl[2];

	*img = mlx_xpm_file_to_image(mlx, file, &fl[0], &fl[1]);
	if (!*img)
		ft_error(ft_strjoin("can not read xmp file ", file));
	if (fl[0] != PIC_SIZE || fl[0] != fl[1])
		ft_error(ft_strjoin("incorrect xmp size ", file));
}

void	ft_init_structs(t_data *data)
{
	t_pic	*pic;

	data->fl = 0;
	data->img = NULL;
	pic = malloc(sizeof(t_pic));
	if (!pic)
		ft_error("can't allocate memory(malloc)");
	ft_load_xmp(data->mlx, &pic->hero, "./xmp/hero.xpm");
	ft_load_xmp(data->mlx, &pic->wall, "./xmp/wall.xpm");
	ft_load_xmp(data->mlx, &pic->none, "./xmp/none.xpm");
	ft_load_xmp(data->mlx, &pic->exit, "./xmp/exit.xpm");
	ft_load_xmp(data->mlx, &pic->coin, "./xmp/coin.xpm");
	data->pic = pic;
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

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac != 2)
		ft_error("incorrect arguments, need only one");
	map.data = &data;
	data.map = &map;
	ft_parser(&map, av);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_error("can't initialize mlx");
	map.width *= PIC_SIZE;
	map.height *= PIC_SIZE;
	data.win = mlx_new_window(data.mlx, map.width, map.height, "so_long");
	if (!data.win)
		ft_error("can't create game window");
	ft_init_structs(&data);
	// ft_print(&data);
	ft_start_game(&data);
	// ft_free_data(&data);
	// sleep(10);
	return (0);
}
