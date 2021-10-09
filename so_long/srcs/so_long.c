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

void	ft_init_structs(t_data *data, t_map *map)
{
	// ft_init_data(data); // add texture and filled mlx window
	data->map  = map;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac != 2)
	{
		ft_putendl_fd("Error", 2);
		exit (1);
	}
	(void)av;
	// ft_parcer(&map, ac, av);
	ft_init_structs(&data, &map);
	// ft_start_game(&data);
	return (0);
}
