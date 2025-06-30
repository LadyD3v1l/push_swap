/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:38:33 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/20 11:38:33 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **dest, t_list **src)
{
	t_list	*temp;

	if (!*src || !src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	ft_lstadd_front(dest, temp);
}

void	push_pb(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	push_pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}
