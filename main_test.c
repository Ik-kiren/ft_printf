#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main ()
{
    printf("t1(%i)", ft_printf(" %x ", 450));
    printf("%c", '\n');
    printf("t2(%i)", printf(" %x ", 450));
    printf("%c", '\n');
    printf("t1(%i)", ft_printf(" %c", '0' - 256));
    printf("%c", '\n');
    printf("t2(%i)", printf(" %c", '0' - 256));
    printf("%c", '\n');
    printf("t1(%i)", ft_printf(" %p ", -1));
    printf("%c", '\n');
    printf("t2(%i)", printf(" %p ", -1));
    printf("%c", '\n');
}