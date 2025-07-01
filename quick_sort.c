/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:35:29 by jobraga-          #+#    #+#             */
/*   Updated: 2025/07/02 00:49:20 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_list(t_list **list_a, t_list **list_b, int *posi_a, int *posi_b)
{
	int		posi;

	posi = 0;
	while (*posi_a > 0 && *posi_b > 0)
	{
		rotate_rr(list_a, list_b);
		(*posi_a)--;
		(*posi_b)--;
		posi++;
	}
	while (*posi_a > 0)
	{
		rotate_ra(list_a);
		(*posi_a)--;
	}
	while (*posi_b > 0)
	{
		rotate_rb(list_b);
		(*posi_b)--;
		posi++;
	}
	return (posi);
}

int	reverse_list(t_list **list_a, t_list **list_b, int *posi_a, int *posi_b)
{
	int		posi;

	posi = 0;
	while (*posi_a < 0 && *posi_b < 0)
	{
		reverse_rrr(list_a, list_b);
		(*posi_a)++;
		(*posi_b)++;
		posi++;
	}
	while (*posi_a < 0)
	{
		reverse_rra(list_a);
		(*posi_a)++;
	}
	while (*posi_b < 0)
	{
		reverse_rrb(list_b);
		(*posi_b)++;
		posi++;
	}
	return (posi);
}

int	check_sorted_list(t_list *lst)
{
	int		i;
	int		size;
	int		*array;

	i = 0;
	size = ft_lstsize(lst);
	array = list_array(lst);
	while (i < size - 1)
	{
		if (array[i] < array[i + 1])
		{
			free(array);
			return (0);
		}
		i++;
	}
	free(array);
	return (1);
}

void	organizer_list(t_list **list_a, t_list **list_b)
{
	t_list	*node;
	int		a;
	int		b;

	calculate(list_a, list_b);
	node = calculate_cust(list_a);
	a = node->local_a;
	b = node->local_b;
	rotate_list(list_a, list_b, &a, &b);
	reverse_list(list_a, list_b, &a, &b);
	if (a == 0 && b == 0)
	{
		push_pb(list_a, list_b);
		while (check_sorted_list(*list_b) != 1)
			rotate_rb(list_b);
		if (check_sorted_list(*list_b) == 0)
			return ;
	}
}

void	quick_number(t_list **list_a, t_list **list_b, int size)
{
	int		*original;
	int		*sorted;
	int		*inside;
	int		num;

	original = list_array(*list_a);
	sorted = bubble_sorted(list_array(*list_a), size);
	inside = malloc(sizeof(int) * size);
	if (!inside)
		return ;
	inside = new_list(sorted, original, inside, size);
	ft_lstclear(list_a);
	num = 0;
	while (num < size)
		ft_lstadd_back(list_a, ft_lstnew(inside[num++]));
	push_pb(list_a, list_b);
	push_pb(list_a, list_b);
	if (check_sorted(*list_b) != 1)
		swap_pb(list_b);
	while (ft_lstsize(*list_a) > 0)
		organizer_list(list_a, list_b);
	free(original);
	free(sorted);
	free(inside);
}
