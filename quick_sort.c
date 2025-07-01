/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:35:29 by jobraga-          #+#    #+#             */
/*   Updated: 2025/06/30 21:13:18 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sorted(int *str, int size)
{
	int		i;
	int		swap;
	int		aux;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (str[i] > str[i + 1])
			{
				aux = str[i];
				str[i] = str[i + 1];
				str[i + 1] = aux;
				swap = 1;
			}
			i++;
		}
	}
	return (str);
}

int	*new_list(int *sort, int *orig, int *inside, int size)
{
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (orig[j] == sort[i])
			{
				inside[j] = i;
				break;
			}
			i++;
		}
		j++;
	}
	return (inside);
}

void	organizer_list(t_list **list_a, t_list **list_b)
{
	t_list	*node;

	calculate(list_a, list_b);
	node = calculate_cust(list_a);
	printf("%d\n", node->num);
	print_local(*list_a);
	if (node->total_cust == 0)
		return ;
}

void	quick_number(t_list **list_a, t_list **list_b, int size)
{
	int		*original;
	int		*sorted;
	int		*inside;
	int		num;
//	t_list	*node;

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
	organizer_list(list_a, list_b);
/*	push_pb(list_a, list_b);
	calculate(list_a, list_b);
	node = calculate_cust(list_a);
	printf("%d\n", node->num);
	print_local(*list_a);
	while (ft_lstsize(*list_a) > 7)
	{
		organizer_list(list_a, list_b);
		push_pb(list_a, list_b);
	}*/
	free(original);
	free(sorted);
	free(inside);
}
