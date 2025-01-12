#include "ft_printf.h"

int ft_putchar(char c) {
    return write(1, &c, 1);
}

int ft_putstr(char *str) {
    int len = 0;

    if (!str)
        str = "(null)";
    while (*str)
        len += ft_putchar(*str++);
    return len;
}

int ft_putnbr(long n) {
    int len = 0;

    if (n < 0) {
        len += ft_putchar('-');
        n = -n;
    }
    if (n > 9)
        len += ft_putnbr(n / 10);
    len += ft_putchar((n % 10) + '0');
    return len;
}

int ft_putnbr_unsigned(unsigned int n) {
    if (n > 9)
        return ft_putnbr_unsigned(n / 10) + ft_putchar((n % 10) + '0');
    return ft_putchar(n + '0');
}

int ft_puthex(unsigned long n, char format) {
    int len = 0;
    char *base = (format == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";

    if (n >= 16)
        len += ft_puthex(n / 16, format);
    len += ft_putchar(base[n % 16]);
    return len;
}

int ft_putptr(unsigned long ptr) {
    int len = 0;

    if (!ptr)
        return ft_putstr("(nil)");
    len += ft_putstr("0x");
    len += ft_puthex(ptr, 'x');
    return len;
}