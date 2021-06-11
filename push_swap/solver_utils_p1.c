#include "head_push_swap.h"

int	ft_find_mid_index(t_data *data, int key)
{
	t_list	*tmp;
	int		maxin;
	int		rez;

	maxin = data->lstn;
	if (key == 'a')
		tmp = data->a_beg;
	if (key == 'b')
		tmp = data->b_beg;
	while (tmp)
	{
		if (maxin < tmp->ind)
			maxin = tmp->ind;
		tmp = tmp->next;
	}
	rez = (maxin + data->lstn + 1) / 2;
	return (rez);
}

int	ft_finish_chek(t_data *data)
{
	if (ft_lstsize(data->a_beg) == data->size
		&& ft_chek_sort(data, 0, 0, 'a') == 1)
		return (0);
	return (1);
}
