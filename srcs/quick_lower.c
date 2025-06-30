/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_lower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:26:00 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/20 17:26:00 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_tree(t_list **list_a)
{
	t_list	*aux;

	aux = *list_a;
	if (aux->num < aux->next->num && aux->num < aux->next->next->num)
	{
		reverse_ra(list_a);
		swap_pa(list_a);
	}
	else if (aux->num > aux->next->num && aux->num < aux->next->next->num)
		swap_pa(list_a);
	else if (aux->num < aux->next->num && aux->num > aux->next->next->num)
		reverse_ra(list_a);
	else if (aux->num > aux->next->num && aux->num > aux->next->next->num)
	{
		rotate_ra(list_a);
		aux = *list_a;
		if (aux->num > aux->next->num)
			swap_pa(list_a);
	}
	else
	{
		swap_pa(list_a);
		reverse_ra(list_a);
	}
}

int	lower_num(t_list **list_a)
{
	t_list	*aux;
	int		low;

	aux = *list_a;
	low = aux->num;
	while (aux)
	{
		if (aux->num < low)
		{
			low = aux->num;
			continue ;
		}
		aux = aux->next;
	}
	return (low);
}

int	lower_posi(t_list **list, int low)
{
	int		posi;
	t_list	*aux;

	aux = *list;
	posi = 0;
	while (aux)
	{
		if (aux->num == low)
			return (posi);
		aux = aux->next;
		posi++;
	}
	return (posi);
}

void	move_rotate(t_list **list, int posi, int size, int low)
{
	t_list	*aux;

	aux = *list;
	if (posi <= (size / 2) && aux->num != low)
		rotate_ra(list);
	else if (posi > (size / 2) && aux->num != low)
		reverse_ra(list);
}

void	quick_fove(t_list **list_a, t_list **list_b, int size)
{
	int		num;
	int		lower;
	t_list	*aux;

	num = size;
	lower = lower_num(list_a);
	while (num > 3 && *list_a)
	{
		aux = *list_a;
		if (aux->num != lower)
			move_rotate(list_a, lower_posi(list_a, lower), size, lower);
		else if (aux->num == lower)
		{
			push_pb(list_a, list_b);
			lower = lower_num(list_a);
			num--;
		}
	}
	quick_tree(list_a);
	while (num != size)
	{
		push_pa(list_a, list_b);
		num++;
	}
}
