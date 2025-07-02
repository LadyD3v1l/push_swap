/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 01:42:07 by jobraga-          #+#    #+#             */
/*   Updated: 2025/07/02 22:39:17 by jobraga-         ###   ########.fr       */
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

int	best_local_list(t_list *list_b, int num)
{
	t_list	*best;
	t_list	*tmp;

	best = NULL;
	tmp = list_b;
	while (tmp)
	{
		if (tmp->num < num)
		{
			if (!best || tmp->num > best->num)
				best = tmp;
		}
		tmp = tmp->next;
	}
	if (best)
		return (best->local_a);
	best = list_b;
	tmp = list_b;
	while (tmp)
	{
		if (tmp->num > best->num)
			best = tmp;
		tmp = tmp->next;
	}
	return (best->local_a);
}

void	calculate_rotate(t_list **list_a, t_list **list_b)
{
	t_list	*value;

	value = *list_a;
	while (value)
	{
		value->local_b = best_local_list(*list_b, value->num);
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
