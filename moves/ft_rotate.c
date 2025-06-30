/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:41:38 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/21 15:41:38 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*aux;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	aux = *stack;
	*stack = aux->next;
	(*stack)->prev = NULL;
	aux->next = NULL;
	aux->prev = NULL;
	ft_lstadd_back(stack, aux);
}

void	rotate_ra(t_list **stack)
{
	ft_rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_rb(t_list **stack)
{
	ft_rotate(stack);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
