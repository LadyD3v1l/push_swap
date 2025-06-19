/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:12:39 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/18 12:12:39 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

//ft_libft.c e ft_libft2.c
char	**ft_split(char const *str, char c);
int		ft_atoi(const char *str);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);

//parse_check.c
int		ft_check_arg(char *str);
void	ft_arg_int(t_list **stack, char *arg);

//parse_free.c
void	ft_free_array(char **result, int i);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);

//main.c


#endif