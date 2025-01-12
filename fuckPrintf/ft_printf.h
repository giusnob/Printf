#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

// Struttura per i flag
typedef struct s_flags {
    int minus;       // Flag '-'
    int zero;        // Flag '0'
    int width;       // Larghezza minima
    int dot;         // Flag '.'
    int precision;   // Precisione
    int hash;        // Flag '#'
    int space;       // Flag ' '
    int plus;        // Flag '+'
} t_flags;

int ft_printf(const char *format, ...);

// Funzioni di supporto
t_flags init_flags(void);
int parse_flags(const char **format, va_list args, t_flags *flags);

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(long n);               // Usa long per gestire numeri grandi
int ft_putnbr_unsigned(unsigned int n);
int ft_puthex(unsigned long n, char format);
int ft_putptr(unsigned long ptr);

int ft_apply_width(int width, int content_len, char pad, int left_align);
int ft_print_sign(long n, t_flags flags);
int ft_print_int(long n, t_flags flags);
int ft_print_hex(unsigned long n, t_flags flags, char format);
int ft_print_str(char *str, t_flags flags);

#endif