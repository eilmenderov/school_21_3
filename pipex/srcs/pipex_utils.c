/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:34:46 by vleida            #+#    #+#             */
/*   Updated: 2021/08/11 16:39:34 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_pipex.h"

void	ft_free_arrs(char ***cmd, char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (cmd && cmd[i])
	{
		j = 0;
		while (cmd[i][j])
			free(cmd[i][j]), cmd[i][j] = NULL, j++;
		free(cmd[i]), cmd[i] = NULL, i++;
	}
	i = 0;
	while (envp && envp[i])
		free(envp[i]), envp[i] = NULL, i++;
	if (envp)
		free(envp), envp = NULL;
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

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
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

int	ft_gnl_cheker(char *ost)
{
	int	i;

	if (!ost)
		return (1);
	i = 0;
	while (*(ost + i) && *(ost + i) != '\n')
		i++;
	if (*(ost + i) == '\n')
		return (0);
	return (1);
}
