#include "head_fdf_bonus.h"

int	ft_atoi_m(char	*str, t_data *data)
{
	int				neg;
	unsigned long	res;

	neg = 1;
	res = 0;
	while (*str && *str == 32)
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
	if ((*str != 0 && *str != ',') || (res > MN_INT && neg < 0)
		|| (res > MX_INT && neg > 0))
		exit (-3);
	return ((int)res * neg);
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
