/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:10:52 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:10:56 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_nb(intmax_t nb, int base)
{
	int	count;

	count = 0;
	if (nb > 0)
	{
		while (nb > 0)
		{
			nb = nb / base;
			count++;
		}
	}
	else if (nb == 0)
		count = 1;
	return (count);
}

char	*ft_itoa_intmax(intmax_t nb, int base, t_struc *struc)
{
	char	*arr;
	int		i;

	if (nb == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (nb < 0)
	{
		struc->minus = 1;
		nb = -nb;
	}
	i = ft_count_nb(nb, base);
	if (!(arr = ft_strnew(i + 1)))
		return (NULL);
	arr[i] = '\0';
	while (i-- > 0)
	{
		arr[i] = nb % base + ((nb % base) > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	return (arr);
}

char	*ft_itoa_uintmax(uintmax_t nb, int base, char type)
{
	uintmax_t	value;
	char		*arr;
	int			i;

	value = nb;
	i = 0;
	if (nb == 0)
		i = 1;
	while (value > 0)
	{
		value = value / base;
		i++;
	}
	if (!(arr = ft_strnew(i + 1)))
		return (NULL);
	arr[i] = '\0';
	while (i--)
	{
		if (type >= 'a' && type <= 'z')
			arr[i] = nb % base + ((nb % base) > 9 ? 'a' - 10 : '0');
		else
			arr[i] = nb % base + ((nb % base) > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	return (arr);
}
