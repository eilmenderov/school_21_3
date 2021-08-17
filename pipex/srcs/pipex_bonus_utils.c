/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:52:44 by vleida            #+#    #+#             */
/*   Updated: 2021/08/16 14:52:45 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_pipex.h"

void	ft_proc_argv(char **av, t_data *data, int i, int j)
{
	data->here_doc = 0;
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		data->eof = ft_strjoin_m(data->eof, av[2], 0);
		if (!data->eof)
			write(2, "Error: malloc error\n", 20), exit(-2);
		data->here_doc = 1, ft_read_file(data, &j);
		data->fd_out = open(av[data->size], O_APPEND | O_WRONLY | O_CREAT);
	}
	else
	{
		data->fd_inf = open(av[1], O_RDONLY);
		data->fd_out = open(av[data->size], O_WRONLY | O_TRUNC);
	}
	if (data->fd_inf == -1 || data->fd_out == -1)
		write(2, "Error: open files error\n", 25), exit(-8);
	data->hd_len = ft_strlen_m(data->eof, 0);
	while (i < data->size - j)
	{
		data->cmd[i] = ft_split(av[i + j], ' ');
		if (!data->cmd[i])
			write(2, "Error: malloc error\n", 20), exit(-2);
		i++;
	}
	data->cmd[i] = NULL;
}

void	ft_read_file(t_data *data, int *j)
{
	int		fd;
	int		key;
	char	*line;

	fd = open("here_doc", O_WRONLY | O_TRUNC | O_CREAT, S_IWRITE | S_IREAD);
	if (fd < 0)
		write(2, "Error: open files error\n", 25), exit(-8);
	write (1, "> ", 2);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, data->eof, data->hd_len))
			break ;
		write(fd, line, ft_strlen_m(line, 0));
		write(fd, "\n", 1);
		write(1, "> ", 2), free(line), line = NULL;
	}
	free(line), close(fd);
	data->fd_inf = open("here_doc", O_RDONLY);
	if (data->fd_inf < 0)
		write(2, "Error: open files error\n", 25), exit(-8);
	unlink("here_doc");
	*j = *j + 1;
}

void	ft_free(t_data *data)
{
	ft_free_arrs(data->cmd, data->envp);
	if (data->here_doc)
		free(data->eof);
	close(data->fd_inf);
	close(data->fd_out);
}
