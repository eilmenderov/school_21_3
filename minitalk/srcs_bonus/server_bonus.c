#include "../srcs/head_minitalk.h"

static void	ft_send_conform(char **cl_pid)
{
	int	client_pid;

	client_pid = ft_atoi_m(*cl_pid);
	if (*cl_pid)
	{
		free(*cl_pid);
		*cl_pid = NULL;
	}
	if (client_pid >= 0)
	{
		usleep(MT_LIMIT);
		kill(client_pid, SIGUSR1);
	}
	else
	{
		write(1, "Error: Houston, we have a problem!\n", 35);
		exit(-4);
	}
}

static void	ft_read_char(int bit)
{
	static t_data	data;
	char			tmp[2];

	if (bit == SIGUSR1)
		data.c += 1 << (7 - data.len);
	data.len++;
	if (data.len == 8 && !data.fl)
	{
		write(1, &data.c, 1);
		if (data.c == 0)
			write(1, "|\n", 2), write(1, "message : |", 11), data.fl = 1;
		data.c = 0;
		data.len = 0;
	}
	if (data.len == 8 && data.fl == 1)
	{
		tmp[0] = data.c;
		tmp[1] = 0;
		data.str = ft_strjoin_m(data.str, tmp, 1);
		if (data.c == 0)
			data.fl = 0, ft_send_conform(&data.str);
		data.c = 0;
		data.len = 0;
	}
}

int	main(void)
{
	int		server_pid;
	int		len;
	char	*rez;

	server_pid = getpid();
	rez = ft_strjoin_m("server_pid : ", ft_itoa_m(server_pid, "0123456789"), 2);
	len = ft_strlen_m(rez, 0);
	if (len < 7)
		exit(-1);
	write(1, rez, len);
	free(rez);
	write(1, "\n", 1);
	write(1, "message : |", 11);
	while (1)
	{
		signal(SIGUSR2, ft_read_char);
		signal(SIGUSR1, ft_read_char);
		pause();
	}
	return (0);
}
