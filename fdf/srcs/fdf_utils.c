#include "head_fdf.h"

int	ft_atoi_m(char	*str, t_data *data)
{
	int				neg;
	unsigned long	res;

	(void)data;
	neg = 1;
	res = 0;
	while (*str && *str == 32)
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && res <= (unsigned int)MX_INT)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((*str != 0 && *str != ',') || (res > (unsigned int)MX_INT && neg < 0)
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

void	ft_key_help_p2(int key, t_data *data)
{
	if (key == 34)
		data->projection = 0;
	else if (key == 32)
		data->b_lock = ft_on_off(data->b_lock);
	else if (key == 5 && data->b_lock == 1)
		data->gamma = data->gamma + (M_PI / 2);
	else if (key == 45)
		data->line_point = ft_on_off(data->line_point);
	else if (key == 43 && data->b_lock == 1)
		data->color += 100;
	else if (key == 47 && data->b_lock == 1)
		data->color -= 100;
	else if (key == 47 && data->b_lock == 1)
		data->color -= 100;
	else if (key == 17 && data->b_lock == 1)
		data->treug = ft_on_off(data->treug);
	else if (key == 15 && data->b_lock == 1)
		data->projection = 2;
	else if (key == 8 && data->b_lock == 1 && data->projection == 2)
		data->angle += 0.03;
	else if (key == 9 && data->b_lock == 1 && data->projection == 2)
		data->angle -= 0.03;
	else if (key == 24 && data->b_lock == 1 && data->projection == 2)
		data->pl_rad += 0.001;
	return ;
}
