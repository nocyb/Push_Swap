/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:25:20 by njung             #+#    #+#             */
/*   Updated: 2025/02/25 15:13:27 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	count(int n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	len;
	long			nbr;

	nbr = n;
	len = count(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
		nbr = -nbr;
	res[len] = '\0';
	while (len-- > 0)
	{
		res[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
	free(res);
}

/*int	main(void)
{
	int	n;

	n = -1547483647;
	printf("%s", ft_itoa(n));
	return (0);
}
int	count(int n)
{
	int	taille;
	int	multiple;

	taille = 1;
	multiple = 10;
	while (n / multiple != 0)
	{
		taille += 1;
		multiple *= 10;
	}
	return (taille);
}*/