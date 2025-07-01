/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 01:42:07 by jobraga-          #+#    #+#             */
/*   Updated: 2025/07/01 11:12:58 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_local(t_list **list)
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
	int		i;
	int		local;
	t_list	*aux;
	t_list	*value;	

	i = ft_lstsize(*list_b);
	value = *list_a;
	while (value)
	{
		aux = *list_b;
		local = 0;
		while (aux)
		{
			if (value->num > aux->num || (value->num < aux->num
				&& (!aux->next || value->num > aux->next->num)))
				break ;
			local++;
			aux = aux->next;
		}
		if (local <= (i / 2))
			value->local_b = local;
		else
			value->local_b = local - i;
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
	calculate_local(list_a);
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
	return(point);
}
