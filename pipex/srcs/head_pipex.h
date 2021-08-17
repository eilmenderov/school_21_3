/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_pipex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:34:49 by vleida            #+#    #+#             */
/*   Updated: 2021/08/11 16:31:15 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_PIPEX_H
# define HEAD_PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define FD_SIZE	65536
# define MX_INT		2147483647
# define MN_INT		-2147483648

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_data
{
	int		size;
	int		here_doc;
	int		hd_len;
	int		fd_out;
	int		fd_inf;
	char	*eof;
	char	***cmd;
	char	**envp;
}				t_data;

/* split.c */
int		ft_count_words(char const *s, char c);
char	**ft_split(char const *s, char c);

/* pipex_utils.c */
void	ft_free_arrs(char ***cmd, char **envp);
size_t	ft_strlen_m(const char *str, unsigned char c);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strjoin_m(char const *s1, char const *s2, int c);
int		ft_gnl_cheker(char *ost);

/* pipex_bonus_utils.c */
void	ft_proc_argv(char **av, t_data *data, int i, int j);
void	ft_read_file(t_data *data, int *j);
void	ft_free(t_data *data);

/* get_next_line.c */
int		get_next_line(int fd, char **line);

#endif
