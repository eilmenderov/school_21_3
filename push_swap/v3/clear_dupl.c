#include "head_push_swap.h"

static int	ft_dific(char a, char b)
{
	if ((a == '3' && b == '4') || (a == '4' && b == '3'))
		return (1);
	if ((a == 'r' && b == '7') || (a == '7' && b == 'r'))
		return (1);
	if ((a == '0' && b == '0') || (a == '1' && b == '1'))
		return (1);
	if ((a == '6' && b == '9') || (a == '9' && b == '6'))
		return (1);
	if ((a == '5' && b == '8') || (a == '8' && b == '5'))
		return (1);
	return (0);
}

static int	ft_flag(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i + 1] && str[i + 2] && str[i + 3])
	{
		if (ft_dific(str[i], str[i + 1]))
			return (1);
		if ((str[i] == '4' && str[i + 1] == '5')
			&& (str[i + 2] == '3' && str[i + 3] == '5'))
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_united_str(char *str, char del)
{
	int		i;
	int		j;
	char	*rez;

	if (!str)
		return (NULL);
	rez = malloc(sizeof(char) * (ft_strlen_m(str, ' ') + 1));
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != del)
		{
			rez[j] = str[i];
			j++;
		}
		i++;
	}
	rez[j] = 0;
	if (str)
	{
		free (str);
		str = NULL;
	}
	return (rez);
}

static void	ft_corect_sol(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i + 1] && s[i + 2] && s[i + 3])
	{
		if (ft_dific(s[i], s[i + 1]))
		{
			s[i] = 32;
			s[i + 1] = 32;
		}
		if ((s[i] == '7' && s[i + 1] == '9')
			|| (s[i] == '9' && s[i + 1] == '7'))
		{
			s[i] = '5';
			s[i + 1] = 32;
		}
		if ((s[i] == '4' && s[i + 1] == '5')
			&& (s[i + 2] == '3' && s[i + 3] == '5'))
		{
			s[i] = '0';
			s[i + 1] = '7';
			s[i + 2] = '7';
			s[i + 3] = 32;
		}
		i++;
	}
}

void	ft_clear_dupl(t_data *data)
{
	while (ft_flag(data->answ))
	{
		ft_corect_sol(data->answ);
		data->answ = ft_united_str(data->answ, ' ');
	}
}
