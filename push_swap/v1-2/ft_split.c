#include "head_push_swap.h"

static int	ft_count_words(char const *s, char c)
{
	size_t	i;
	int		wrd;

	wrd = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			wrd++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wrd);
}

char	**ft_free_all(char **rez, int fl)
{
	if (fl < 0)
		fl = (-1) * fl;
	while (fl != 0)
	{
		if (rez[fl])
		{
			free (rez[fl]);
			rez[fl] = NULL;
		}
		fl--;
	}
	if (rez[0])
		free (rez[0]);
	free (rez);
	rez = NULL;
	return (rez);
}

static int	ft_conadd_let(char const *s, char c, char **rez)
{
	int		i;
	int		j;
	char	*rit;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	rit = malloc(sizeof(char) * (i + 1));
	if (!rit)
		return (0);
	j = 0;
	while (*(s + j) && j < i)
	{
		rit[j] = *(s + j);
		j++;
	}
	rit[j] = 0;
	*rez = rit;
	return (1);
}

static int	ft_add_newwr(char const *s, char c, int i, char **rez)
{
	int		j;
	int		wrd;
	int		k;

	k = 1;
	wrd = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			if (wrd == i)
				break ;
			wrd++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	if (s[j])
		k = ft_conadd_let(&s[j], c, rez);
	if (!k || wrd != i)
		return (-i);
	return (1);
}

char	**ft_split_m(char const *s, char c, int *ac, t_data	*data)
{
	int		wrd;
	int		i;
	int		fl;
	char	**rez;

	if (!s)
		return (NULL);
	wrd = ft_count_words(s, c) + 1;
	rez = malloc(sizeof(rez) * (wrd + 1));
	if (!rez)
		return (NULL);
	i = -1;
	while (i++ < wrd)
		rez[i] = NULL;
	i = -1;
	while (++i < wrd)
	{
		fl = ft_add_newwr(s, c, i, &rez[i]);
		if (fl != 1)
			return (ft_free_all(rez, fl));
	}
	*ac = i - 1;
	data->size = *ac;
	data->chek = 2;
	return (rez);
}
