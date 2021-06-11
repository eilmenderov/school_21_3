#ifndef HEAD_PUSH_SWAP_H
# define HEAD_PUSH_SWAP_H

# define MX_INT 2147483647
# define MN_INT -2147483648

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int				content;
	int				mvs;
	int				ind;
	char			*duo;
	struct s_list	*next;
}			t_list;

typedef struct s_data
{
	int		fl;
	int		argm;
	int		chek;
	int		size;
	int		*arr;
	int		lstn;
	char	*answ;
	t_list	*a_beg;
	t_list	*b_beg;
}			t_data;

char	**ft_split_m(char const *s, char c, int *ac, t_data	*data);
char	**ft_free_all(char **rez, int fl);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_pr_lstlast(t_list *lst);

int		ft_atoi_m(char	*str, t_data *data);
void	ft_init_data(t_data *dat);
int		ft_lstsize(t_list *lst);
int		ft_chek_sort(t_list *lst, t_data *data);
void	ft_print_data(t_data *data);

void	ft_swap_s(t_list *ma, t_data *data, int key);
void	ft_swap_ss(t_data *data);
void	ft_swap_r(t_list *lst, t_data *data, int key);
void	ft_swap_rr(t_data *data);
void	ft_swap_rrm(t_list *lst, t_data *data, int key);
void	ft_swap_rrr(t_data *data);
void	ft_push_el(t_data *data, int key);
size_t	ft_strlen_m(char *str, int c);
char	*ft_strjoin(char *ans, char *step);

void	ft_clear_memory(t_data *data);
int		ft_finish_chek(t_data *data);

void	ft_itoa_m_duo(t_data *data);
void	ft_new_solve(t_data *data);

void	ft_sort_chek_arr(t_data *data);
void	ft_solver(t_data *data);
void	ft_small_solve(t_data *data);
void	ft_solve_bsev(t_data *data);
void	ft_move_back(t_data *data);

int		ft_find_max(t_list *lst);
int		ft_find_min(t_list *lst);
int		ft_rot_dec(t_list *lst, int max, int min);
int		ft_exist_elpush_max(t_data *data, int mid);

void	ft_mov_impr(t_data *data, int mid);
void	ft_pb_impr(t_data *data, int mid);
void	ft_solve_bsm(t_data *data);
void	ft_best_mov(t_data *data);

#endif
