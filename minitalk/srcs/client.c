#include "head_minitalk.h"

static int	ft_atoi_m(const char *str)
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

static void	ft_sent_bits(int pid, char *str)
{
	int	i;
	int	len;
	int	byte;

	i = 0;
	len = ft_strlen_m(str, 0);
	while (i <= len)
	{
		byte = 0;
		while (byte < 7)
		{
			if ((str[i] >> byte) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			byte++;
			usleep(T_LIMIT);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi_m(av[1]);
		if (pid < 0)
			write(1, "Error: invalid PID\n", 19), exit (-3);
		ft_sent_bits(pid, av[2]);
	}
	else
		write(1, "Error: invalid input\n", 21);
	return (0);
}
