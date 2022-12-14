#include "ft_printf.h"

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if (!str)
    {
        ft_putstr("(null)");
        return (6);
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

void ft_printnbr(int d)
{
    if (d == 0)
		ft_putchar('0');
	if (d == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (d < 0)
		{
			ft_putchar('-');
			d = -d;
		}
		if (d <= 9 && d > 0)
			ft_putchar(d + 48);
		else if (d >= 9)
		{
			ft_printnbr(d / 10);
			ft_putchar((d % 10) + '0');
		}
	}
}

int ft_putnbr(int d)
{
    int nb;
    int i;

    i = 0;
    nb = d;
    if (d < 0)
        i++;
    if (d == 0)
    {
        write(1, "0", 1);
        i++;
    }
    else
    {
        while (nb != 0)
        {
            nb = nb / 10;
            i++;
        }
        ft_printnbr(d);
    }
    return (i);
}

void ft_printunsnbr(unsigned int d)
{
    if (d == 0)
		ft_putchar('0');
	if (d <= 9 && d > 0)
		ft_putchar(d + 48);
	else if (d >= 9)
	{
		ft_printunsnbr(d / 10);
		ft_putchar((d % 10) + '0');
	}
}

int ft_putunsnbr(unsigned int d)
{
    unsigned int nb;
    int i;

    i = 0;
    nb = d;
    if (d == 0)
    {
        write(1, "0", 1);
        i++;
    }
    else
    {
        while (nb != 0)
        {
            nb = nb / 10;
            i++;
        }
        ft_printunsnbr(d);
    }
    return (i);
}

void ft_printhexa(unsigned int d)
{
    if (d == 0)
		ft_putchar('0');
	else
	{
        if (d >= 10 && d <= 15)
        {
            ft_putchar(d + 87);
        }
		else if (d <= 9 && d > 0)
			ft_putchar(d + 48);
		else if (d >= 16)
		{
			ft_printhexa(d / 16);
			if (d % 16 >= 10 && d % 16 <= 15)
			    ft_putchar((d % 16) + 87);
            else
			    ft_putchar((d % 16) + '0');
		}
	}
}

int ft_puthexa(unsigned int d)
{
    unsigned int nb;
    int i;

    i = 0;
    nb = d;
    if (d == 0)
    {
        write(1, "0", 1);
        i++;
    }
    else
    {
        while (nb != 0)
        {
            nb = nb / 16;
            i++;
        }
        ft_printhexa(d);
    }
    return (i);
}

void ft_printhexaM(unsigned int d)
{
    if (d == 0)
		ft_putchar('0');
	else
	{
        if (d >= 10 && d <= 15)
            ft_putchar(d + 55);
		else if (d <= 9 && d > 0)
			ft_putchar(d + 48);
		else if (d >= 16)
		{
			ft_printhexaM(d / 16);
			if (d % 16 >= 10 && d % 16 <= 15)
			    ft_putchar((d % 16) + 55);
            else
			    ft_putchar((d % 16) + '0');
		}
	}
}

int ft_puthexaM(unsigned int d)
{
    unsigned int nb;
    int i;

    i = 0;
    nb = d;
    if (d == 0)
    {
        write(1, "0", 1);
        i++;
    }
    else
    {
        while (nb != 0)
        {
            nb = nb / 16;
            i++;
        }
        ft_printhexaM(d);
    }
    return (i);
}

void ft_printptr(unsigned long long d)
{

    if (d >= 16)
    {
        ft_printptr(d / 16);
        ft_printptr(d % 16);
    }
    else
    {
        if (d >= 10 && d <= 15)
            ft_putchar(d + 87);
        else
            ft_putchar(d + 48);
    }
}

int ft_putptr(unsigned long long d)
{
    unsigned long long nb;
    int i;

    i = 2;
    nb = d;
    if (d == 0)
    {
        write(1, "(nil)", 5);
        i = 5;
    }
    else
    {
        write(1, "0x", 2);
        while (nb != 0)
        {
            nb = nb / 16;
            i++;
        }
        ft_printptr(d);
    }
    return (i);
}