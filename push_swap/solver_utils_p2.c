#include "head_push_swap.h"

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

void	ft_tfs_helper(int *i, int *rez, int *mstep, int k)
{
	if (*i > *rez)
	{
		*rez = *i;
		*mstep = k;
	}
}

int	ft_next_tfind(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		if (tmp->des)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->des)
			return (tmp->ind);
		tmp = tmp->next;
	}
	return (0);
}
