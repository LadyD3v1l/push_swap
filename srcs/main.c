/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:21:21 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/18 12:21:21 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_upper(t_list **list_a, t_list **list_b, int size)
{
	t_list	*node;
	int		rotate;

	push_number(list_a, list_b, size);
	calculate_local_a(list_b);
	node = calculate_list(list_b);
	rotate = node->local_a;
	while (rotate < 0)
	{
		reverse_rrb(list_b);
		rotate++;
	}
	while (rotate > 0)
	{
		rotate_rb(list_b);
		rotate--;
	}
	while (ft_lstsize(*list_b) > 0)
		push_pa(list_a, list_b);
}

void	push_swap(t_list **list_a, t_list **list_b)
{
	int		len;

	len = ft_lstsize(*list_a);
	if (len == 2)
		swap_pa(list_a);
	else if (len == 3)
		push_tree(list_a);
	else if (len == 4 || len == 5)
		push_fove(list_a, list_b, len);
	else
		push_swap_upper(list_a, list_b, len);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		if (ft_check_arg(av[i]))
			ft_arg_int(&a, av[i]);
		else
			ft_finish(&a);
		i++;
	}
	if (check_iden(a) == 0)
		ft_finish(&a);
	if (check_sorted(a) == 0)
		ft_clear(&a);
	push_swap(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
