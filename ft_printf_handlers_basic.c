/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers_basic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:24:36 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/17 14:49:51 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_percent(t_flags flags)
{
	(void)flags;
	return (ft_putchar('%'));
}

int	handle_char(va_list *args, t_flags flags)
{
	char	c;
	int		printed;

	c = va_arg(*args, int);
	printed = 0;
	if (!flags.minus)
		printed += apply_width(flags.width, 1, ' ');
	printed += ft_putchar(c);
	if (flags.minus)
		printed += apply_width(flags.width, 1, ' ');
	return (printed);
}

int	handle_string(va_list *args, t_flags flags)
{
	char	*str;
	int		len_str;
	int		printed;

	str = va_arg(*args, char *);
	printed = 0;
	if (!str)
		str = "";
	len_str = ft_strlen(str);
	if (flags.precision >= 0 && flags.precision < len_str)
		len_str = flags.precision;
	if (!flags.minus)
		printed += apply_width(flags.width, len_str, ' ');
	printed += ft_putstr_precision(str, flags.precision);
	if (flags.minus)
		printed += apply_width(flags.width, len_str, ' ');
	return (printed);
}
