/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:01:30 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/20 21:01:30 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_list **stack)
{
	t_list	*aux;
	t_list	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	aux = *stack;
	while (aux->next)
		aux = aux->next;
	before_last = aux->prev;
	before_last->next = NULL;
	aux->prev = NULL;
	aux->next = NULL;
	ft_lstadd_front(stack, aux);
}

void	reverse_ra(t_list **stack)
{
	ft_reverse(stack);
	write(1, "rra\n", 4);
}

void	reverse_rb(t_list **stack)
{
	ft_reverse(stack);
	write(1, "rrb\n", 4);
}

void	reverse_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	write(1, "rrr\n", 4);
}
