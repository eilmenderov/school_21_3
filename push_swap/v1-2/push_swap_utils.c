#include "head_push_swap.h"

void	ft_init_data(t_data *dat)
{
	dat->fl = 0;
	dat->argm = 0;
	dat->chek = 0;
	dat->size = 0;
	dat->answ = NULL;
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
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && res <= MN_INT)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (*str != 0 || (res > MN_INT && neg < 0) || (res > MX_INT && neg > 0))
		data->fl = -5;
	return ((int)res * neg);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*schet;

	schet = lst;
	i = 0;
	while (schet)
	{
		i++;
		schet = schet->next;
	}
	return (i);
}

int	ft_chek_sort(t_list *lst, t_data *data)
{
	int		i;
	int		j;
	t_list	*ma;

	if (!lst)
	{
		data->fl = -6;
		return (0);
	}
	ma = lst;
	i = 0;
	j = 0;
	while (ma->next)
	{
		if (ma->next->content < ma->content)
			i++;
		if (ma->next->content > ma->content)
			j++;
		ma = ma->next;
	}
	if (ft_lstsize(lst) == j + 1)
		return (1);
	if (ft_lstsize(lst) == i + 1)
		return (-1);
	return (0);
}

void	ft_print_data(t_data *data)
{
	int		i;
	int		fl;
	t_list	*beg;

	printf("status : ");
	fl = ft_chek_sort(data->a_beg, data);
	if (fl > 0)
		printf("OK!\tsort = %d", fl);
	else
		printf("KO!");
	printf("\n");
	printf("fl = %d\targ = %d\tchk = %d\tsiz = %d\n", data->fl, data->argm, data->chek, data->size);
	printf("A :\t");
	beg = data->a_beg;
	while (beg)
	{
		printf("%d ", beg->content);
		beg = beg->next;
	}
	printf("\nB :\t");
	beg = data->b_beg;
	while (beg)
	{
		printf("%d ", beg->content);
		beg = beg->next;
	}
	printf("\n");
	i = 0;
	printf("M :");
	while (data->arr && i < data->size)
	{
		printf(" %d", data->arr[i]);
		i++;
	}
	printf("\n");
}
