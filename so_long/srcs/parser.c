#include "head_so_long.h"

static void	ft_init_map(t_map *map)
{
	mlx_get_screen_size(&map->max_width, &map->max_height);
	map->max_width = map->max_width / PIC_SIZE  - 1;
	map->max_height = map->max_height / PIC_SIZE - 1;
	map->width = 0;
	map->height = 0;
	map->hero = 0;
	map->coin = 0;
	map->moves = 0;
	map->field = NULL;
}

static void	ft_map_check(int fd, t_map *map, int gnl, int fl)
{
	char	*line;
	size_t	len;

	line = NULL;
	while (gnl)
	{
		gnl = ft_gnl_old(fd, &line);
		if (gnl < 0)
			ft_error("get_next_line error");
		len = ft_strlen_m(line, 0);
		if ((int)len > map->max_width)
			ft_error("map width too long for this scren resolution");
		if (!map->width)
			map->width = len;
		if (!len)
			fl = 1;
		if (len && (fl || map->width != len))
			ft_error("different line lenghts in the map");
		map->height += !fl;
		if ((int)map->height > map->max_height)
			ft_error("map height too tall for this scren resolution");
		free(line);
	}
	close(fd);
}

static void	ft_pool_field(char *file, t_map *map)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("can't open file(open)");
	map->field = malloc(sizeof(char *) * (map->height + 1));
	if (!map->field)
		ft_error("can't allocate memory(malloc)");
	line = NULL;
	i = 0;
	while (i < map->height)
	{
		if (ft_gnl_old(fd, &line) < 0)
			ft_error("get_next_line error");
		map->field[i] = line;
		line = NULL;
		i++;
	}
	map->field[i] = NULL;
	close(fd);
}

static void	ft_field_check(t_map *map)
{
	size_t	i;
	size_t	j;

	if (ft_how_many_char(map->field[0], WALL) != (int)map->width ||
		ft_how_many_char(map->field[map->height - 1], WALL) != (int)map->width)
		ft_error("hole in up or down walls");
	i = 1;
	while (i < map->height - 2 && map->hero < 2)
	{
		if (map->field[i][0] != WALL || map->field[i][map->width - 1] != WALL)
			ft_error("hole in left or right walls");
		map->hero += ft_how_many_char(map->field[i], HERO);
		map->coin += ft_how_many_char(map->field[i], COIN);
		j = 1;
		while (j < map->width - 2)
		{
			if (!ft_ch_for_coinc(map->field[i][j], "10PEC"))
				ft_error("incorrect symbol in the map");
			j++;
		}
		i++;
	}
	if (map->hero != 1)
		ft_error("check player in the map");
}

void	ft_parser(t_map *map, char **av)
{
	int	f_len;
	int	fd;

	f_len = ft_strlen_m(av[1], 0);
	if (f_len < 4 || ft_strncmp(av[1] + f_len - 4, ".ber", 5))
		ft_error("incorrect map name, need <map_name.ber>");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("file does not exist or access denied");
	ft_init_map(map);
	ft_map_check(fd, map, 1, 0);
	ft_pool_field(av[1], map);
	ft_field_check(map);
}