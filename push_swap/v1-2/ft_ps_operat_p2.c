#include "head_push_swap.h"

void	ft_swap_rrm(t_list *lst, t_data *data, int key)
{
	t_list	*buf;

	if (!ft_finish_chek(data))
		return ;
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
		ft_swap_rrm(data->a_beg, data, 'c');
		i++;
	}
	if (data->b_beg && data->b_beg->next)
	{
		ft_swap_rrm(data->b_beg, data, 'r');
		j++;
	}
	if (i && j)
		data->answ = ft_strjoin(data->answ, "r");
	else if (i && !j)
		data->answ = ft_strjoin(data->answ, "8");
	else if (!i && j)
		data->answ = ft_strjoin(data->answ, "9");
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
			if (str[i] != c)
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
