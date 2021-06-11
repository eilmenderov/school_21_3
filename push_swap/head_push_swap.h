#ifndef HEAD_PUSH_SWAP_H
# define HEAD_PUSH_SWAP_H

# define MX_INT 2147483647
# define MN_INT -2147483648
# define BUFFER_SIZE 32

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				mvs;
	int				ind;
	unsigned char	des;
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

/* push_swap_utils.c */
void	ft_init_data(t_data *dat);
int		ft_atoi_m(char	*str, t_data *data);
int		ft_chek_sort(t_data *data, int i, int j, int key);
int		ft_short_way(t_data *data, int key, int min, int max);

/* second_step.c */
int		ft_find_unit(t_data *data, int ind, int mn, int mx);
int		ft_second_step(t_data *data);

/* solver.c */
void	ft_solver(t_data *data);

/* solver_utils_p1.c */
int		ft_find_mid_index(t_data *data, int key);
int		ft_finish_chek(t_data *data);

/* solver_utils_p2.c */
size_t	ft_strlen_m(char *str, int c);
char	*ft_strjoin(char *ans, char *step);
void	ft_tfs_helper(int *i, int *rez, int *mstep, int k);
int		ft_next_tfind(t_list *lst);

/* first_step.c */
void	ft_first_step(t_data *data, t_list *tmp, int prev);

/* small_solve.c */
int		ft_find_ind_mxmn(t_list *lst, int mnmx);
void	ft_small_solve(t_data *data, int key);

/* sort_chek_arr.c */
void	ft_creat_arr(t_data *data);
void	ft_sort_chek_arr(t_data *data);

/* clear_memory.c */
void	ft_clear_memory(t_data *data);
int		ft_lstsize(t_list *lst);

/* checker_utils.c */
int		ft_cheker_gnl(char *ost);
int		ft_chek_alst(t_data *data);

/* get_next_line.c */
int		get_next_line(int fd, char **line);

#endif
