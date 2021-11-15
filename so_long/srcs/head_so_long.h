/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_so_long.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:09:40 by vleida            #+#    #+#             */
/*   Updated: 2021/11/15 15:39:10 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_SO_LONG_H
# define HEAD_SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# define PIC_SIZE	64
# define T_COLOR	0x00FFAA

/* keys */
# define W_KEY		13
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2

/* map_symbols */
# define WALL		'1'
# define NONE		'0'
# define HERO		'P'
# define EXIT		'E'
# define COIN		'C'
# define ENEMY		'K'
# define SYMBOLS	"10PECK"

typedef struct s_map
{
	size_t			width;
	size_t			height;
	int				max_width;
	int				max_height;
	size_t			hero;
	size_t			coin;
	size_t			earn_coins;
	size_t			moves;
	size_t			exits;
	char			**field;
	struct s_data	*data;
}				t_map;

typedef struct s_pic
{
	void			*empty;
	void			*hero;
	void			*hero_up;
	void			*hero_l;
	void			*hero_r;
	void			*coin;
	void			*enemy[3];
	void			*wall;
	void			*none;
	void			*exit;
	struct s_data	*data;
}				t_pic;

typedef struct s_data
{
	int		fl;
	int		bonus;
	size_t	p_x;
	size_t	p_y;
	size_t	res_x;
	size_t	res_y;
	size_t	timer;
	void	*mlx;
	void	*win;
	void	*img;

	t_map	*map;
	t_pic	*pic;
}				t_data;

/* 3/5 moves.c */
void	ft_draw_info(t_data *data, t_map *map);
void	ft_step(t_data *data, int key, t_map *map);

/* 5/5 parser.c */
void	ft_parser(t_map *map, char **av);

/* 2/5 so_long_utils.c */
int		ft_close(t_data *data);
int		ft_keys(int key, t_data *data);

/* 5/5 so_long.c */
void	ft_error(char *msg);
void	ft_free_data(t_data *data);

/* 3/5 start_game.c*/
void	ft_start_game(t_data *data);

#endif
