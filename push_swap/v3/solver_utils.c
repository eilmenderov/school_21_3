#include "head_push_swap.h"

int	ft_exist_elpush_min(t_data *data, int mid, int key)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (key == 'a')
		tmp = data->a_beg;
	if (key == 'b')
		tmp = data->b_beg;
	while (tmp)
	{
		if (tmp->ind < mid && tmp->ind >= data->lstn)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_exist_elpush_max(t_data *data, int mid, int key)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (key == 'a')
		tmp = data->a_beg;
	if (key == 'b')
		tmp = data->b_beg;
	while (tmp)
	{
		if (tmp->ind >= mid)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

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

void	ft_move_back(t_data *data)
{
	int		i;
	t_list	*tmp;

	if (!ft_finish_chek(data))
		return ;
	i = 0;
	tmp = data->a_beg;
	while (tmp)
	{
		i = i + tmp->mvs;
		tmp = tmp->next;
	}
	if (i == 0)
		return ;
	while (ft_lstlast(data->a_beg)->ind != data->lstn - 1)
	{
		if (data->b_beg->ind != data->lstn)
			ft_swap_rrr(data);
		else
			ft_swap_rrm(data, 'a');
	}
}

int	ft_finish_chek(t_data *data)
{
	if (ft_lstsize(data->a_beg) == data->size
		&& ft_chek_sort(data, 0, 0, 'a') == 1)
		return (0);
	return (1);
}

size_t	ft_strlen_m(char *str, int c)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	if (c == 0)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		j = 0;
		i = 0;
		while (str[i])
		{
			if (str[i] != (unsigned char)c)
				j++;
			i++;
		}
		return (j);
	}
}

char	*ft_strjoin(char *ans, char *step)
{
	size_t	len;
	size_t	i;
	char	*rez;

	len = ft_strlen_m(ans, 0) + ft_strlen_m(step, 0);
	rez = malloc(sizeof(char) * (len + 1));
	if (!rez || !step)
		return (NULL);
	i = 0;
	while (ans && ans[i])
	{
		rez[i] = ans[i];
		i++;
	}
	while (*step)
	{
		rez[i] = *step;
		i++;
		step++;
	}
	rez[i] = 0;
	if (ans)
		free (ans);
	return (rez);
}
