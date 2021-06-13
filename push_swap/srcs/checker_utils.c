#include "head_push_swap.h"

int	ft_cheker_gnl(char *ost)
{
	if (!ost)
		return (1);
	while (*ost && *ost != '\n')
		ost++;
	if (*ost == '\n')
		return (0);
	return (1);
}

int	ft_chek_alst(t_data *data)
{
	t_list	*lst;

	if (ft_lstsize(data->a_beg) != data->size)
		return (0);
	lst = data->a_beg;
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
