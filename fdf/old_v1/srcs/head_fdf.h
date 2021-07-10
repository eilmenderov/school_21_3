#ifndef HEAD_FDF_H
# define HEAD_FDF_H

# define MX_INT 2147483647
# define MN_INT -2147483648
# define M_PI 3.14159265358979323846
# define BUFFER_SIZE 32
# define ZOOM 30
# define ANGLE 0.75
# define COL_COR 100
# define CORECT 200
# define Z_COF 2

/* colors */
# define BROW 0xA0522D
# define GREEN 0x9ACD32
# define BLUE 0x87CEEB

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx_siera/mlx.h"
#include <stdio.h>

typedef struct s_data
{
	int		heig;
	int		widt;
	int		erfl;
	double	x;
	double	x1;
	double	y;
	double	y1;
	int		zoom;
	int		z_cof;
	double	z_cor;
	double	shift_x;
	double	shift_y;
	double	angle_x;
	double	angle_y;
	int		**arr;
	int		maxz;
	int		minz;
	int		c;
	
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

/* read_map.c*/
void	ft_read_map(t_data *data, char *av);

/* get_next_line.c */
int		get_next_line(int fd, char **line);

/* split.c */
int		ft_count_words(char const *s, char c);
char	**ft_split(char const *s, char c);

/* fdf_utils.c */
int		ft_atoi_m(char	*str, t_data *data);
size_t	ft_strlen_m(char *str, int c);
char	*ft_strjoin(char *ans, char *step);
int		ft_cheker_gnl(char *ost);

/* draw_lines.c */
void	ft_draw(t_data *data, int x, int y);
void	ft_draw_br(t_data *data);

#endif
