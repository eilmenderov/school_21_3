/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:59:07 by vleida            #+#    #+#             */
/*   Updated: 2021/10/29 11:43:08 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_so_long.h"

static int	ft_animations(t_data *data)
{
	int	i;
	int	j;

	data->timer++;
	if (data->timer % 10)
	{
		i = -1;
		while (data->map->field[++i])
		{
			j = -1;
			while (data->map->field[i][++j])
			{
				if (data->map->field[i][j] == ENEMY)
				{
					mlx_put_image_to_window(data->mlx, data->win,
						data->pic->none, j * PIC_SIZE, i * PIC_SIZE);
					mlx_put_image_to_window(data->mlx, data->win,
						data->pic->enemy[data->timer / 10 % 3],
						j * PIC_SIZE, i * PIC_SIZE);
				}
			}
		}
	}
	mlx_do_sync(data->mlx);
	return (0);
}

static void	ft_put_img(size_t x, size_t y, t_data *data, t_pic *pic)
{
	if (data->map->field[y][x] != '1' && data->map->field[y][x] != ENEMY)
		mlx_put_image_to_window(data->mlx, data->win, pic->none,
			x * PIC_SIZE, y * PIC_SIZE);
	if (data->map->field[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, pic->wall,
			x * PIC_SIZE, y * PIC_SIZE);
	else if (data->map->field[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, pic->hero,
			x * PIC_SIZE, y * PIC_SIZE);
		data->p_x = x;
		data->p_y = y;
	}
	else if (data->map->field[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, pic->exit,
			x * PIC_SIZE, y * PIC_SIZE);
	else if (data->map->field[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, pic->coin,
			x * PIC_SIZE, y * PIC_SIZE);
	else if (data->map->field[y][x] == 'K')
		mlx_loop_hook(data->mlx, ft_animations, data);
}

static void	ft_draw_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			ft_put_img(x, y, data, data->pic);
			x++;
		}
		y++;
	}
	ft_draw_info(data, data->map);
}

void	ft_start_game(t_data *data)
{
	ft_draw_map(data);
	mlx_hook(data->win, 2, 0, ft_keys, data);
	mlx_hook(data->win, 17, 0l, ft_close, data);
	printf("Movements done 0\n");
	mlx_loop(data->mlx);
}
