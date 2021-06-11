#include "head_push_swap.h"


static int	ft_razm_duo(unsigned int c, int sys)
{
	int	result;

	result = 0;
	while (c / sys)
	{
		c = c / sys;
		result++;
	}
	return (result + 1);
}

static void	ft_str_nbr_duo(unsigned int nb, int razm, char *rez, char *sys)
{
	int	i;

	i = 2;
	if (nb / i)
		ft_str_nbr_duo(nb / i, razm - 1, rez, sys);
	rez[razm - 1] = sys[nb % i];
}

void	ft_itoa_m_duo(t_data *data)
{
	int		razm;
	int		i;
	char	*rez;
	t_list	*tmp;

	razm = ft_razm_duo(data->size, 2);
	tmp = data->a_beg;
	while (tmp)
	{
		rez = malloc(sizeof(char) * (razm + 1));
		i = -1;
		while (i++ < razm)
			rez[i] = '0';
		rez[razm] = 0;
		ft_str_nbr_duo(tmp->content, razm, rez, "01");
		tmp->duo = rez;
		tmp = tmp->next;
	}
}

static int	ft_chek_char(t_list *lst, int nb)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst)
		return (0);
	while (tmp)
	{
		if (tmp->duo[nb] == '0')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_new_solve(t_data *data)
{
	int	i;

	i = ft_razm_duo(data->size, 2) - 1;
	while (i >= 0 || !ft_finish_chek(data))
	{
		while (ft_chek_char(data->a_beg, i))
		{
			if (data->a_beg->duo[i] == '0')
				ft_push_el(data, 'b');
			else
				ft_swap_r(data->a_beg, data, 'a');
		}
		while (ft_lstsize(data->b_beg))
			ft_push_el(data, 'a');
		i--;
	}
}



/*
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
	// if (ft_lstsize(data->b_beg) > 0)
	// 	ft_pb_sort(data);
	while (data->a_beg->ind == data->lstn)
	{
		ft_swap_r(data->a_beg, data, 'a');
		data->lstn++;
	}
}

static void	ft_mover(t_data *data)
{
	int		mid;
	t_list	*lst;
	int		len;

	len = ft_lstsize(data->a_beg);
	mid = data->size - (len / 2);
	if (len < 6)
		ft_small_solve(data);
	if (len <= 3)
		return ;
	while (ft_exist_elpush_min(data, mid) && len > 2)
	{
		lst = data->a_beg;
		if (lst->ind <= mid && lst->ind >= data->lstn)
			ft_push_el(data, 'b');
		else
			ft_swap_r(data->a_beg, data, 'a');
	}
	// ft_mover(data);
}

void	ft_new_solve(t_data *data)
{
	ft_mover(data);
	ft_pb_sort(data);
	ft_mover(data);
	// ft_push_el(data, 'b');
	// ft_push_el(data, 'b');
}
*/


