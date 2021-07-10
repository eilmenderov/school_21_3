#include "head_fdf.h"

static char	*ft_format_line(char *data)
{
	int		i;
	char	*rez;

	if (!data)
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i])
		i++;
	rez = malloc(sizeof(char) * (i + 1));
	if (!rez)
	{
		free (data);
		return (NULL);
	}
	rez[i] = 0;
	i = 0;
	while (data[i] && data[i] != '\n')
	{
		rez[i] = data[i];
		i++;
	}
	return (rez);
}

static char	*ft_saver(char *ost, int *fl)
{
	char	*rez;
	int		i;
	int		j;

	i = 0;
	while (ost[i] && ost[i] != '\n')
		i++;
	if (!ost[i])
	{
		*fl = 1;
		free (ost);
		return (NULL);
	}
	rez = malloc(sizeof(char) * (ft_strlen_m(ost, 0) - i + 1));
	if (!rez)
	{
		free (ost);
		return (NULL);
	}
	j = 0;
	while (ost[i++])
		rez[j++] = ost[i];
	rez[j] = 0;
	free (ost);
	return (rez);
}

static int	ft_helper(char *buf, int *rdr, int fd)
{
	*rdr = read(fd, buf, BUFFER_SIZE);
	if (*rdr == -1)
	{
		free (buf);
		buf = NULL;
		return (1);
	}
	buf[*rdr] = 0;
	return (0);
}

static int	ft_helper_dop(char **buf, char **ost, char ***line, int *fl)
{
	free (*buf);
	*buf = NULL;
	**line = ft_format_line(*ost);
	if (!(**line))
		return (1);
	*fl = 0;
	*ost = ft_saver(*ost, fl);
	if (!fl && !(*ost))
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*ost;
	int			rdr;
	int			fl;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	rdr = 1;
	while (ft_cheker_gnl(ost) && rdr)
	{
		if (ft_helper(buf, &rdr, fd))
			return (-1);
		ost = ft_strjoin(ost, buf);
	}
	if (ft_helper_dop(&buf, &ost, &line, &fl))
		return (-1);
	if (!rdr && fl)
		return (0);
	return (1);
}
