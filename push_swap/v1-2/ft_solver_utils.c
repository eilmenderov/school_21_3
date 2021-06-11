#include "head_push_swap.h"

int	ft_find_max(t_list *lst)
{
	t_list	*buf;
	int		max;

	buf = lst;
	max = buf->content;
	while (buf)
	{
		if (max < buf->content)
			max = buf->content;
		buf = buf->next;
	}
	return (max);
}

int	ft_find_min(t_list *lst)
{
	t_list	*buf;
	int		min;

	buf = lst;
	min = buf->content;
	while (buf)
	{
		if (min > buf->content)
			min = buf->content;
		buf = buf->next;
	}
	return (min);
}

int	ft_rot_dec(t_list *lst, int max, int min)
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
		if (buf->ind <= max && buf->ind >= min)
			last = i;
		if (!first && buf->ind <= max && buf->ind >= min)
			first = i;
		buf = buf->next;
		i++;
	}
	if (first <= ft_lstsize(lst) - last)
		return (1);
	return (-1);
}

int	ft_exist_elpush_max(t_data *data, int mid)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = data->b_beg;
	while (tmp)
	{
		if (tmp->ind >= mid)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_solve_bsev(t_data *data)
{
	while (ft_lstsize(data->a_beg) != data->size)
	{
		if (data->a_beg->ind - 1 == data->b_beg->ind)
			ft_push_el(data, 'a');
		else if (data->a_beg->ind == data->lstn)
		{
			ft_push_el(data, 'a');
			ft_swap_r(data->a_beg, data, 'a');
			data->lstn++;
		}
		else
			ft_swap_r(data->b_beg, data, 'b');
	}
}