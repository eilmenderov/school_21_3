#include "head_push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->ind = 0;
	newlist->mvs = 0;
	newlist->next = NULL;
	return (newlist);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (last)
	{
		while (last->next)
			last = last->next;
		return (last);
	}
	return (last);
}

t_list	*ft_pr_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (last)
	{
		while (last->next->next)
			last = last->next;
		return (last);
	}
	return (last);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_end;

	if (lst)
	{
		if (*lst)
		{
			lst_end = ft_lstlast(*lst);
			lst_end->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
