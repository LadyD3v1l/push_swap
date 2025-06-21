/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:54:45 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/18 11:54:45 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int			i;
	long		num;
	int			sig;

	i = 0;
	num = 0;
	sig = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if ((str[i]) == '-')
			sig *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sig);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(int));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (!lst)
		return (0);
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
