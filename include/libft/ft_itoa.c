/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enbuyuk <enbuyuk@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:13:41 by enbuyuk           #+#    #+#             */
/*   Updated: 2024/10/28 11:44:33 by enbuyuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dest;
	long	num;

	num = n;
	len = ft_nbrlen(num);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	if (num < 0)
	{
		dest[0] = '-';
		num *= -1;
	}
	if (num == 0)
		dest[0] = '0';
	while (num > 0)
	{
		dest[len--] = '0' + (num % 10);
		num /= 10;
	}
	return (dest);
}
