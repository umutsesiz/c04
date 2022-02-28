/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usesiz <usesiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:17:24 by usesiz            #+#    #+#             */
/*   Updated: 2022/02/28 12:37:33 by usesiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int numb)
{
	if (numb == -2147483648)
	{
		ft_putchar('-');
		write(1, "2147483648", 10);
	}
	else if (numb < 0)
	{
		ft_putchar('-');
		numb = numb * -1;
		ft_putnbr(numb);
	}
	else if (numb <= 9)
	{
		ft_putchar(numb + '0');
	}
	else
	{
		ft_putnbr(numb / 10);
		ft_putnbr(numb % 10);
	}
}
