#include "head_push_swap.h"

static void	ft_swap_numb(int *a, int *b)
{
	int	buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

static void	ft_sort_quick(int *arr, int lf, int rt)
{
	int	mid;
	int	i;
	int	j;

	i = lf;
	j = rt;
	mid = arr[(lf + rt) / 2];
	while (i <= j)
	{
		while (arr[i] < mid)
			i++;
		while (arr[j] > mid)
			j--;
		if (i <= j)
		{
			ft_swap_numb(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	if (lf < j)
		ft_sort_quick(arr, lf, j);
	if (rt > i)
		ft_sort_quick(arr, i, rt);
}

static void	ft_add_index(t_data *data)
{
	t_list	*lst;
	int		i;

	lst = data->a_beg;
	while (lst)
	{
		i = 0;
		while (data->arr[i] != lst->content)
			i++;
		lst->ind = i;
		lst = lst->next;
	}
}

void	ft_sort_chek_arr(t_data *data)
{
	int	fl;
	int	i;

	if (data->fl)
		return ;
	ft_sort_quick(data->arr, 0, data->size - 1);
	fl = 0;
	i = 0;
	while (i < data->size - 1)
	{
		if (data->arr[i] == data->arr[i + 1])
		{
			fl = 1;
			break ;
		}
		i++;
	}
	if (fl)
	{
		data->fl = -7;
		return ;
	}
	ft_add_index(data);
}
