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

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%i\n", lst->num);
		lst = lst->next;
	}
}

void	print_local(t_list *lst)
{
	while (lst)
	{
		printf("num: %i ", lst->num);
		printf("local_a: %i ", lst->local_a);
		printf("local_b: %i ", lst->local_b);
		printf("total_cust: %i\n", lst->total_cust);
		lst = lst->next;
	}
}

void	push_swap(t_list **list_a, t_list **list_b)
{
	int	len;

	len = ft_lstsize(*list_a);
	if (len == 2)
		swap_pa(list_a);
	else if (len == 3)
		quick_tree(list_a);
	else if (len == 4 || len == 5)
		quick_fove(list_a, list_b, len);
	else
		quick_number(list_a, list_b, len);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*b;

	i = 1;
	a = NULL;
	b = NULL;
	while (i < ac)
	{
		if (ft_check_arg(av[i]))
			ft_arg_int(&a, av[i]);
		else
			ft_finish(&a);
		i++;
	}
	if (ft_check_list(a) != 2)
		ft_finish(&a);
	push_swap(&a, &b);
/*	printf("\na:\n");
	print_list(a);
	printf("\nb:\n");
	print_list(b);*/
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}

int	ft_check_list(t_list *lst)
{
	int		i;

	i = 0;
	if (check_sorted(lst) == 1)
		i = i + 1;
	if (check_iden(lst) == 1)
		i = i + 1;
	return (i);
}

// 18446744073709551630 1