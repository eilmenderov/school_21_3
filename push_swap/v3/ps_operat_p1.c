#include "head_push_swap.h"

void	ft_swap_s(t_data *data, int key)
{
	t_list	*buf;
	t_list	*lst;

	if (!ft_finish_chek(data))
		return ;
	if (key == 'a' || key == 'c')
		lst = data->a_beg;
	if (key == 'b' || key == 's')
		lst = data->b_beg;
	if (!lst || !lst->next)
		return ;
	if (key == 'a')
		data->answ = ft_strjoin(data->answ, "0");
	if (key == 'b')
		data->answ = ft_strjoin(data->answ, "1");
	buf = lst->next;
	lst->next = lst->next->next;
	buf->next = lst;
	if (key == 'a' || key == 'c')
		data->a_beg = buf;
	if (key == 'b' || key == 's')
		data->b_beg = buf;
}

void	ft_swap_ss(t_data *data)
{
	int	i;
	int	j;

	if (!ft_finish_chek(data))
		return ;
	i = 0;
	j = 0;
	if (data->a_beg && data->a_beg->next)
	{
		ft_swap_s(data, 'c');
		i++;
	}
	if (data->b_beg && data->b_beg->next)
	{
		ft_swap_s(data, 's');
		j++;
	}
	if (i && j)
		data->answ = ft_strjoin(data->answ, "2");
	else if (i && !j)
		data->answ = ft_strjoin(data->answ, "0");
	else if (!i && j)
		data->answ = ft_strjoin(data->answ, "1");
}

void	ft_swap_r(t_data *data, int key)
{
	t_list	*buf;
	t_list	*lst;

	if (!ft_finish_chek(data))
		return ;
	if (key == 'a' || key == 'c')
		lst = data->a_beg;
	if (key == 'b' || key == 'r')
		lst = data->b_beg;
	if (!lst || !lst->next)
		return ;
	if (key == 'a')
		data->answ = ft_strjoin(data->answ, "5");
	if (key == 'b')
		data->answ = ft_strjoin(data->answ, "6");
	buf = lst->next;
	lst->next = NULL;
	ft_lstadd_back(&buf, lst);
	if (key == 'a' || key == 'c')
		data->a_beg = buf;
	if (key == 'b' || key == 'r')
		data->b_beg = buf;
}

void	ft_swap_rr(t_data *data)
{
	int	i;
	int	j;

	if (!ft_finish_chek(data))
		return ;
	i = 0;
	j = 0;
	if (data->a_beg && data->a_beg->next)
	{
		ft_swap_r(data, 'c');
		i++;
	}
	if (data->b_beg && data->b_beg->next)
	{
		ft_swap_r(data, 'r');
		j++;
	}
	if (i && j)
		data->answ = ft_strjoin(data->answ, "7");
	else if (i && !j)
		data->answ = ft_strjoin(data->answ, "5");
	else if (!i && j)
		data->answ = ft_strjoin(data->answ, "6");
}

void	ft_push_el(t_data *data, int key)
{
	t_list	*buf;

	if (key == 'a')
	{
		if (!data->b_beg)
			return ;
		buf = data->b_beg;
		data->b_beg = data->b_beg->next;
		buf->next = NULL;
		ft_lstadd_front(&data->a_beg, buf);
		data->a_beg = buf;
		data->answ = ft_strjoin(data->answ, "3");
	}
	if (key == 'b')
	{
		if (!data->a_beg)
			return ;
		data->a_beg->mvs++;
		buf = data->a_beg;
		data->a_beg = data->a_beg->next;
		buf->next = NULL;
		ft_lstadd_front(&data->b_beg, buf);
		data->b_beg = buf;
		data->answ = ft_strjoin(data->answ, "4");
	}
}
