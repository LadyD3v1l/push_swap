/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:26:20 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/21 16:26:20 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_pa(t_list **stack)
{
	ft_swap(stack);
	write(1, "sa\n", 3);
}

void	swap_pb(t_list **stack)
{
	ft_swap(stack);
	write(1, "sb\n", 3);
}
