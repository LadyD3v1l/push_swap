/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
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
