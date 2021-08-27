#include "../srcs/head_minitalk.h"

int	ft_atoi_m(const char *str)
{
	long long	res;

	res = 0;
	while (*str && *str >= '0' && *str <= '9' && res <= MAX_PID)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (*str || (int)res > MAX_PID)
		return (-1);
	return ((int)res);
}

void	ft_send_char(int pid, unsigned char c)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (i & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i = i / 2;
		usleep(T_LIMIT);
	}
}

void	ft_send_str(int pid, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_m(str, 0);
	while (i <= len)
	{
		ft_send_char(pid, str[i]);
		i++;
	}
}
