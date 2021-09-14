#ifndef HEAD_FDF_BONUS_H
# define HEAD_FDF_BONUS_H

# define MX_INT 			2147483647
# define MN_INT 			-2147483648
# define M_PI 				3.14159265358979323846
# define BUFFER_SIZE 		32
# define ZOOM 				15
# define ANGLE 				0.52
# define CORECT 			250
# define UNIQ_BPP 			4

/* color */
# define COLOR_TEXT			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E
# define COLOR_UP			0xEF8633
# define COLOR_RED			0xCC3333
# define COLOR_ZERO			0x33FF00
# define COLOR_WHITE		0xFFFFCC
# define COLOR_DEEP			0x00CCFF

/* resolution */
# define WIDTH				1280
# define HEIGHT				720
# define MENU_WIDTH			250

/* libs */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx_siera/mlx.h"

typedef struct s_data
{
	int				height;
	int				width;
	int				erfl;
	int				maxz;
	int				minz;
	int				b_lock;
	int				line_point;
	int				zoom;
	int				projection;
	double			rad_z;
	double			pl_rad;
	double			angle;
	double			alpha;
	double			beta;
	double			gamma;
	double			z_corr;
	int				x_shift;
	int				y_shift;
	int				treug;
	unsigned int	color;
	int				**arr;

	int				st_x;
	int				st_y;
	int				st_z;
	unsigned int	st_c;
	int				end_x;
	int				end_y;
	int				end_z;
	unsigned int	end_c;
	int				cur_x;
	int				cur_y;
	unsigned int	cur_c;

	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
}			t_data;

/* read_map.c*/
void			ft_read_map(t_data *data, char *av);

/* get_next_line.c */
int				get_next_line(int fd, char **line);

/* split.c */
int				ft_count_words(char const *s, char c);
char			**ft_split(char const *s, char c);

/* fdf_utils.c */
int				ft_atoi_m(char	*str, t_data *data);
size_t			ft_strlen_m(char *str, int c);
char			*ft_strjoin(char *ans, char *step);
int				ft_cheker_gnl(char *ost);
void			ft_key_help_p2(int key, t_data *data);

/* draw_img.c */
void			draw_image(t_data *data, int x, int y);

/* draw_utils.c */
void			ft_isometric(int *x, int *y, int z);
void			ft_print_menu(t_data *data, int y);
int				ft_abs(int a);
int				ft_comper(int a, int b);
void			*ft_memset(void *b, int c, size_t len);

/* color.c */
unsigned int	ft_get_color(t_data *data, int x, int y);
unsigned int	ft_get_default_color(int z, t_data *data);
int				ft_on_off(int a);

/* pool_st_end.c */
void			ft_pool_st(t_data *data, int x, int y);
void			ft_pool_end(t_data *data, int x, int y);
#endif
