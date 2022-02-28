/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:04:56 by slammari          #+#    #+#             */
/*   Updated: 2022/02/27 19:32:23 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb <= 9)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
