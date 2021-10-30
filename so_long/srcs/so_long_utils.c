/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:13:56 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 15:18:12 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_so_long.h"

int	ft_close(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	ft_free_data(data);
	exit (0);
}

int	ft_keys(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	if (key == W_KEY || key == S_KEY || key == D_KEY || key == A_KEY)
		ft_step(data, key, data->map);
	return (1);
}
