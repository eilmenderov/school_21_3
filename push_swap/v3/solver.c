#include "head_push_swap.h"

static void	ft_mover_iterativ(t_data *data)
{
	int		mid;
	t_list	*lst;

	mid = ((data->size + data->lstn + 1) / 2);
	if (mid >= data->size)
		return ;
	while (ft_exist_elpush_min(data, mid, 'a'))
	{
		lst = data->a_beg;
		if (lst->ind < mid && lst->ind >= data->lstn)
			ft_push_el(data, 'b');
		else
			ft_swap_r(data, 'a');
	}
}

static void	ft_delim(t_data *data)
{
	int		mid;

	while (ft_lstsize(data->b_beg) > 3)
	{
		mid = ft_find_mid_index(data, 'b');
		while (ft_exist_elpush_max(data, mid, 'b'))
		{
			if (data->b_beg->ind == data->lstn)
			{
				ft_push_el(data, 'a');
				ft_swap_r(data, 'a');
				data->lstn++;
			}
			else if (data->b_beg->ind >= mid)
				ft_push_el(data, 'a');
			else
				ft_swap_rrm(data, 'b');
		}
		while (data->b_beg && data->b_beg->ind == data->lstn)
		{
			ft_push_el(data, 'a');
			ft_swap_r(data, 'a');
			data->lstn++;
		}
	}
}

static int	ft_solve_bthree(t_data *data)
{
	t_list	*lst;

	if (ft_chek_sort(data, 0, 0, 'b') == 1)
		return (1);
	if (ft_chek_sort(data, 0, 0, 'b') == -1)
		return (-1);
	lst = data->b_beg;
	if (lst->ind == ft_find_ind_mxmn(lst, 1)
		|| lst->ind == ft_find_ind_mxmn(lst, -1))
		ft_swap_r(data, 'b');
	else
	{
		if (data->a_beg->next->ind < data->a_beg->ind)
			ft_swap_ss(data);
		else
			ft_swap_s(data, 'b');
	}
	if (ft_chek_sort(data, 0, 0, 'b') == 1)
		return (1);
	if (ft_chek_sort(data, 0, 0, 'b') == -1)
		return (-1);
	return (0);
}

static void	ft_push_bth(t_data *data, int fl)
{
	if (fl == 1)
	{
		while (data->b_beg)
		{
			ft_push_el(data, 'a');
			ft_swap_r(data, 'a');
			data->lstn++;
		}
		while (data->a_beg && data->a_beg->ind == data->lstn)
		{
			ft_swap_r(data, 'a');
			data->lstn++;
		}
	}
	else if (fl == -1)
	{
		while (data->b_beg)
			ft_push_el(data, 'a');
		while (data->a_beg && data->a_beg->ind == data->lstn)
		{
			ft_swap_r(data, 'a');
			data->lstn++;
		}
	}
}

static int	ft_solve_atoo(t_data *data)
{
	int		i;
	t_list	*lst;

	while (ft_finish_chek(data) && (data->a_beg->ind == data->lstn
			|| data->a_beg->next->ind == data->lstn))
	{
		if (data->a_beg->next->ind == data->lstn)
			ft_swap_bs(data);
		else if (data->a_beg->ind == data->lstn)
		{
			ft_swap_br(data);
			data->lstn++;
		}
	}
	i = 0;
	lst = data->a_beg;
	while (ft_finish_chek(data) && lst && i < 7)
	{
		i++;
		if (lst->ind > data->lstn + 5)
			break ;
		lst = lst->next;
	}
	return (i);
}

static void	ft_solve_ath(t_data *data, int fl)
{
	if (!ft_finish_chek(data))
		return ;
	while (ft_lstsize(data->b_beg) < 3)
	{
		if (data->a_beg->ind == data->lstn)
		{
			ft_swap_br(data);
			data->lstn++;
		}
		else
			ft_push_el(data, 'b');
	}
	if (data->a_beg->next->ind < data->a_beg->ind)
		ft_swap_bs(data);
	ft_small_solve(data, 'b');
}

static void	ft_mover(t_data *data)
{
	while ((data->b_beg && data->b_beg->ind == data->lstn) || data->a_beg->ind
		== data->lstn || data->a_beg->next->ind == data->lstn)
	{
		if (data->a_beg->ind == data->lstn)
		{
			ft_swap_br(data);
			data->lstn++;
		}
		else if (data->a_beg->next->ind == data->lstn)
			ft_swap_bs(data);
		else if (data->b_beg && data->b_beg->ind == data->lstn)
		{
			ft_push_el(data, 'a');
			ft_swap_br(data);
			data->lstn++;
		}
	}
	while (data->a_beg->mvs && data->a_beg->ind != 0)
	{
		if (data->a_beg->ind == data->lstn)
		{
			ft_swap_br(data);
			data->lstn++;
		}
		else
			ft_push_el(data, 'b');
	}
}

void	ft_solver(t_data *data)
{
	int	fl;

	if (data->size < 6)
	{
		ft_small_solve(data, 'a');
		return ;
	}
	while (ft_finish_chek(data))
	{
		ft_mover_iterativ(data);
		ft_move_back(data);
		while (ft_lstsize(data->b_beg) >= 4)
		{
			ft_delim(data);
			if (ft_lstsize(data->a_beg) == 3)
				ft_small_solve(data, 'a');
			if (ft_lstsize(data->b_beg) <= 3)
				ft_push_bth(data, ft_solve_bthree(data));
			fl = ft_solve_atoo(data);
			if (fl <= 3)
				ft_solve_ath(data, fl);
			ft_mover(data);
		}
	}
}
