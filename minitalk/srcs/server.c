#include "head_minitalk.h"

void	ft_read_bits(int bit)
{
	static t_data	data;

	data.c += ((bit & 1) << data.len);
	data.len++;
	if (data.len == 7)
	{
		write(1, &data.c, 1);
		if (!data.c)
			write(1, "|\n", 2), write(1, "message : |", 11);
		data.c = 0;
		data.len = 0;
	}
}

int	main(void)
{
	int		pid;
	int		len;
	char	*rez;

	pid = getpid();
	rez = ft_strjoin_m("PID : ", ft_itoa_m(pid, "0123456789"), 2);
	len = ft_strlen_m(rez, 0);
	if (len < 7)
		exit(-1);
	write(1, rez, len);
	free(rez);
	write(1, "\n", 1);
	write(1, "message : |", 11);
	while (1)
	{
		signal(SIGUSR2, ft_read_bits);
		signal(SIGUSR1, ft_read_bits);
		pause();
	}
	return (0);
}
