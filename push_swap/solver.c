#include "head_push_swap.h"

static void	ft_move_tog(t_data *data, int inda, int indb, int fl)
{
	while (data->a_beg->ind != inda && data->b_beg->ind != indb)
	{
		if (fl == 1)
			ft_swap_rr(data);
		else
			ft_swap_rrr(data);
	}
}

static void	ft_push_right(t_data *data)
{
	int	indb;
	int	inda;
	int	sha;
	int	shb;

	indb = ft_second_step(data);
	inda = ft_find_unit(data, indb, 0, 0);
	shb = ft_short_way(data, 'b', indb, indb);
	sha = ft_short_way(data, 'a', inda, inda);
	if (sha == shb)
		ft_move_tog(data, inda, indb, sha);
	while (data->b_beg->ind != indb)
	{
		if (shb == 1)
			ft_swap_r(data, 'b');
		else
			ft_swap_rrm(data, 'b');
	}
	while (data->a_beg->ind != inda)
	{
		if (sha == 1)
			ft_swap_r(data, 'a');
		else
			ft_swap_rrm(data, 'a');
	}
}

void	ft_solver(t_data *data)
{
	while (ft_lstsize(data->b_beg))
	{
		ft_push_right(data);
		ft_push_el(data, 'a');
	}
	while (data->a_beg->ind != 0)
	{
		if (ft_short_way(data, 'a', 0, 0) == 1)
			ft_swap_r(data, 'a');
		else
			ft_swap_rrm(data, 'a');
	}
}
