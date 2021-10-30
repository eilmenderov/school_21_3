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

static void	ft_put_img(size_t x, size_t y, t_data *data, t_pic *pic)
{
	if (data->map->field[y][x] != '1')
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
}

void	ft_start_game(t_data *data)
{
	ft_draw_map(data);
	mlx_hook(data->win, 2, 0, ft_keys, data);
	mlx_hook(data->win, 17, 0l, ft_close, data);
	printf("Movements done 0\n");
	mlx_loop(data->mlx);
}
