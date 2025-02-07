#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int len = 0;
    t_flags flags;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            flags = (t_flags){0, -1, 0, 0, 0, 0, 0};
            parse_flags(&format, &args, &flags);
            if (*format == 'c')
                len += handle_char(&args, flags);
            else if (*format == 's')
                len += handle_string(&args, flags);
            else if (*format == 'd' || *format == 'i')
                len += handle_decimal(&args, flags);
            else if (*format == 'u')
                len += handle_unsigned(&args, flags);
            else if (*format == 'x' || *format == 'X')
                len += handle_hex(&args, flags, *format);
            else if (*format == 'p')
                len += handle_pointer(&args, flags);
            else if (*format == '%')
                len += handle_percent(flags);
            else
                len += ft_putchar(*format);
        }
        else
            len += ft_putchar(*format);
        format++;
    }
    va_end(args);
    return (len);
}
