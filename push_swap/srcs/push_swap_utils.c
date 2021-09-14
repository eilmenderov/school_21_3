#include "head_push_swap.h"

void	ft_init_data(t_data *dat)
{
	dat->fl = 0;
	dat->argm = 0;
	dat->chek = 0;
	dat->size = 0;
	dat->arr = NULL;
	dat->a_beg = NULL;
	dat->b_beg = NULL;
}

int	ft_atoi_m(char	*str, t_data *data)
{
	int				neg;
	unsigned long	res;

	neg = 1;
	res = 0;
	while (*str && *str == 32)
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && res <= (unsigned int)MX_INT)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (*str != 0 || (res > (unsigned int)MX_INT && neg < 0)
		|| (res > (unsigned int)MX_INT && neg > 0))
		data->fl = -5;
	return ((int)res * neg);
}

int	ft_chek_sort(t_data *data, int i, int j, int key)
{
	t_list	*lst;

	if (key == 'a')
		lst = data->a_beg;
	if (key == 'b')
		lst = data->b_beg;
	if (!lst)
		return (1);
	key = ft_lstsize(lst);
	while (lst->next)
	{
		if (lst->next->ind < lst->ind)
			i = i + 1;
		if (lst->next->ind > lst->ind)
			j = j + 1;
		lst = lst->next;
	}
	if (key == j + 1)
		return (1);
	if (key == i + 1)
		return (-1);
	return (0);
}

int	ft_short_way(t_data *data, int key, int min, int max)
{
	int		i;
	int		first;
	int		last;
	t_list	*buf;

	if (key == 'a')
		data->buf = data->a_beg;
	if (key == 'b')
		data->buf = data->b_beg;
	i = 0;
	first = 0;
	buf = data->buf;
	while (buf)
	{
		if (buf->ind <= max && buf->ind >= min)
			last = i;
		if (!first && buf->ind <= max && buf->ind >= min)
			first = i;
		buf = buf->next;
		i++;
	}
	if (first <= ft_lstsize(data->buf) - last)
		return (1);
	return (-1);
}
