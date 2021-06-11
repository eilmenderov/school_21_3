#include "head_push_swap.h"

static int	ft_true_false_s(t_list *abeg, int kmax, int *k, int rez)
{
	int		i;
	int		indl;
	int		mstep;
	t_list	*lst;

	while (*k < kmax)
	{
		lst = abeg->next;
		indl = abeg->ind;
		i = 0;
		while (lst)
		{
			if (lst->ind > indl && lst->ind <= indl + *k)
			{
				i++;
				indl = lst->ind;
			}
			lst = lst->next;
		}
		ft_tfs_helper(&i, &rez, &mstep, *k);
		*k = *k + 1;
	}
	*k = mstep;
	return (rez);
}

static int	ft_true_false_m(t_data *data)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		step;
	int		start_ind;

	if (!data->a_beg)
		return (0);
	start_ind = data->a_beg->ind;
	max = ft_true_false_s(data->a_beg, (data->size / 10) + 3, &data->chek, 0);
	tmp = data->a_beg->next;
	i = 0;
	while (tmp)
	{
		step = 0;
		i = ft_true_false_s(tmp, (data->size / 10) + 3, &step, 0);
		if (i > max)
		{
			start_ind = tmp->ind;
			max = i;
			data->chek = step;
		}
		tmp = tmp->next;
	}
	return (start_ind);
}

static void	ft_true_false(t_data *data)
{
	int		start;
	int		step;
	t_list	*lst;

	data->chek = 0;
	start = ft_true_false_m(data);
	step = data->chek;
	lst = data->a_beg;
	while (lst)
	{
		if (lst->ind == start)
			break ;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->ind >= start && lst->ind <= start + step)
		{
			lst->des = 1;
			start = lst->ind;
		}
		lst = lst->next;
	}
}

static int	ft_eelpush(t_data *data)
{
	t_list	*lst;

	lst = data->a_beg;
	while (lst)
	{
		if (!lst->des)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_first_step(t_data *data, t_list *tmp, int prev)
{
	ft_true_false(data);
	prev = 0;
	while (data->a_beg && ft_eelpush(data))
	{
		tmp = data->a_beg;
		if (tmp->next && tmp->des && !tmp->next->des && tmp->ind
			> tmp->next->ind && tmp->next->ind > prev)
		{
			ft_swap_s(data, 'a');
			data->a_beg->des = 1;
		}
		else if (tmp->next && !tmp->des && tmp->next->des && tmp->ind
			> tmp->next->ind && tmp->ind < ft_next_tfind(tmp))
		{
			data->a_beg->des = 1;
			ft_swap_s(data, 'a');
		}
		else if (!tmp->des)
			ft_push_el(data, 'b');
		else
		{
			prev = tmp->ind;
			ft_swap_r(data, 'a');
		}
	}
}
