/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enbuyuk <enbuyuk@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:13:38 by enbuyuk           #+#    #+#             */
/*   Updated: 2024/10/28 11:45:20 by enbuyuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		new_index;
	char	**new;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	new_index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > j)
			new[new_index++] = ft_substr(s, j, i - j);
	}
	new[new_index] = NULL;
	return (new);
}
