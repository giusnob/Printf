#include "ft_printf.h"

int	handle_without_minus(int negative, int total_len,
		t_flags flags)
{
	int	printed;

	printed = 0;
	if (flags.ovo && flags.precision == -1)
	{
		if (negative)
			printed += ft_putchar('-');
		else if (flags.plus)
			printed += ft_putchar('+');
		else if (flags.space)
			printed += ft_putchar(' ');
		printed += apply_width(flags.width, total_len, '0');
	}
	else
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}

int	handle_zero_without_precision(int negative, t_flags flags)
{
	int	printed;

	printed = 0;
	if (negative)
		printed += ft_putchar('-');
	else if (flags.plus)
		printed += ft_putchar('+');
	else if (flags.space)
		printed += ft_putchar(' ');
	return (printed);
}

int	count_total_len(t_flags flags, int num)
{
	int			len_num;
	int			effective_precision;
	int			total_len;

	len_num = count_digits(num);
	effective_precision = len_num;
	if (flags.precision > len_num)
		effective_precision = flags.precision;
	total_len = effective_precision;
	if (num < 0 || flags.plus || flags.space)
		total_len += 1;
	return (total_len);
}

int	handle_decimal(va_list *args, t_flags flags)
{
	const int	num = va_arg(*args, int);
	int			printed;
	long		n;
	int			total_len;

	total_len = count_total_len(flags, num);
	printed = 0;
	n = num;
	if (n < 0)
		n = -n;
	if (!flags.minus)
		printed += handle_without_minus(num < 0, total_len, flags);
	if (!(flags.ovo && flags.precision == -1))
		printed += handle_zero_without_precision(num < 0, flags);
	printed += apply_precision(flags.precision, count_digits(num));
	printed += ft_putnbr(n);
	if (flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}

int	handle_unsigned(va_list *args, t_flags flags)
{
	const unsigned int	n = va_arg(*args, unsigned int);
	const int			len_num = count_unsigned(n);
	int					prec_padding;
	int					total_len;
	int					printed;

	prec_padding = 0;
	if (flags.precision > len_num)
		prec_padding = flags.precision - len_num;
	total_len = len_num + prec_padding;
	printed = 0;
	if (!flags.minus && !flags.ovo)
		printed += apply_width(flags.width, total_len, ' ');
	if (!flags.minus && flags.ovo && flags.precision == -1)
		printed += apply_width(flags.width, total_len, '0');
	printed += apply_precision(flags.precision, len_num);
	printed += ft_putnbr_unsigned(n);
	if (flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}
