#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *ost, char *buf)
{
	int		razm;
	char	*rez;
	int		i, j;

	razm = ft_strlen(ost) + ft_strlen(buf);
	rez = malloc(sizeof(char) * (razm + 1));
	i = 0;
	while (ost && ost[i])
	{
		rez[i] = ost[i];
		i++;
	}
	j = 0;
	while (buf && buf[j])
	{
		rez[i] = buf[j];
		i++;
		j++;
	}
	rez[i] = 0;
	if (ost)
		free (ost);
	return (rez);
}

int	get_next_line(char **line)
{
	char	*ost;
	char	*buf;
	int		rdr;
	int		ans;

	ost = NULL;
	rdr = 1;
	if (!line)
		return (-1);
	buf = malloc(sizeof(char) * 2);
	while (rdr > 0)
	{
		rdr = read(0, buf, 1);
		buf[1] = 0;
		if (rdr != 1)
			break ;
		if (buf[0] == '\n' && !ft_strlen(ost))
		{
			buf[0] = 0;
			ost = ft_strjoin(ost, buf);
			buf[0] = '\n';
			break ;
		}
		ost = ft_strjoin(ost, buf);
	}
	if (buf[0] == 0)
		ans = 0;
	if (buf[0] == '\n')
		ans = 1;
	free (buf);
	if (rdr == -1)
		ans = -1;
	*line = ost;
	return (ans);
}
