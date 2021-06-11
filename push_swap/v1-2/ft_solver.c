#include "head_push_swap.h"

static int	ft_find_mid_index(t_list *lst, t_data *data)
{
	t_list	*tmp;
	int		maxin;
	int		rez;

	maxin = data->lstn;
	tmp = lst;
	while (tmp)
	{
		if (maxin < tmp->ind)
			maxin = tmp->ind;
		tmp = tmp->next;
	}
	rez = ((maxin - data->lstn + 1) / 2) + 1;
	return (rez);
}

static void	ft_pb_sort(t_data *data)
{
	int	mid;

	if (!ft_lstsize(data->b_beg))
		return ;
	if (ft_lstsize(data->b_beg) <= 2)
		ft_solve_bsm(data);
	mid = ft_find_mid_index(data->b_beg, data);
	while (ft_exist_elpush_max(data, mid))
	{
		if (data->b_beg->ind <= data->lstn)
			ft_pb_impr(data, mid);
		else if (data->b_beg->ind > mid)
			ft_push_el(data, 'a');
		else
			ft_best_mov(data);
	}
	if (ft_lstsize(data->b_beg) > 0)
		ft_pb_sort(data);
	while (data->a_beg->ind == data->lstn)
	{
		ft_swap_r(data->a_beg, data, 'a');
		data->lstn++;
	}
}

static int	ft_exist_elpush_min(t_data *data, int mid)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = data->a_beg;
	while (tmp)
	{
		if (tmp->ind <= mid && tmp->ind >= data->lstn)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	ft_mover_iterativ(t_data *data)
{
	int		mid;
	t_list	*lst;

	mid = ((data->size + data->lstn) / 2);
	if (mid > data->size)
		return ;
	while (ft_exist_elpush_min(data, mid))
	{
		lst = data->a_beg;
		if (lst->ind <= mid && lst->ind >= data->lstn)
			ft_push_el(data, 'b');
		else
			ft_mov_impr(data, mid);
	}
	if (ft_lstsize(data->a_beg) < 6)
	{
		ft_small_solve(data);
		if (ft_lstsize(data->b_beg))
			ft_solve_bsev(data);
	}
}

void	ft_solver(t_data *data)
{
	int	fl;

	if (data->size < 6)
	{
		ft_small_solve(data);
		return ;
	}
	fl = 1;
	while (ft_finish_chek(data))
	{
		if (fl == 0)
		{
			ft_mover_iterativ(data);
			ft_move_back(data);
		}
		if (ft_finish_chek(data))
		{
			fl = 1;
			ft_pb_sort(data);
			while (data->a_beg->mvs && ft_finish_chek(data))
				ft_push_el(data, 'b');
			if (!data->a_beg->mvs && !ft_lstsize(data->b_beg))
				fl = 0;
		}
	}
}
