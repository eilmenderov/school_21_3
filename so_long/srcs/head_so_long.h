/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_so_long.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:09:40 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 16:50:29 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_SO_LONG_H
# define HEAD_SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct s_map
{
	size_t			width;
	size_t			height;
	struct s_data	*data;
}				t_map;

typedef struct s_pic
{
	void			*hero[4];
	void			*coin[4];
	void			*trap;
	void			*wall;
	void			*none;
	void			*exit;
	struct s_data	*data;
}				t_pic;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;

	t_map	*map;
	t_pic	*pic;
}				t_data;

/* 1/5 so_long_utils.c */
int	ft_init(int a);

#endif
