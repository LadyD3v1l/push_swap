/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:21:21 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/18 12:21:21 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *lst)
{
	while(lst)
	{
		printf("%i\n", lst->content);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*a;

	i = 1;
	a = NULL;
	while(i < ac)
	{
		if(ft_check_arg(av[i]))
			ft_arg_int(&a, av[i]);
		else
		{
			ft_lstclear(&a);
			write(2, "Error\n", 6);
		}
		i++;
	}
	print_list(a);
	return (0);
}
