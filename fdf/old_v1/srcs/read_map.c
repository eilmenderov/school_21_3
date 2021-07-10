#include "head_fdf.h"

static void	ft_get_h_w(t_data *data, int fd)
{
	char	*line;
	int		gnl;

	line = NULL;
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == -1)
			break ;
		if (data->widt == 0)
			data->widt = ft_count_words(line, ' ');
		data->heig++;
		if (line)
			free(line);
		line = NULL;
	}
	data->heig--;
	if (data->heig <= 0 || data->widt <= 0 || gnl == -1)
		data->erfl = -2;
}

static void	ft_clear_split_line(char *line, char **av, int i)
{
	if (line)
	{
		free (line);
		line = NULL;
	}
	while (av && av[i])
	{
		free (av[i]);
		av[i] = NULL;
		i++;
	}
	if (av)
	{
		free (av);
		av = NULL;
	}
}

static void	ft_fill_arr(int **mas, t_data *data, int gnl, int fd)
{
	char	*line;
	char	**av;
	int		i;
	int		j;

	line = NULL;
	i = 0;
	while (gnl == 1 && !data->erfl && i < data->heig)
	{
		gnl = get_next_line(fd, &line);
		av = ft_split(line, ' ');
		mas[i] = malloc(sizeof(int) * (data->widt));
		if (!mas[i])
			exit (-5);
		j = 0;
		while (av[j] && !data->erfl)
		{
			mas[i][j] = ft_atoi_m(av[j], data);
			j++;
		}
		ft_clear_split_line(line, av, 0);
		i++;
	}
	data->arr = mas;
}

static void	ft_pull_data(t_data *data, int i, int j)
{
	while (i < data->heig)
	{
		j = 0;
		while (j < data->widt)
		{
			if (data->arr[i][j] < data->minz)
				data->minz = data->arr[i][j];
			if (data->arr[i][j] > data->maxz)
				data->maxz = data->arr[i][j];
			j++;
		}
		i++;
	}
}

void	ft_read_map(t_data *data, char *fname)
{
	int	fd;
	int	**arr;
	int	i;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		exit(-1);
	ft_get_h_w(data, fd);
	close (fd);
	arr = malloc(sizeof(arr) * (data->heig));
	if (!arr)
		exit(-4);
	i = 0;
	while (i < data->heig)
	{
		arr[i] = NULL;
		i++;
	}
	fd = open(fname, O_RDONLY);
	ft_fill_arr(arr, data, 1, fd);
	ft_pull_data(data, 0, 0);
	close (fd);
}
