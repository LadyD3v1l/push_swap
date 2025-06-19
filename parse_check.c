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

int		ft_check_arg(char *str)
{
	int		i;

	i = 0;	
	while (str[i])
	{
		if(str[i] == ' ')
			i++;
		if (str[i] == '-'|| str[i] == '+')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return(0);
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
	int		i;
	char	**array;

	array = ft_split(arg, ' ');
	i = 0;
	while(array[i])
	{
		node = ft_lstnew(ft_atoi(array[i++]));
		ft_lstadd_back(stack, node);
	}
	ft_free_array(array, i);
}

