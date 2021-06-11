#include "head_push_swap.h"

static int	ft_dific(char a, char b)
{
	if ((a == '3' && b == '4') || (a == '4' && b == '3'))
		return (1);
	if ((a == 'r' && b == '7') || (a == '7' && b == 'r'))
		return (1);
	if ((a == '0' && b == '0') || (a == '1' && b == '1'))
		return (1);
	if ((a == '6' && b == '9') || (a == '9' && b == '6'))
		return (1);
	if ((a == '5' && b == '8') || (a == '8' && b == '5'))
		return (1);
	return (0);
}

int	ft_flag(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i + 1] && str[i + 2] && str[i + 3])
	{
		if (ft_dific(str[i], str[i + 1]))
			return (1);
		if ((str[i] == '4' && str[i + 1] == '5')
			&& (str[i + 2] == '3' && str[i + 3] == '5'))
			return (1);
		i++;
	}
	return (0);
}

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

char	*ft_united_str(char *str, char del)
{
	int		i;
	int		j;
	char	*rez;

	if (!str)
		return (NULL);
	rez = malloc(sizeof(char) * (ft_strlen_m(str, ' ') + 1));
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != del)
		{
			rez[j] = str[i];
			j++;
		}
		i++;
	}
	rez[j] = 0;
	if (str)
	{
		free (str);
		str = NULL;
	}
	return (rez);
}

void	ft_corect_sol(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i + 1] && s[i + 2] && s[i + 3])
	{
		if (ft_dific(s[i], s[i + 1]))
		{
			s[i] = 32;
			s[i + 1] = 32;
		}
		if ((s[i] == '7' && s[i + 1] == '9')
			|| (s[i] == '9' && s[i + 1] == '7'))
		{
			s[i] = '5';
			s[i + 1] = 32;
		}
		if ((s[i] == '4' && s[i + 1] == '5')
			&& (s[i + 2] == '3' && s[i + 3] == '5'))
		{
			s[i] = '0';
			s[i + 1] = '7';
			s[i + 2] = '7';
			s[i + 3] = 32;
		}
		i++;
	}
}

void	ft_find_solution(t_data *data)
{
	int	i;

	if (data->fl < 0 || ft_chek_sort(data->a_beg, data) == 1)
		return ;
	ft_creat_arr(data);
	ft_sort_chek_arr(data);
	if (data->fl < 0)
		return ;
	data->lstn = 0;
	data->chek = 0;
	ft_itoa_m_duo(data);
	// ft_new_solve(data);
	ft_solver(data);
	while (ft_flag(data->answ))
	{
		ft_corect_sol(data->answ);
		data->answ = ft_united_str(data->answ, ' ');
	}
	i = ft_strlen_m(data->answ, 0);
	printf("ans = %s\n", data->answ);
	printf("oper = %d\n", i);
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
	// char	buf;
	// read(0, buf, 1);
	// sleep(20);
	return (0);
}
