#include "head_minitalk_bonus.h"

static void	ft_read_conform(int bit)
{
	if (bit == SIGUSR1)
	{
		write(1, "message delivered\n", 18);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*client_pid;

	if (ac != 3)
	{
		write(1, "Error: invalid input\n", 21);
		return (0);
	}
	server_pid = ft_atoi_m(av[1]);
	if (server_pid < 0)
		write(1, "Error: invalid server_PID\n", 19), exit (-3);
	ft_send_str(server_pid, av[2]);
	client_pid = ft_itoa_m(getpid(), "0123456789");
	if (!client_pid)
		write(1, "Error: malloc error\n", 20), exit(-2);
	ft_send_str(server_pid, client_pid);
	free(client_pid);
	signal(SIGUSR1, ft_read_conform);
	sleep(5);
	write(1, "Error: something wrong!\n", 24);
	return (0);
}
