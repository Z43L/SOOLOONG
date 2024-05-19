/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrd_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:10:37 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/19 23:18:36 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LIBFT/libft.h"
#include <stdbool.h>

int	printnbr(long c, int len, bool tof, int base)
{
	char	*hexmayus;
	char	*hexminus;

	hexmayus = "0123456789ABCDEF";
	hexminus = "0123456789abcdef";
	if (tof == true)
		len += ft_putchar_fd(hexmayus[c % base]);
	else if (tof == false)
		len += ft_putchar_fd(hexminus[c % base]);
	else
		len += ft_putchar_fd(c % base + '0');
	return (len);
}

int	ft_putnbrd_base(long c, int base, int len, bool tof)
{
	if (c < 0)
	{
		len += ft_putchar_fd('-');
		c = -c;
	}
	if (c >= base)
		len += ft_putnbrd_base(c / base, base, len, tof);
	len = printnbr(c, len, tof, base);
	return (len);
}
