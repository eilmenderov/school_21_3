#ifndef HEAD_MINITALK_BONUS_H
# define HEAD_MINITALK_BONUS_H

# define MX_INT		2147483647
# define MN_INT		-2147483648
# define T_LIMIT	60
# define MT_LIMIT	250
# define MAX_PID	99998

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_data
{
	int		c;
	int		len;
	int		fl;
	char	*str;
}			t_data;

/* minitalk_utils1_bonus.c */
char	*ft_itoa_m(int n, char *sys);
size_t	ft_strlen_m(const char *str, unsigned char c);
char	*ft_strjoin_m(char const *s1, char const *s2, int c);

/* minitalk_utils2_bonus.c */
int		ft_atoi_m(const char *str);
void	ft_send_char(int pid, unsigned char c);
void	ft_send_str(int pid, char *str);

#endif
