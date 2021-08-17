/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:34:41 by vleida            #+#    #+#             */
/*   Updated: 2021/08/11 16:37:50 by vleida           ###   ########.fr       */
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
}

static void	ft_pipex(int fd_inf, int fd_outf, char ***cmd, char **ev)
{
	int		fd[2];
	pid_t	baby_pid;

	if (pipe(fd) != 0)
		write(2, "Error: pipe error\n", 18), exit(-3);
	baby_pid = fork();
	if (baby_pid == -1)
		write(2, "Error: fork error\n", 18), exit(-4);
	if (!baby_pid)
	{
		if (dup2(fd[1], 1) + dup2(fd_inf, 0) < 0)
			write(2, "Error: dup2 error\n", 18), exit(-7);
		if (close(fd[0]) + close(fd[1]) < 0)
			write(2, "Error: close error\n", 19), exit(-6);
		ft_exec(cmd[0][0], cmd[0], ev), write (2, "Error: invalid cmd(1)\n", 23);
	}
	else
	{
		if (dup2(fd[0], 0) + dup2(fd_outf, 1) < 0)
			write(2, "Error: dup2 error\n", 18), exit(-7);
		if (close(fd[0]) + close(fd[1]) < 0)
			write(2, "Error: close error\n", 19), exit(-6);
		ft_exec(cmd[1][0], cmd[1], ev), write (2, "Error: invalid cmd(2)\n", 23);
	}
	ft_free_arrs(cmd, ev), close(fd_inf), close(fd_outf), exit(-5);
}

static void	ft_proc_envp(char ***envp)
{
	int		i;
	char	**rez;

	i = 0;
	rez = *envp;
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
	*envp = rez;
}

int	main(int ac, char **av, char **envp)
{
	int		fd_inf;
	int		fd_outf;
	char	***cmd;
	int		i;

	if (ac != 5)
		write (2, "Error: invalid input\n", 21), exit(1);
	fd_inf = open(av[1], O_RDONLY);
	fd_outf = open(av[ac - 1], O_WRONLY | O_TRUNC);
	if (fd_outf == -1 || fd_inf == -1)
		write(2, "Error: open files error\n", 25), exit(-8);
	cmd = malloc(sizeof(char **) * (ac - 2));
	if (!cmd)
		write(2, "Error: malloc error\n", 20), exit(-2);
	i = 0;
	while (i < ac - 3)
	{
		cmd[i] = ft_split(av[i + 2], ' ');
		if (!cmd[i])
			write(2, "Error: malloc error\n", 20), exit(-2);
		i++;
	}
	cmd[i] = NULL, ft_proc_envp(&envp);
	ft_pipex(fd_inf, fd_outf, cmd, envp), ft_free_arrs(cmd, envp);
	return (0);
}
