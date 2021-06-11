#include "head_push_swap.h"

static void	ft_move_s_p(t_data *data, char *line)
{
	if (!line)
	{
		data->fl = -12;
		return ;
	}
	if (line[0] == 's' && line [1] == 'a' && line[2] == 0)
		ft_swap_s(data, 'a');
	else if (line[0] == 's' && line [1] == 'b' && line[2] == 0)
		ft_swap_s(data, 'b');
	else if (line[0] == 's' && line [1] == 's' && line[2] == 0)
		ft_swap_ss(data);
	else if (line[0] == 'p' && line [1] == 'a' && line[2] == 0)
		ft_push_el(data, 'a');
	else if (line[0] == 'p' && line [1] == 'b' && line[2] == 0)
		ft_push_el(data, 'b');
	else
		data->fl = -13;
}

static void	ft_move_r(t_data *data, char *line)
{
	if (!line)
	{
		data->fl = -10;
		return ;
	}
	if (line [1] == 'a' && line[2] == 0)
		ft_swap_r(data, 'a');
	else if (line [1] == 'b' && line[2] == 0)
		ft_swap_r(data, 'b');
	else if (line [1] == 'r' && line[2] == 0)
		ft_swap_rr(data);
	else if (line [1] == 'r' && line[2] == 'a' && line[3] == 0)
		ft_swap_rrm(data, 'a');
	else if (line [1] == 'r' && line[2] == 'b' && line[3] == 0)
		ft_swap_rrm(data, 'b');
	else if (line [1] == 'r' && line[2] == 'r' && line[3] == 0)
		ft_swap_rrr(data);
	else
		data->fl = -11;
}

static void	ft_parc_solut(t_data *data, char *line, int rdr)
{
	if (!line)
	{
		if (rdr)
			data->fl = -8;
		return ;
	}
	if (line[0] == 's' || line[0] == 'p')
		ft_move_s_p(data, line);
	else if (line[0] == 'r')
		ft_move_r(data, line);
	else
		data->fl = -9;
}

static void	ft_chek_solve(t_data *data)
{
	char	*line;
	int		rdr;

	line = NULL;
	data->size = ft_lstsize(data->a_beg);
	rdr = 1;
	while (rdr && rdr != -1 && !data->fl)
	{
		rdr = get_next_line(0, &line);
		if (line && line[0] != 0)
			ft_parc_solut(data, line, rdr);
		free (line);
		line = NULL;
	}
	if (line)
		free (line);
	if (!data->fl)
	{
		if (ft_chek_alst(data))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*temp;
	int		i;

	if (ac == 1)
		return (0);
	ft_init_data(&data);
	if (ac == 2)
		av = ft_split_m(av[1], ' ', &ac, &data);
	i = 1;
	if (data.chek == 2)
		i = 0;
	while (i < ac && !data.fl)
	{
		temp = ft_lstnew(ft_atoi_m(av[i], &data));
		ft_lstadd_back(&data.a_beg, temp);
		i++;
	}
	if (data.chek == 2)
		ft_free_all(av, data.size);
	ft_creat_arr(&data);
	ft_sort_chek_arr(&data);
	ft_chek_solve(&data);
	ft_clear_memory(&data);
	return (0);
}
