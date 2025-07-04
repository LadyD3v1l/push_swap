/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:35:29 by jobraga-          #+#    #+#             */
/*   Updated: 2025/07/03 16:35:39 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_list **list_a, t_list **list_b, int *posi_a, int *posi_b)
{
	while (*posi_a > 0 && *posi_b > 0)
	{
		rotate_rr(list_a, list_b);
		(*posi_a)--;
		(*posi_b)--;
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
	}
}

void	reverse_list(t_list **list_a, t_list **list_b, int *posi_a, int *pos_b)
{
	while (*posi_a < 0 && *pos_b < 0)
	{
		reverse_rrr(list_a, list_b);
		(*posi_a)++;
		(*pos_b)++;
	}
	while (*posi_a < 0)
	{
		reverse_rra(list_a);
		(*posi_a)++;
	}
	while (*pos_b < 0)
	{
		reverse_rrb(list_b);
		(*pos_b)++;
	}
}

t_list	*calculate_list(t_list **list)
{
	t_list	*point;
	t_list	*aux;
	int		upper;

	aux = *list;
	point = aux;
	upper = aux->num;
	while (aux)
	{
		if (aux->num > upper)
		{
			upper = aux->num;
			point = aux;
		}
		aux = aux->next;
	}
	return (point);
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
		push_pb(list_a, list_b);
}

void	push_number(t_list **list_a, t_list **list_b, int size)
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
