/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 01:42:07 by jobraga-          #+#    #+#             */
/*   Updated: 2025/06/30 01:50:36 by jobraga-         ###   ########.fr       */
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
			if (value->num > aux->num
				&& (!aux->next || value->num < aux->next->num))
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
