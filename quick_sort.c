/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:35:29 by jobraga-          #+#    #+#             */
/*   Updated: 2025/06/26 19:11:11 by jobraga-         ###   ########.fr       */
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
	return(str);
}

void	quick_number(t_list **list_a, int size)
{
	int		*original;
	int		*sorted;
	int		inside[size - 1];
	int		i;
	int		copied;
	int		j;
	int		k;

	original = list_array(*list_a);
	sorted = bubble_sorted(list_array(*list_a), size);
	copied = 1;
	j = 0;
	k = 0;
	while (copied)
	{
		copied = 0;
		i = 0;
		while(i < size)
		{
			if (original[j] == sorted[i])
			{
				inside[k] = i;
				i = 0;
				j++;
				k++;
				copied = 1;
			}
			i++;
		}
	}
}
