/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
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
	int				num;
	struct s_list	*next;
}					t_list;

//ft_libft.c
char	**ft_split(char const *str, char c);

//ft_libft2.c
long	ft_atoi(const char *str);
t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);

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

//quick_quick.c
void	quick_tree(t_list **list_a);

//ft_push
void	ft_push(t_list **dest, t_list **src);
void	push_pb(t_list **stack_a, t_list **stack_b);
void	push_pa(t_list **stack_a, t_list **stack_b);

//ft_reverse
void	ft_reverse(t_list **stack);
void	reverse_ra(t_list **stack);
void	reverse_rb(t_list **stack);

//ft_rotate
void	ft_rotate(t_list **stack);
void	rotate_ra(t_list **stack);
void	rotate_rb(t_list **stack);

//ft_swap
void	ft_swap(t_list **stack);
void	swap_pa(t_list **stack);
void	swap_pb(t_list **stack);

//main.c
int		ft_check_list(t_list *lst);

#endif