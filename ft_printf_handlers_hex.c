#include "ft_printf.h"

static int	count_hex(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static int	get_total_len(unsigned int n, t_flags flags)
{
	int				len_hex;
	int				prec_padding;
	int				prefix_len;
	int				total_len;

	len_hex = count_hex(n);
	prec_padding = 0;
	if (flags.precision > len_hex)
		prec_padding = flags.precision - len_hex;
	prefix_len = 0;
	if (flags.hash && n != 0)
		prefix_len = 2;
	total_len = prefix_len + prec_padding + len_hex;
	return (total_len);
}

int	handle_hex(va_list *args, t_flags flags, char type)
{
	const unsigned int	n = va_arg(*args, unsigned int);
	const int			len_hex = count_hex(n);
	int					total_len;
	int					printed;

	printed = 0;
	total_len = get_total_len(n, flags);
	if (!flags.minus && !flags.ovo)
		printed += apply_width(flags.width, total_len, ' ');
	if (!flags.minus && flags.ovo && flags.precision == -1)
		printed += apply_width(flags.width, total_len, '0');
	if (flags.hash && n != 0 && type == 'x')
		printed += ft_putstr("0x");
	else if (flags.hash && n != 0 && type == 'X')
		printed += ft_putstr("0X");
	printed += apply_precision(flags.precision, len_hex);
	printed += ft_puthex(n, type);
	if (flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}

int	handle_pointer(va_list *args, t_flags flags)
{
	const unsigned long	ptr = va_arg(*args, unsigned long);
	int					printed;
	int					hex_count;
	int					total_len;

	printed = 0;
	hex_count = count_hex(ptr);
	if (!ptr)
		return (ft_putstr("(nil)"));
	total_len = 2 + hex_count;
	if (hex_count > 0)
		total_len = 3;
	if (!flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	printed += ft_putstr("0x");
	printed += ft_puthex(ptr, 'x');
	if (flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}
