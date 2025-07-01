/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insider.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:43:35 by jobraga-          #+#    #+#             */
/*   Updated: 2025/07/02 00:50:57 by jobraga-         ###   ########.fr       */
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
				inside[j] = i;
				break ;
			}
			i++;
		}
		j++;
	}
	return (inside);
}
