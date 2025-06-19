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

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%i\n", lst->content);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*b;

	i = 1;
	a = NULL;
	b = NULL;
	while (i < ac)
	{
		if (ft_check_arg(av[i]))
			ft_arg_int(&a, av[i]);
		else
			ft_finish(&a);
		i++;
	}
	if (ft_check_list(a) != 2)
		ft_finish(&a);
	print_list(a);
	return (0);
}

int	ft_check_list(t_list *lst)
{
	int		*lst_arg;
	int		i;

	i = 0;
	lst_arg = ft_list_array(lst);
	if (ft_check_sorted(lst_arg, lst) == 1)
		i = i + 1;
	if (ft_check_iden(lst_arg, lst) == 1)
		i = i + 1;
	return (i);
}
