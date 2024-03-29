/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:38:36 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/03 15:38:37 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int i;

	i = 1;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = (n * (-1));
	}
	while (i < n / 10)
	{
		i = i * 10;
	}
	while (i != 0)
	{
		ft_putchar(n / i + '0');
		n = n % i;
		i = i / 10;
	}
}
