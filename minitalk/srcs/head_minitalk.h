#ifndef HEAD_MINITALK_H
# define HEAD_MINITALK_H

# define MX_INT		2147483647
# define MN_INT		-2147483648
# define T_LIMIT	70
# define MAX_PID	99998

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_data
{
	char	c;
	int		len;
}			t_data;

/* minitalk_utils.c */
char	*ft_itoa_m(int n, char *sys);
size_t	ft_strlen_m(const char *str, unsigned char c);
char	*ft_strjoin_m(char const *s1, char const *s2, int c);

#endif
