/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:53:11 by jobraga           #+#    #+#             */
/*   Updated: 2025/06/18 11:53:11 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *str, char c)
{
	int		word;

	word = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			while (*str != c && *str != '\0')
				str++;
			word++;
		}
	}
	return (word);
}

static size_t	ft_word_len(const char *str, char c)
{
	size_t		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*ft_copy_word(const char *str, size_t n)
{
	size_t		i;
	char		*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (n + 1));
	if (!word)
		return (NULL);
	while (i < n)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		cw;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	cw = ft_count_words(str, c);
	result = malloc(sizeof(char *) * (cw + 1));
	if (!result)
		return (NULL);
	while (*str && *str == c)
		str++;
	while (cw--)
	{
		result[i] = ft_copy_word(str, ft_word_len(str, c));
		if (!result[i])
			return (ft_free(result, i), NULL);
		str += ft_word_len(str, c);
		while (*str && *str == c)
			str++;
		i++;
	}
	result[i] = NULL;
	return (result);
}
