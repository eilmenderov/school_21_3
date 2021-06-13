#include "head_push_swap.h"

void	ft_mover_iterativ(t_data *data)
{
	int	mid;

	mid = data->arr[ft_find_mid(data->a_beg)];
	if (data->size == 6)
		mid = data->arr[1];
	while (ft_chek_lst(data->a_beg, mid, 's'))
	{
		if (data->a_beg->content <= mid)
			ft_push_el(data, 'b');
		else
		{
			if (ft_rot_dec(data->a_beg, mid) == 1)
				ft_swap_r(data->a_beg, data, 'a');
			else
				ft_swap_rrm(data->a_beg, data, 'a');
		}
	}
}

static void	ft_step_two_help(t_data *data)
{
	while (data->a_beg->ind == data->lstn)
	{
		ft_swap_r(data->a_beg, data, 'a');
		data->lstn++;
	}
	while (data->b_beg && data->b_beg->ind == data->lstn)
	{
		ft_push_el(data, 'a');
		ft_swap_r(data->a_beg, data, 'a');
		data->lstn++;
	}
	while (data->a_beg->ind == data->lstn)
	{
		ft_swap_r(data->a_beg, data, 'a');
		data->lstn++;
	}
	while (data->a_beg->next->ind == data->lstn)
	{
		ft_swap_s(data->a_beg, data, 'a');
		ft_push_el(data, 'a');
		data->lstn++;
		ft_step_two_help(data);
	}
}

static void	ft_step_two(t_data *data)
{
	int	mid;

	mid = data->arr[ft_find_mid(data->b_beg)];
	if (!ft_lstsize(data->b_beg) || mid <= 1)
		return ;
	while (ft_chek_lst(data->b_beg, mid, 'b') == 2)
	{
		if (data->b_beg->ind == data->lstn)
		{
			ft_push_el(data, 'a');
			ft_swap_r(data->a_beg, data, 'a');
			data->lstn++;
		}
		else if (data->b_beg->content >= mid)
			ft_push_el(data, 'a');
		else
			ft_swap_r(data->b_beg, data, 'b');
	}
	ft_step_two_help(data);
	if (ft_lstsize(data->b_beg))
		ft_step_two(data);
}

int	ft_rot_dec(t_list *lst, int nb)
{
	int		i;
	int		first;
	int		last;
	t_list	*buf;

	i = 0;
	first = 0;
	buf = lst;
	while (buf)
	{
		if (buf->content <= nb)
			last = i;
		if (!first && buf->content <= nb)
			first = i;
		buf = buf->next;
		i++;
	}
	if (first <= ft_lstsize(lst) - last)
		return (1);
	return (-1);
}

int	ft_find_mid(t_list *lst)
{
	t_list	*tmp;
	int		mx_ind;
	int		mn_ind;

	mx_ind = 0;
	mn_ind = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content == ft_find_max(lst))
			mx_ind = tmp->ind;
		if (tmp->content == ft_find_min(lst))
			mn_ind = tmp->ind;
		tmp = tmp->next;
	}
	if (ft_lstsize(lst) <= 2)
		return (0);
	return (mn_ind + ((mx_ind - mn_ind) / 2));
}

int	ft_chek_lst(t_list *lst, int mid, int bs)
{
	t_list	*buf;
	int		fl;

	if (!lst)
		return (0);
	buf = lst;
	fl = ft_lstsize(lst);
	if (fl < 3)
		return (0);
	while (buf)
	{
		if (buf->content <= mid && bs == 's')
			return (1);
		if (buf->content >= mid && bs == 'b')
			return (2);
		buf = buf->next;
	}
	return (0);
}

static void	ft_mover(t_data *data)
{
	int	mid;

	mid = data->arr[1];
	while (ft_chek_lst(data->a_beg, mid, 's'))
	{
		if (data->a_beg->content <= mid)
			ft_push_el(data, 'b');
		else
		{
			if (ft_rot_dec(data->a_beg, 1, data) == 1)
				ft_swap_r(data->a_beg, data, 'a');
			else
				ft_swap_rrm(data->a_beg, data, 'a');
		}
	}
}