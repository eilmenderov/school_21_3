#include "head_push_swap.h"

void	ft_creat_arr(t_data *data)
{
	int		size;
	int		*arr;
	int		i;
	t_list	*buf;

	size = ft_lstsize(data->a_beg);
	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		data->fl = -5;
		return ;
	}
	buf = data->a_beg;
	i = 0;
	while (buf)
	{
		arr[i] = buf->content;
		buf = buf->next;
		i++;
	}
	data->size = size;
	data->arr = arr;
}

void	ft_find_solution(t_data *data)
{
	int	i;

	if (data->fl < 0 || ft_chek_sort(data, 0, 0, 'a') == 1)
		return ;
	ft_creat_arr(data);
	ft_sort_chek_arr(data);
	if (data->fl < 0)
		return ;
	data->lstn = 0;
	data->chek = 0;
	ft_solver(data);
	ft_clear_dupl(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*temp;
	int		i;

	ft_init_data(&data);
	if (ac == 2)
		av = ft_split_m(av[1], ' ', &ac, &data);
	i = 1;
	if (data.chek == 2)
		i = 0;
	while (i < ac && !data.fl)
	{
		temp = ft_lstnew(ft_atoi_m(av[i], &data));
		ft_lstadd_back(&data.a_beg, temp);
		i++;
	}
	if (data.chek == 2)
		ft_free_all(av, data.size);
	ft_find_solution(&data);
	ft_print_data(&data);
	ft_clear_memory(&data);
	// sleep(20);
	return (0);
}
