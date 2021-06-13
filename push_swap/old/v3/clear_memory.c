#include "head_push_swap.h"

static void	ft_lstdelone(t_list *lst, void (*del)(int *))
{
	if (lst && del)
	{
		(*del)(&(lst->content));
		(*del)(&(lst->mvs));
		(*del)(&(lst->ind));
		free(lst);
		if (lst)
			lst = NULL;
	}
}

static void	ft_lstclear(t_list **lst, void (*del)(int *))
{
	t_list	*buf;

	if (lst && del)
	{
		while (*lst)
		{
			buf = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = buf;
		}
	}
}

static void	ft_del_int(int *numb)
{
	*numb = 0;
}

void	ft_clear_memory(t_data *data)
{
	int	i;

	ft_lstclear(&data->a_beg, &ft_del_int);
	ft_lstclear(&data->b_beg, &ft_del_int);
	i = 0;
	if (data->arr)
	{
		while (i < data->size)
		{
			data->arr[i] = 0;
			i++;
		}
		free (data->arr);
		if (data->arr)
			data->arr = NULL;
	}
	if (data->answ)
	{
		free (data->answ);
		data->answ = NULL;
	}
	if (data->fl < 0)
		write(1, "Error!\n", 7);
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
