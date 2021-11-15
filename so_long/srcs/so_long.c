/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:09:35 by vleida            #+#    #+#             */
/*   Updated: 2021/11/15 15:40:32 by vleida           ###   ########.fr       */
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
	ft_load_xmp(data->mlx, &pic->hero_up, "./xmp/up.xpm");
	ft_load_xmp(data->mlx, &pic->hero_l, "./xmp/left.xpm");
	ft_load_xmp(data->mlx, &pic->hero_r, "./xmp/right.xpm");
	ft_load_xmp(data->mlx, &pic->wall, "./xmp/wall.xpm");
	ft_load_xmp(data->mlx, &pic->none, "./xmp/none.xpm");
	ft_load_xmp(data->mlx, &pic->exit, "./xmp/exit.xpm");
	ft_load_xmp(data->mlx, &pic->coin, "./xmp/coin.xpm");
	ft_load_xmp(data->mlx, &pic->enemy[0], "./xmp/enemy0.xpm");
	ft_load_xmp(data->mlx, &pic->enemy[1], "./xmp/enemy1.xpm");
	ft_load_xmp(data->mlx, &pic->enemy[2], "./xmp/enemy2.xpm");
	pic->empty = mlx_new_image(data->mlx, PIC_SIZE * 1.66, PIC_SIZE / 2);
	data->pic = pic;
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map && data->map->field)
	{
		while (data->map->field[i])
		{
			free(data->map->field[i]);
			i++;
		}
		free(data->map->field);
	}
	if (data->pic)
		free(data->pic);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac != 2)
		ft_error("incorrect arguments, need only one");
	map.data = &data;
	data.map = &map;
	data.bonus = 0;
	ft_parser(&map, av);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_error("can't initialize mlx");
	data.res_x = map.width * PIC_SIZE;
	data.res_y = map.height * PIC_SIZE;
	data.win = mlx_new_window(data.mlx, data.res_x, data.res_y, "so_long");
	if (!data.win)
		ft_error("can't create game window");
	ft_init_structs(&data);
	ft_start_game(&data);
	ft_free_data(&data);
	return (0);
}
