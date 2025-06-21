/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
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
	aux->next = NULL;
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
