#include "head_push_swap.h"

static void	ft_count_b(t_data *data)
{
	int		len;
	int		i;
	t_list	*lst;

	len = ft_lstsize(data->b_beg);
	lst = data->b_beg;
	i = 1;
	while (lst)
	{
		lst->mvs = i;
		lst = lst->next;
		if (len % 2 == 1 && i == (len + 2) / 2)
			break ;
		i++;
		if (len % 2 == 0 && i == (len / 2) + 1)
			break ;
	}
	while (lst)
	{
		lst->mvs = i;
		lst = lst->next;
		i--;
	}
}

static void	ft_count_a(t_data *data)
{
	int		len;
	int		i;
	t_list	*lst;

	len = ft_lstsize(data->a_beg);
	lst = data->a_beg;
	i = 0;
	while (lst)
	{
		lst->mvs = i;
		lst = lst->next;
		if (len % 2 == 1 && i == len / 2)
			break ;
		i++;
		if (len % 2 == 0 && i == (len + 1) / 2)
			break ;
	}
	while (lst)
	{
		lst->mvs = i;
		lst = lst->next;
		i--;
	}
}

static void	ft_united(t_data *data)
{
	t_list	*la;
	t_list	*lb;
	int		ind;

	ft_count_b(data);
	ft_count_a(data);
	lb = data->b_beg;
	while (lb)
	{
		ind = ft_find_unit(data, lb->ind, 0, 0);
		la = data->a_beg;
		while (la)
		{
			if (la->ind == ind)
				break ;
			la = la->next;
		}
		lb->mvs = lb->mvs + la->mvs;
		lb = lb->next;
	}
}

int	ft_find_unit(t_data *data, int ind, int mn, int mx)
{
	t_list	*lst;

	mx = ft_find_ind_mxmn(data->a_beg, 1);
	mn = ft_find_ind_mxmn(data->a_beg, -1);
	if (ind > mx || ind < mn)
		return (mn);
	lst = data->a_beg;
	while (lst && lst->next)
	{
		if (lst->ind < ind && lst->next->ind > ind)
		{
			lst = lst->next;
			break ;
		}
		if (lst->next->ind == ft_lstlast(lst)->ind)
		{
			if (lst->next->ind < ind && data->a_beg->ind > ind)
			{
				lst = data->a_beg;
				break ;
			}
		}
		lst = lst->next;
	}
	return (lst->ind);
}

int	ft_second_step(t_data *data)
{
	int		mn;
	int		ind;
	t_list	*lst;

	ft_united(data);
	lst = data->b_beg;
	ind = lst->ind;
	mn = lst->mvs;
	while (lst)
	{
		if (mn > lst->mvs)
		{
			mn = lst->mvs;
			ind = lst->ind;
		}
		lst = lst->next;
	}
	return (ind);
}
