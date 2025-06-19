/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
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

/*int		ft_check_list(t_list **stack)
{
	int		i;
	int		j;
	t_list	*node;

	i = ft_lstsize(stack);
	while()
}*/

void	ft_arg_int(t_list **stack, char *arg)
{
	t_list	*node;
	int		i;
	char	**array;
	long	num;

	array = ft_split(arg, ' ');
	i = 0;
	while (array[i])
	{
		num = ft_atoi(array[i++]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_lstclear(stack);
			write(2, "Error\n", 6);
			exit ;
		}
		node = ft_lstnew(num);
		ft_lstadd_back(stack, node);
	}
	ft_free_array(array, i);
}
