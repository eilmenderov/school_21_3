#include "head_push_swap.h"

void	ft_swap_rrm(t_data *data, int key)
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
		data->answ = ft_strjoin(data->answ, "8");
	if (key == 'b')
		data->answ = ft_strjoin(data->answ, "9");
	buf = ft_lstlast(lst);
	ft_pr_lstlast(lst)->next = NULL;
	ft_lstadd_front(&lst, buf);
	if (key == 'a' || key == 'c')
		data->a_beg = buf;
	if (key == 'b' || key == 'r')
		data->b_beg = buf;
}

void	ft_swap_rrr(t_data *data)
{
	int	i;
	int	j;

	if (!ft_finish_chek(data))
		return ;
	i = 0;
	j = 0;
	if (data->a_beg && data->a_beg->next)
	{
		ft_swap_rrm(data, 'c');
		i++;
	}
	if (data->b_beg && data->b_beg->next)
	{
		ft_swap_rrm(data, 'r');
		j++;
	}
	if (i && j)
		data->answ = ft_strjoin(data->answ, "r");
	else if (i && !j)
		data->answ = ft_strjoin(data->answ, "8");
	else if (!i && j)
		data->answ = ft_strjoin(data->answ, "9");
}
