#include "head_push_swap.h"

static void	ft_solve_three(t_data *data)
{
	if (data->a_beg->content == ft_find_min(data->a_beg))
	{
		ft_swap_r(data->a_beg, data, 'a');
		ft_swap_s(data->a_beg, data, 'a');
		ft_swap_rrm(data->a_beg, data, 'a');
	}
	else if (data->a_beg->content == ft_find_max(data->a_beg))
	{
		ft_swap_r(data->a_beg, data, 'a');
		if (!ft_chek_sort(data->a_beg, data))
			ft_swap_s(data->a_beg, data, 'a');
	}
	else if (data->a_beg->next->content == ft_find_max(data->a_beg))
		ft_swap_rrm(data->a_beg, data, 'a');
	else
		ft_swap_s(data->a_beg, data, 'a');
}

static void	ft_solve_for(t_data *data)
{
	if (data->a_beg->content == ft_find_max(data->a_beg))
	{
		ft_push_el(data, 'b');
		ft_small_solve(data);
		ft_push_el(data, 'a');
		ft_swap_r(data->a_beg, data, 'a');
	}
	else if (data->a_beg->content == ft_find_min(data->a_beg))
	{
		ft_push_el(data, 'b');
		ft_small_solve(data);
		ft_push_el(data, 'a');
	}
	else
	{
		if (ft_rot_dec(data->a_beg, 1, data->lstn) == 1)
			ft_swap_r(data->a_beg, data, 'a');
		else
			ft_swap_rrm(data->a_beg, data, 'a');
		ft_small_solve(data);
	}
}

static void	ft_solve_five(t_data *data)
{
	int		min;
	int		lstind;
	t_list	*lst;

	min = ft_find_min(data->a_beg);
	lst = data->a_beg;
	while (lst && lst->content != min)
		lst = lst->next;
	lstind = lst->ind;
	while (data->a_beg->content != min)
	{
		if (ft_rot_dec(data->a_beg, lstind, data->lstn) == 1)
			ft_swap_r(data->a_beg, data, 'a');
		else
			ft_swap_rrm(data->a_beg, data, 'a');
	}
	ft_push_el(data, 'b');
	ft_small_solve(data);
	ft_push_el(data, 'a');
}

void	ft_small_solve(t_data *data)
{
	if (ft_chek_sort(data->a_beg, data) == 1)
		return ;
	if (ft_lstsize(data->a_beg) == 2)
		ft_swap_s(data->a_beg, data, 'a');
	if (ft_lstsize(data->a_beg) == 3)
		ft_solve_three(data);
	if (ft_lstsize(data->a_beg) == 4)
		ft_solve_for(data);
	if (ft_lstsize(data->a_beg) == 5)
		ft_solve_five(data);
}

void	ft_move_back(t_data *data)
{
	int		i;
	t_list	*tmp;

	if (!ft_finish_chek(data))
		return ;
	i = 0;
	tmp = data->a_beg;
	while (tmp)
	{
		i = i + tmp->mvs;
		tmp = tmp->next;
	}
	if (i == 0)
		return ;
	while (ft_lstlast(data->a_beg)->ind != data->lstn - 1)
	{
		if (data->b_beg->ind != data->lstn)
			ft_swap_rrr(data);
		else
			ft_swap_rrm(data->a_beg, data, 'a');
	}
}
