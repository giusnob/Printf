#include "ft_printf.h"

int ft_printf(const char *format, ...) {
    va_list args;
    t_flags flags;
    int printed_chars = 0;

    va_start(args, format);
    while (*format) {
        if (*format == '%' && *(format + 1)) {
            format++;
            flags = init_flags();
            parse_flags(&format, args, &flags);
            if (*format == 'd' || *format == 'i')
                printed_chars += ft_print_int(va_arg(args, int), flags);
            else if (*format == 'u')
                printed_chars += ft_putnbr_unsigned(va_arg(args, unsigned int));
            else if (*format == 'x' || *format == 'X')
                printed_chars += ft_print_hex(va_arg(args, unsigned int), flags, *format);
            else if (*format == 'p')
                printed_chars += ft_putptr(va_arg(args, unsigned long));
            else if (*format == 's')
                printed_chars += ft_print_str(va_arg(args, char *), flags);
            else if (*format == 'c')
                printed_chars += ft_putchar(va_arg(args, int));
            else if (*format == '%')
                printed_chars += ft_putchar('%');
        } else {
            printed_chars += ft_putchar(*format);
        }
        format++;
    }
    va_end(args);
    return printed_chars;
}