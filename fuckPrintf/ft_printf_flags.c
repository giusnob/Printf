#include "ft_printf.h"

t_flags init_flags(void) {
    t_flags flags;

    flags.minus = 0;
    flags.zero = 0;
    flags.width = 0;
    flags.dot = 0;
    flags.precision = -1;
    flags.hash = 0;
    flags.space = 0;
    flags.plus = 0;
    return flags;
}

int parse_flags(const char **format, va_list args, t_flags *flags) {
    while (**format) {
        if (**format == '-')
            flags->minus = 1;
        else if (**format == '0' && flags->dot == 0)
            flags->zero = 1;
        else if (**format == '.')
            flags->dot = 1, flags->precision = 0;
        else if (**format >= '0' && **format <= '9') {
            if (flags->dot)
                flags->precision = flags->precision * 10 + (**format - '0');
            else
                flags->width = flags->width * 10 + (**format - '0');
        } else if (*format == '') {
            int value = va_arg(args, int);
            if (flags->dot)
                flags->precision = value;
            else
                flags->width = value;
        } else
            break;
        (*format)++;
    }
    return 0;
}