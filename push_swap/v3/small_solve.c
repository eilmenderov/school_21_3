#include "head_push_swap.h"

int	ft_find_ind_mxmn(t_list *lst, int mnmx)
{
	t_list	*tmp;
	int		max;
	int		min;

	tmp = lst;
	max = lst->ind;
	min = lst->ind;
	while (tmp)
	{
		if (max < tmp->ind)
			max = tmp->ind;
		if (min > tmp->ind)
			min = tmp->ind;
		tmp = tmp->next;
	}
	if (mnmx > 0)
		return (max);
	return (min);
}

static void	ft_solve_three(t_data *data, int key)
{
	if (key == 'a')
		data->buf = data->a_beg;
	if (key == 'b')
		data->buf = data->b_beg;
	if (ft_lstsize(data->buf) != 3 || ft_chek_sort(data, 0, 0, key) == 1)
		return ;
	if (data->buf->ind == ft_find_ind_mxmn(data->buf, -1))
	{
		ft_swap_s(data, key);
		ft_swap_r(data, key);
	}
	else if (data->buf->ind == ft_find_ind_mxmn(data->buf, 1))
	{
		ft_swap_r(data, key);
		if (!ft_chek_sort(data, 0, 0, key))
			ft_swap_s(data, key);
	}
	else if (data->buf->next->ind == ft_find_ind_mxmn(data->buf, 1))
		ft_swap_rrm(data, key);
	else
		ft_swap_s(data, key);
}

static void	ft_solve_for(t_data *data, int key)
{
	int	tgt;

	if (key == 'a')
		data->buf = data->a_beg;
	if (key == 'b')
		data->buf = data->b_beg;
	tgt = ft_find_ind_mxmn(data->buf, -1);
	if (data->buf->ind == tgt)
	{
		if (key == 'a')
			ft_push_el(data, 'b');
		else
			ft_push_el(data, 'a');
		ft_solve_three(data, key);
		ft_push_el(data, key);
	}
	else
	{
		if (ft_short_way(data, key, tgt, tgt) == 1)
			ft_swap_r(data, key);
		else
			ft_swap_rrm(data, key);
		ft_solve_for(data, key);
	}
}

static void	ft_solve_five(t_data *data, int key)
{
	t_list	*lst;
	int		min;

	if (key == 'a')
		lst = data->a_beg;
	if (key == 'b')
		lst = data->b_beg;
	min = ft_find_ind_mxmn(lst, -1);
	if (lst->ind != min && ft_lstsize(lst) > 4)
	{
		if (ft_short_way(data, key, min, min) == 1)
			ft_swap_r(data, key);
		else
			ft_swap_rrm(data, key);
		ft_solve_five(data, key);
		return ;
	}
	if (key == 'a')
		ft_push_el(data, 'b');
	else
		ft_push_el(data, 'a');
	ft_solve_for(data, key);
	ft_push_el(data, key);
}

void	ft_small_solve(t_data *data, int key)
{
	t_list	*lst;

	if (key == 'a')
		lst = data->a_beg;
	if (key == 'b')
		lst = data->b_beg;
	if (ft_chek_sort(data, 0, 0, key) == 1)
		return ;
	if (ft_lstsize(lst) == 2)
		ft_swap_s(data, key);
	if (ft_lstsize(lst) == 3)
		ft_solve_three(data, key);
	if (ft_lstsize(lst) == 4)
		ft_solve_for(data, key);
	if (ft_lstsize(lst) == 5)
		ft_solve_five(data, key);
}
