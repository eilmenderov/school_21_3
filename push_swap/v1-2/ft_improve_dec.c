#include "head_push_swap.h"

void	ft_mov_impr(t_data *data, int mid)
{
	// if (ft_rot_dec(data->a_beg, mid, data->lstn) == 1)
	// {
		// if (data->b_beg && data->b_beg->next
		// 	&& data->b_beg->next->ind < data->b_beg->ind)
		// 	ft_swap_rr(data);
		// else
			ft_swap_r(data->a_beg, data, 'a');
	// }
	// else
	// {
	// 	if (data->b_beg && data->b_beg->next
	// 		&& ft_lstlast(data->b_beg)->ind < data->b_beg->ind)
	// 		ft_swap_rrr(data);
	// 	else
	// 		ft_swap_rrm(data->a_beg, data, 'a');
	// }
}

void	ft_pb_impr(t_data *data, int mid)
{
	if (mid > 0)
	{
		if (data->b_beg->ind == data->lstn)
		{
			ft_push_el(data, 'a');
			data->lstn++;
			if (data->b_beg && data->b_beg->ind < mid
				&& data->b_beg->ind != data->lstn + 1)
				ft_swap_rr(data);
			else
				ft_swap_r(data->a_beg, data, 'a');
		}
		else
			ft_swap_r(data->b_beg, data, 'b');
	}
	else
	{
		if (data->b_beg && data->b_beg->next->ind < data->b_beg->ind)
			ft_swap_rr(data);
		else
			ft_swap_r(data->a_beg, data, 'a');
		data->lstn++;
	}
}

void	ft_solve_bsm(t_data *data)
{
	data->chek++;
	if (ft_lstsize(data->b_beg) == 2 && ft_chek_sort(data->b_beg, data) != 1)
	{
		ft_pb_impr(data, 2);
		ft_pb_impr(data, 2);
	}
	if (ft_lstsize(data->b_beg) == 1)
	{
		ft_push_el(data, 'a');
		ft_swap_r(data->a_beg, data, 'a');
		data->lstn++;
	}
}

void	ft_best_mov(t_data *data)
{
	if (ft_rot_dec(data->b_beg, data->lstn, data->lstn) == 1)
		ft_swap_r(data->b_beg, data, 'b');
	else
		ft_swap_rrm(data->b_beg, data, 'b');
}
