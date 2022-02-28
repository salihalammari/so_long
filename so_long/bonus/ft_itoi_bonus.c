/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:22:04 by slammari          #+#    #+#             */
/*   Updated: 2022/02/27 18:44:27 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_nbr(long long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	if (n < 0)
		n = n * (-1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*calcul(long long nb, char *nbr, int len)
{
	int	sign;

	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = nb * (-1);
	}
	else if (nb == 0)
		nbr[0] = '0';
	nbr[len] = '\0';
	while (len--)
	{
		nbr[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign == 1)
		nbr[0] = '-';
	return (nbr);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	long long	nb;
	int			len;

	nb = n;
	len = count_nbr(nb);
	nbr = malloc(len + 1 * sizeof(char));
	if (!nbr)
		return (NULL);
	return (calcul(nb, nbr, len));
}

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
