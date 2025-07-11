/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:52:15 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/18 15:52:15 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		aux = *lst;
		*lst = (*lst)->next;
		free(aux);
	}
}

void	ft_free_array(char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
}

void	ft_finish(t_list **list)
{
	ft_lstclear(list);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_clear(t_list **list)
{
	ft_lstclear(list);
	exit(EXIT_FAILURE);
}
