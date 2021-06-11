#include "head_push_swap.h"

void	ft_swap_s(t_list *lst, t_data *data, int key)
{
	t_list	*buf;

	if (!ft_finish_chek(data))
		return ;
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
		ft_swap_s(data->a_beg, data, 'c');
		i++;
	}
	if (data->b_beg && data->b_beg->next)
	{
		ft_swap_s(data->b_beg, data, 's');
		j++;
	}
	if (i && j)
		data->answ = ft_strjoin(data->answ, "2");
	else if (i && !j)
		data->answ = ft_strjoin(data->answ, "0");
	else if (!i && j)
		data->answ = ft_strjoin(data->answ, "1");
}

void	ft_swap_r(t_list *lst, t_data *data, int key)
{
	t_list	*buf;

	if (!ft_finish_chek(data))
		return ;
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
		ft_swap_r(data->a_beg, data, 'c');
		i++;
	}
	if (data->b_beg && data->b_beg->next)
	{
		ft_swap_r(data->b_beg, data, 'r');
		j++;
	}
	if (i && j)
		data->answ = ft_strjoin(data->answ, "7");
	else if (i && !j)
		data->answ = ft_strjoin(data->answ, "5");
	else if (!i && j)
		data->answ = ft_strjoin(data->answ, "6");
}
