#include "ft_printf.h"

int	apply_width(int width, int content_len, char pad)
{
	int	count;
	int	pad_len;

	count = 0;
	pad_len = width - content_len;
	while (pad_len-- > 0)
	{
		ft_putchar(pad);
		count++;
	}
	return (count);
}

int	apply_precision(int precision, int num_len)
{
	int	count;
	int	pad_len;

	count = 0;
	pad_len = precision - num_len;
	while (pad_len-- > 0)
	{
		ft_putchar('0');
		count++;
	}
	return (count);
}

int	ft_putstr_precision(char *str, int precision)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str && (precision < 0 || len < precision))
	{
		ft_putchar(*str);
		len++;
		str++;
	}
	return (len);
}
