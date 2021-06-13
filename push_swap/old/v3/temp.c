#include "head_push_swap.h"

void	ft_print_data(t_data *data)
{
	int		i;
	int		fl;
	t_list	*beg;

	printf("status : ");
	fl = ft_chek_sort(data, 0, 0, 'a');
	if (fl > 0)
		printf("OK!\tsort = %d", fl);
	else
		printf("KO!");
	printf("\n");
	i = ft_strlen_m(data->answ, 0);
	printf("ans = %s\n", data->answ);
	printf("oper = %d\n", i);
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
