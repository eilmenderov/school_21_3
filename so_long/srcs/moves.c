/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:20:32 by vleida            #+#    #+#             */
/*   Updated: 2021/11/15 15:43:51 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_so_long.h"

static void	ft_change_pos(t_data *data, size_t *pos, void *pic, int fl)
{
	data->map->field[data->p_y][data->p_x] = NONE;
	mlx_put_image_to_window(data->mlx, data->win, data->pic->none,
		data->p_x * PIC_SIZE, data->p_y * PIC_SIZE);
	if (fl == 1)
		*pos = *pos + 1;
	else if (fl == -1)
		*pos = *pos - 1;
	if (data->map->field[data->p_y][data->p_x] == ENEMY)
		exit(printf("Game Over, you lose =(\n"));
	data->map->field[data->p_y][data->p_x] = HERO;
	mlx_put_image_to_window(data->mlx, data->win, data->pic->none,
		data->p_x * PIC_SIZE, data->p_y * PIC_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, pic,
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
	ft_draw_info(map->data, map);
	return (0);
}

void	ft_draw_info(t_data *data, t_map *map)
{
	char	*msg;

	if (!data->bonus)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->pic->empty,
		PIC_SIZE / 3, PIC_SIZE / 16);
	msg = ft_strjoin_m("MOVES: ", ft_itoa(map->moves), 2);
	mlx_string_put(data->mlx, data->win, PIC_SIZE / 2, PIC_SIZE / 4,
		T_COLOR, msg);
	free(msg);
	msg = ft_strjoin_m("COINS: ", ft_itoa(map->earn_coins), 2);
	mlx_string_put(data->mlx, data->win, PIC_SIZE / 2, PIC_SIZE / 2,
		T_COLOR, msg);
	free(msg);
}

void	ft_step(t_data *data, int key, t_map *map)
{
	if (key == W_KEY && data->p_y != 0
		&& !ft_check_new_pos(map, data->p_x, data->p_y - 1))
		ft_change_pos(data, &data->p_y, data->pic->hero_up, -1);
	if (key == S_KEY && data->p_y != map->height - 1
		&& !ft_check_new_pos(map, data->p_x, data->p_y + 1))
		ft_change_pos(data, &data->p_y, data->pic->hero, 1);
	if (key == A_KEY && data->p_x != 0
		&& !ft_check_new_pos(map, data->p_x - 1, data->p_y))
		ft_change_pos(data, &data->p_x, data->pic->hero_l, -1);
	if (key == D_KEY && data->p_x != map->width - 1
		&& !ft_check_new_pos(map, data->p_x + 1, data->p_y))
		ft_change_pos(data, &data->p_x, data->pic->hero_r, 1);
}
