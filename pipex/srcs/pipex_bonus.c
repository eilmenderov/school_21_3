/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:34:41 by vleida            #+#    #+#             */
/*   Updated: 2021/08/11 17:14:38 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_pipex.h"

static void	ft_exec(char *cmd, char **acmd, char **envp)
{
	int		i;
	char	*str;

	i = 0;
	while (envp[i])
	{
		str = ft_strjoin_m(envp[i], cmd, 0);
		if (!str)
			write(2, "Error: malloc error\n", 20), exit(-2);
		execve(str, acmd, NULL);
		free(str);
		i++;
	}
	write (2, "Error: invalid cmd\n", 23), exit(-5);
}

static void	ft_command(t_data *data, int tmp_fd, int fd[2], int i)
{
	if (dup2(tmp_fd, 0) == -1)
		write(2, "Error: dup2 error\n", 18), exit(-7);
	if (data->cmd[i + 1])
	{
		if (dup2(fd[1], 1) == -1)
			write(2, "Error: dup2 error\n", 18), exit(-7);
	}
	else
	{
		if (dup2(data->fd_out, 1) == -1)
			write(2, "Error: dup2 error\n", 18), exit(-7);
	}
	if (close(fd[0]) + close(fd[1]) + close(data->fd_out) < 0)
		write(2, "Error: close error\n", 19), exit(-6);
	ft_exec(data->cmd[i][0], data->cmd[i], data->envp);
}

static void	ft_pipex(t_data *data, int i, int tmp_fd)
{
	int		fd[2];
	pid_t	baby_pid;

	if (dup2(data->fd_inf, 0) + dup2(data->fd_out, 1) + close(data->fd_inf) < 0)
		write(2, "Error: dup2 error\n", 18), exit(-7);
	while (data->cmd[i])
	{
		if (pipe(fd) == -1)
			write(2, "Error: pipe error\n", 18), exit(-3);
		baby_pid = fork();
		if (baby_pid == -1)
			write(2, "Error: fork error\n", 18), exit(-4);
		else if (!baby_pid)
			ft_command(data, tmp_fd, fd, i);
		else
		{
			wait(NULL), i++;
			if (close(tmp_fd) + close(fd[1]) + dup2(fd[0], tmp_fd)
				+ close(fd[0]) < 0)
				write(2, "Error: close or dup2 error\n", 27), exit(-7);
		}
	}
	if (close(data->fd_out) < 0)
		write(2, "Error: close error\n", 19), exit(-6);
}

static void	ft_proc_envp(char **envp, t_data *data)
{
	int		i;
	char	**rez;

	i = 0;
	rez = envp;
	while (rez[i])
	{
		if (!ft_strncmp(rez[i], "PATH=", 5))
			break ;
		i++;
	}
	rez = ft_split(&rez[i][5], ':');
	i = 0;
	while (rez[i])
		rez[i] = ft_strjoin_m(rez[i], "/", 1), i++;
	data->envp = rez;
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		write (2, "Error: invalid input\n", 21), exit(1);
	data.cmd = malloc(sizeof(char **) * (ac - 1));
	if (!data.cmd)
		write(2, "Error: malloc error\n", 20), exit(-2);
	data.size = ac - 1;
	ft_proc_envp(envp, &data), ft_proc_argv(av, &data, 0, 2);
	if (data.here_doc && ac != 6)
		write (2, "Error: invalid input\n", 21), ft_free(&data), exit(1);
	else
		ft_pipex(&data, 0, 0);
	ft_free(&data);
	return (0);
}
