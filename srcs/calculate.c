/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 01:42:07 by jobraga-          #+#    #+#             */
/*   Updated: 2025/07/02 14:23:50 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_local_a(t_list **list)
{
	int		i;
	int		local;
	t_list	*aux;

	aux = *list;
	i = ft_lstsize(*list);
	local = 0;
	while (aux)
	{
		if (local <= (i / 2))
			aux->local_a = local;
		else
			aux->local_a = local - i;
		local++;
		aux = aux->next;
	}
}

void	calculate_rotate(t_list **list_a, t_list **list_b)
{
	t_list	*aux;
	t_list	*value;

	value = *list_a;
	while (value)
	{
		aux = *list_b;
		while (aux)
		{
			if (value->num < aux->num
				&& (!aux->next || value->num > aux->next->num))
			{
				if (!aux->next)
					value->local_b = 0;
				else
					value->local_b = aux->next->local_a;
				break ;
			}
			aux = aux->next;
		}
		value = value->next;
	}
}

void	calculate_total(t_list **list)
{
	t_list	*aux;

	aux = *list;
	while (aux)
	{
		aux->total_cust = abs(aux->local_a) + abs(aux->local_b);
		aux = aux->next;
	}
}

void	calculate(t_list **list_a, t_list **list_b)
{
	calculate_local_a(list_a);
	calculate_local_a(list_b);
	calculate_rotate(list_a, list_b);
	calculate_total(list_a);
}

t_list	*calculate_cust(t_list **list)
{
	t_list	*point;
	t_list	*aux;
	int		low;

	aux = *list;
	point = aux;
	low = aux->total_cust;
	while (aux)
	{
		if (aux->total_cust < low)
		{
			low = aux->total_cust;
			point = aux;
		}
		aux = aux->next;
	}
	return (point);
}
