#include "ft_printf.h"

int typeVar(va_list list, char c)
{
    int printlen;

    printlen = 0;
    if (c == 'c')
        printlen += ft_putchar(va_arg(list, int));
    else if (c == 's')
        printlen += ft_putstr(va_arg(list, char *));
    else if (c == 'p')
        printlen += ft_putptr(va_arg(list, unsigned long long));
    else if (c == 'i' || c == 'd')
        printlen += ft_putnbr(va_arg(list, int));
    else if (c == 'u')
        printlen += ft_putunsnbr(va_arg(list, unsigned int));
    else if (c == 'x')
        printlen += ft_puthexa(va_arg(list,unsigned int));
    else if (c == 'X')
        printlen += ft_puthexaM(va_arg(list,unsigned int));
    else if (c == '%')
    {
        write(1, "%", 1);
        printlen++;
    }
    return(printlen);
}

int ft_printf(const char *str, ...)
{
    va_list list;
    int i;
    int printlen;

    if (!str || str[0] == '\0')
        return 0;
    i = 0;
    printlen = 0;
    va_start(list, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            printlen += typeVar(list, str[i + 1]);
            i++;
        }
        else
        {
            printlen += ft_putchar(str[i]);
        }
        i++;
    }
    va_end(list);
    return(printlen);
}
