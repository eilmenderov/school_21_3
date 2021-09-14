#include "head_push_swap.h"

static char	*ft_choise(char sym)
{
	if (sym == '0')
		return ("sa\n");
	else if (sym == '1')
		return ("sb\n");
	else if (sym == '2')
		return ("ss\n");
	else if (sym == '3')
		return ("pa\n");
	else if (sym == '4')
		return ("pb\n");
	else if (sym == '5')
		return ("ra\n");
	else if (sym == '6')
		return ("rb\n");
	else if (sym == '7')
		return ("rr\n");
	else if (sym == '8')
		return ("rra\n");
	else if (sym == '9')
		return ("rrb\n");
	else if (sym == 'r')
		return ("rrr\n");
	return (NULL);
}

static void	ft_solv(t_data *data)
{
	t_list	*tmp;

	if (data->size < 6)
	{
		ft_small_solve(data, 'a');
		return ;
	}
	tmp = NULL;
	ft_first_step(data, tmp, 0);
	ft_solver(data);
}

static void	ft_find_solution(t_data *data)
{
	int		i;
	char	*rez;

	if (data->fl < 0 || ft_chek_sort(data, 0, 0, 'a') == 1)
		return ;
	ft_creat_arr(data);
	ft_sort_chek_arr(data);
	if (data->fl < 0)
		return ;
	data->lstn = 0;
	data->chek = 0;
	ft_solv(data);
	rez = NULL;
	i = 0;
	while (data->answ && data->answ[i])
	{
		rez = ft_strjoin(rez, ft_choise(data->answ[i]));
		i++;
	}
	if (data->answ)
		free (data->answ);
	data->answ = rez;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*temp;
	int		i;

	if (ac == 1)
		return (0);
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
	write(1, data.answ, ft_strlen_m(data.answ, 0));
	ft_clear_memory(&data);
	return (0);
}
