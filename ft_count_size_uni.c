/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_size_uni.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:22:56 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:22:57 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size_of_unicode(wchar_t w_char)
{
	if (w_char <= 0x7F)
		return (1);
	else if (w_char > 0x7F && w_char <= 0x7FF)
		return (2);
	else if (w_char > 0x7FF && w_char <= 0xFFFF)
		return (3);
	else if (w_char > 0xFFFF && w_char <= 0x10FFFF)
		return (4);
	return (0);
}

int	ft_count_bytes_of_unicode(wchar_t *w_str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (w_str[i] != '\0')
	{
		count = count + ft_size_of_unicode(w_str[i]);
		i++;
	}
	return (count);
}

int	ft_count_len_prec(t_struc *struc)
{
	int i;
	int len;
	int tmp;

	i = 0;
	len = 0;
	while (struc->w_str[i] != '\0')
	{
		tmp = ft_size_of_unicode(struc->w_str[i]);
		if (struc->prec < len + tmp)
			return (len);
		len = len + tmp;
		i++;
	}
	return (len);
}
