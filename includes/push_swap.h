/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:12:39 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/18 12:12:39 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				local_a;
	int				local_b;
	int				total_cust;
	int				num;		//valor armazenado
	struct s_list	*next;		//próximo elemento
	struct s_list	*prev;		//elemento anterior
}					t_list;

void	print_local(t_list *lst);

//big_cases.c
void	rotate_list(t_list **list_a, t_list **list_b, int *posi_a, int *posi_b);
void	reverse_list(t_list **list_a, t_list **list_b, int *posi_a, int *pos_b);
t_list	*calculate_list(t_list **list);
void	organizer_list(t_list **list_a, t_list **list_b);
void	push_number(t_list **list_a, t_list **list_b, int size);

//calculate.c
void	calculate_local_a(t_list **list);
int		best_local_list(t_list *list_b, int num);
void	calculate_rotate(t_list **list_a, t_list **list_b);
void	calculate_total(t_list **list);
t_list	*calculate_cust(t_list **list);

//extras.c
int		*bubble_sorted(int *str, int size);
int		*new_list(int *sort, int *orig, int *inside, int size);
int		check_sorted_list(t_list *lst);
void	calculate(t_list **list_a, t_list **list_b);

//libft.c
char	**ft_split(char const *str, char c);

//libft2.c
long	ft_atoi(const char *str);
t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);

//main.c
void	push_swap_upper(t_list **list_a, t_list **list_b, int size);
void	push_swap(t_list **list_a, t_list **list_b);

//parse_check.c
int		ft_check_arg(char *str);
void	ft_arg_int(t_list **stack, char *arg);
int		*list_array(t_list *list);
int		check_iden(t_list *lst);
int		check_sorted(t_list *lst);

//parse_free.c
void	ft_free_array(char **result, int i);
void	ft_lstclear(t_list **lst);
void	ft_finish(t_list **list);
void	ft_clear(t_list **list);

//small_cases.c
void	push_tree(t_list **list_a);
int		lower_num(t_list **list_a);
int		lower_posi(t_list **list, int low);
void	move_rotate(t_list **list, int posi, int size, int low);
void	push_fove(t_list **list_a, t_list **list_b, int size);

//ft_push
void	ft_push(t_list **dest, t_list **src);
void	push_pb(t_list **stack_a, t_list **stack_b);
void	push_pa(t_list **stack_a, t_list **stack_b);

//ft_reverse.c
void	ft_reverse(t_list **stack);
void	reverse_rra(t_list **stack);
void	reverse_rrb(t_list **stack);
void	reverse_rrr(t_list **stack_a, t_list **stack_b);

//ft_rotate.c
void	ft_rotate(t_list **stack);
void	rotate_ra(t_list **stack);
void	rotate_rb(t_list **stack);
void	rotate_rr(t_list **stack_a, t_list **stack_b);

//ft_swap.c
void	ft_swap(t_list **stack);
void	swap_pa(t_list **stack);
void	swap_pb(t_list **stack);

#endif