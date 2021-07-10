#include "head_minitalk.h"

static int	ft_razm(int c, int sys)
{
	int	result;

	result = 0;
	if (c < 0)
		result++;
	while (c / sys)
	{
		c = c / sys;
		result++;
	}
	return (result + 1);
}

static void	ft_str_nbr(int nb, int razm, char *rez, char *sys)
{
	static int	i;

	i = ft_strlen_m(sys, 0);
	if (nb == MN_INT)
	{
		ft_str_nbr(nb / i, razm - 1, rez, sys);
		rez[razm - 1] = sys[-(nb % i)];
	}
	else if (nb < 0)
	{
		rez[0] = 45;
		ft_str_nbr(-nb, razm, rez, sys);
	}
	else
	{
		if (nb / i)
			ft_str_nbr(nb / i, razm - 1, rez, sys);
		rez[razm - 1] = sys[nb % i];
	}
}

char	*ft_itoa_m(int n, char *sys)
{
	int		razm;
	char	*rez;

	razm = ft_razm(n, ft_strlen_m(sys, 0));
	rez = malloc(sizeof(char) * (razm + 1));
	if (!rez)
		return (NULL);
	rez[razm] = 0;
	ft_str_nbr(n, razm, rez, sys);
	return (rez);
}

size_t	ft_strlen_m(const char *str, unsigned char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	if (!c)
	{
		while (str[i])
			i++;
	}
	else
	{
		while (str[i] && str[i] != c)
			i++;
		if (!str[i])
			i = 0;
	}
	return (i);
}

char	*ft_strjoin_m(char const *s1, char const *s2, int c)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*rez;

	len = ft_strlen_m(s1, 0) + ft_strlen_m(s2, 0);
	rez = malloc(sizeof(char) * (len + 1));
	if (!rez)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
		rez[i] = s1[i], i++;
	j = 0;
	while (s2 && s2[j])
		rez[i] = s2[j], i++, j++;
	rez[i] = 0;
	if (s1 && (c == 1 || c == 3))
		free ((char *)s1), s1 = NULL;
	if (s2 && (c == 2 || c == 3))
		free ((char *)s2), s2 = NULL;
	return (rez);
}
