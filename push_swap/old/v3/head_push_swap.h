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
	t_list	*buf;
	t_list	*a_beg;
	t_list	*b_beg;
}			t_data;

/* split.c */
char	**ft_split_m(char const *s, char c, int *ac, t_data	*data);
char	**ft_free_all(char **rez, int fl);

/* func_lst.c */
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_pr_lstlast(t_list *lst);

/* operat_p1.c */
void	ft_swap_s(t_data *data, int key);
void	ft_swap_ss(t_data *data);
void	ft_swap_r(t_data *data, int key);
void	ft_swap_rr(t_data *data);
void	ft_push_el(t_data *data, int key);

/* operat_p2_pu.c */
void	ft_swap_rrm(t_data *data, int key);
void	ft_swap_rrr(t_data *data);
void	ft_swap_bs(t_data *data);
void	ft_swap_br(t_data *data);
void	ft_swap_brr(t_data *data);

/* push_swap_utils.c */
void	ft_init_data(t_data *dat);
int		ft_atoi_m(char	*str, t_data *data);
int		ft_chek_sort(t_data *data, int i, int j, int key);
int		ft_short_way(t_data *data, int key, int min, int max);

/* solver.c */
void	ft_solver(t_data *data);

/* solver_utils.c */
int		ft_exist_elpush_min(t_data *data, int mid, int key);
int		ft_exist_elpush_max(t_data *data, int mid, int key);
int		ft_find_mid_index(t_data *data, int key);
void	ft_move_back(t_data *data);
int		ft_finish_chek(t_data *data);
size_t	ft_strlen_m(char *str, int c);
char	*ft_strjoin(char *ans, char *step);

/* small_solve.c */
int		ft_find_ind_mxmn(t_list *lst, int mnmx);
void	ft_small_solve(t_data *data, int key);

/* clear_dupl.c */
void	ft_clear_dupl(t_data *data);

/* sort_chek_arr.c */
void	ft_sort_chek_arr(t_data *data);

/* clear_memory.c */
void	ft_clear_memory(t_data *data);
int		ft_lstsize(t_list *lst);

/* temp.c */
void	ft_print_data(t_data *data);

#endif
