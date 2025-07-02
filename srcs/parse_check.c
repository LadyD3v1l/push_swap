/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:09:22 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/18 12:09:22 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (0);
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_arg_int(t_list **stack, char *arg)
{
	t_list	*node;
	int		inter;
	char	**array;
	long	num;

	array = ft_split(arg, ' ');
	inter = 0;
	while (array[inter])
	{
		num = ft_atoi(array[inter++]);
		if (num > INT_MAX || num < INT_MIN)
			ft_finish(stack);
		node = ft_lstnew(num);
		ft_lstadd_back(stack, node);
	}
	ft_free_array(array, inter);
}

int	*list_array(t_list *list)
{
	t_list	*aux;
	int		*array;
	int		i;

	i = 0;
	aux = list;
	array = malloc(sizeof(int) * ft_lstsize(list));
	if (!array)
		return (NULL);
	while (aux)
	{
		array[i] = aux->num;
		aux = aux->next;
		i++;
	}
	return (array);
}

int	check_iden(t_list *lst)
{
	int		i;
	int		j;
	int		size;
	int		*array;

	i = 0;
	size = ft_lstsize(lst);
	array = list_array(lst);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				free(array);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(array);
	return (1);
}

int	check_sorted(t_list *lst)
{
	int		i;
	int		size;
	int		*array;

	i = 0;
	size = ft_lstsize(lst);
	array = list_array(lst);
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			free(array);
			return (1);
		}
		i++;
	}
	free(array);
	return (0);
}
