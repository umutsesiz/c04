/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usesiz <usesiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:31:09 by usesiz            #+#    #+#             */
/*   Updated: 2022/02/28 12:39:42 by usesiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	k;

	i = 0;
	while (base[i])
	{
		k = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[k])
		{
			if (base[i] == base[k])
				return (0);
			k++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	nb;

	size = check_base(base);
	if (size != 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = nbr * -1;
		}
		else
			nb = nbr;
		if (nb >= size)
		{
			ft_putnbr_base(nb / size, base);
			ft_putchar(base[nb % size]);
		}
		else
			ft_putchar(base[nb % size]);
	}
}
/*int		main(void)
{
	ft_putnbr_base(12, "01");
	printf("\n");
	ft_putnbr_base(40, "poneyvif");
	printf("\n");
	ft_putnbr_base(894867, "0123456789");
	printf("\n");
	ft_putnbr_base(59, "0123456789abcdef");
}*/
