#include "ft_printf.h"

static void handle_negative_width(t_flags *flags)
{
    if (flags->width < 0)
    {
        flags->minus = 1;
        flags->width = -flags->width;
    }
}

int parse_flags(const char **format, va_list *args, t_flags *flags)
{
    while (**format)
    {
        if (**format == '-')
            flags->minus = 1;
        else if (**format == '0' && flags->width == 0 && flags->minus == 0)
            flags->ovo = 1;
        else if (**format == '#')
            flags->hash = 1;
        else if (**format == '+')
            flags->plus = 1;
        else if (**format == ' ')
            flags->space = 1;
        else if (**format == '.')
        {
            flags->precision = 0;
            (*format)++;
            if (**format == '*')
            {
                flags->precision = va_arg(*args, int);
                if (flags->precision < 0)
                    flags->precision = -1;
            }
            else
            {
                while (**format >= '0' && **format <= '9')
                {
                    flags->precision = flags->precision * 10 + (**format - '0');
                    (*format)++;
                }
                continue;
            }
        }
        else if (**format >= '0' && **format <= '9')
        {
            if (flags->precision != -1)
                flags->precision = flags->precision * 10 + (**format - '0');
            else
                flags->width = flags->width * 10 + (**format - '0');
        }
        else if (**format == '*')
        {
            if (flags->precision != -1)
            {
                flags->precision = va_arg(*args, int);
                if (flags->precision < 0)
                    flags->precision = -1;
            }
            else
            {
                flags->width = va_arg(*args, int);
                handle_negative_width(flags);
            }
        }
        else
            break;
        (*format)++;
    }
    return (0);
}

int handle_char(va_list *args, t_flags flags)
{
    char c = va_arg(*args, int);
    int printed = 0;
    if (!flags.minus)
        printed += apply_width(flags.width, 1, ' ');
    printed += ft_putchar(c);
    if (flags.minus)
        printed += apply_width(flags.width, 1, ' ');
    return (printed);
}

int handle_string(va_list *args, t_flags flags)
{
    char *str = va_arg(*args, char *);
    int len_str;
    int printed = 0;
    if (!str)
        str = "(null)";
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

static int count_digits(long n)
{
    int count = 0;
    if (n == 0)
        return (1);
    while (n)
    {
        count++;
        n /= 10;
    }
    return (count);
}

int handle_decimal(va_list *args, t_flags flags)
{
    int num = va_arg(*args, int);
    int printed = 0;
    int negative = (num < 0);
    long n = num;
    if (n < 0)
        n = -n;
    int len_num = count_digits(n);
    int effective_precision = (flags.precision > len_num) ? flags.precision : len_num;
    int total_len = effective_precision;
    if (negative || flags.plus || flags.space)
        total_len += 1;
    if (!flags.minus)
    {
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
        {
            printed += apply_width(flags.width, total_len, ' ');
        }
    }
    if (!(flags.ovo && flags.precision == -1))
    {
        if (negative)
            printed += ft_putchar('-');
        else if (flags.plus)
            printed += ft_putchar('+');
        else if (flags.space)
            printed += ft_putchar(' ');
    }
    printed += apply_precision(flags.precision, len_num);
    printed += ft_putnbr(n);
    if (flags.minus)
        printed += apply_width(flags.width, total_len, ' ');
    return (printed);
}

static int count_unsigned(unsigned int n)
{
    int count = 0;
    if (n == 0)
        return (1);
    while (n)
    {
        count++;
        n /= 10;
    }
    return (count);
}

int handle_unsigned(va_list *args, t_flags flags)
{
    unsigned int n = va_arg(*args, unsigned int);
    int len_num = count_unsigned(n);
    int prec_padding = (flags.precision > len_num) ? flags.precision - len_num : 0;
    int total_len = len_num + prec_padding;
    int printed = 0;
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

static int count_hex(unsigned int n)
{
    int count = 0;
    if (n == 0)
        return (1);
    while (n)
    {
        count++;
        n /= 16;
    }
    return (count);
}

int handle_hex(va_list *args, t_flags flags, char type)
{
    unsigned int n = va_arg(*args, unsigned int);
    int len_hex = count_hex(n);
    int prec_padding = (flags.precision > len_hex) ? flags.precision - len_hex : 0;
    int prefix_len = (flags.hash && n != 0) ? 2 : 0;
    int total_len = prefix_len + prec_padding + len_hex;
    int printed = 0;
    if (!flags.minus && !flags.ovo)
        printed += apply_width(flags.width, total_len, ' ');
    if (!flags.minus && flags.ovo && flags.precision == -1)
        printed += apply_width(flags.width, total_len, '0');
    if (flags.hash && n != 0)
        printed += ft_putstr((type == 'x') ? "0x" : "0X");
    printed += apply_precision(flags.precision, len_hex);
    printed += ft_puthex(n, type);
    if (flags.minus)
        printed += apply_width(flags.width, total_len, ' ');
    return (printed);
}

int handle_pointer(va_list *args, t_flags flags)
{
    unsigned long ptr = va_arg(*args, unsigned long);
    int printed = 0;
    int hex_count = 0;
    unsigned long tmp = ptr;
    int total_len;
    if (!ptr)
        return (ft_putstr("(nil)"));
    while (tmp)
    {
        hex_count++;
        tmp /= 16;
    }
    total_len = 2 + ((hex_count > 0) ? hex_count : 1);
    if (!flags.minus)
        printed += apply_width(flags.width, total_len, ' ');
    printed += ft_putstr("0x");
    printed += ft_puthex(ptr, 'x');
    if (flags.minus)
        printed += apply_width(flags.width, total_len, ' ');
    return (printed);
}

int handle_percent(t_flags flags)
{
    int printed = 0;
    if (!flags.minus && !flags.ovo)
        printed += apply_width(flags.width, 1, ' ');
    if (!flags.minus && flags.ovo)
        printed += apply_width(flags.width, 1, '0');
    printed += ft_putchar('%');
    if (flags.minus)
        printed += apply_width(flags.width, 1, ' ');
    return (printed);
}
