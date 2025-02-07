#include "ft_printf.h"

int ft_putchar(char c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int len = 0;
    if (!str)
        str = "(null)";
    while (*str)
    {
        ft_putchar(*str);
        len++;
        str++;
    }
    return (len);
}

int ft_putstr_precision(char *str, int precision)
{
    int len = 0;
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

int ft_putnbr(long n)
{
    int len = 0;
    if (n < 0)
    {
        len += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        len += ft_putnbr(n / 10);
    len += ft_putchar((n % 10) + '0');
    return (len);
}

int ft_putnbr_unsigned(unsigned int n)
{
    int len = 0;
    if (n >= 10)
        len += ft_putnbr_unsigned(n / 10);
    len += ft_putchar((n % 10) + '0');
    return (len);
}

int ft_puthex(unsigned long n, char type)
{
    int len = 0;
    char *base = (type == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
    if (n >= 16)
        len += ft_puthex(n / 16, type);
    len += ft_putchar(base[n % 16]);
    return (len);
}

int ft_putptr(unsigned long ptr)
{
    int len = 0;
    if (!ptr)
        return (ft_putstr("(nil)"));
    len += ft_putstr("0x");
    len += ft_puthex(ptr, 'x');
    return (len);
}

int apply_width(int width, int content_len, char pad)
{
    int count = 0;
    int pad_len = width - content_len;
    while (pad_len-- > 0)
    {
        ft_putchar(pad);
        count++;
    }
    return (count);
}

int apply_precision(int precision, int num_len)
{
    int count = 0;
    int pad_len = precision - num_len;
    while (pad_len-- > 0)
    {
        ft_putchar('0');
        count++;
    }
    return (count);
}
