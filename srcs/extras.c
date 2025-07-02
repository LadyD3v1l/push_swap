/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:43:35 by jobraga-          #+#    #+#             */
/*   Updated: 2025/07/02 22:57:36 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sorted(int *str, int size)
{
	int		i;
	int		swap;
	int		aux;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (str[i] > str[i + 1])
			{
				aux = str[i];
				str[i] = str[i + 1];
				str[i + 1] = aux;
				swap = 1;
			}
			i++;
		}
	}
	return (str);
}

int	*new_list(int *sort, int *orig, int *inside, int size)
{
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (orig[j] == sort[i])
			{
				inside[j] = i + 1;
				break ;
			}
			i++;
		}
		j++;
	}
	return (inside);
}

int	check_sorted_list(t_list *lst)
{
	int		i;
	int		size;
	int		*array;

	i = 0;
	size = ft_lstsize(lst);
	array = list_array(lst);
	while (i < size - 1)
	{
		if (array[i] < array[i + 1])
		{
			free(array);
			return (0);
		}
		i++;
	}
	free(array);
	return (1);
}

void	calculate(t_list **list_a, t_list **list_b)
{
	calculate_local_a(list_a);
	calculate_local_a(list_b);
	calculate_rotate(list_a, list_b);
	calculate_total(list_a);
}
