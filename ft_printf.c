#include "ft_printf.h"

void	ft_printf_char(char	a)
{
	write(1, &a, 1);
}

int	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_strlen(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_putnbr(int	nb)
{
	char		p;
	static int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		count += 2;
		nb = 147483648;
		ft_putnbr(nb);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		count++;
		nb *= (-1);
		ft_putnbr(nb);
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		p = (nb % 10) + '0';
		write(1, &p, 1);
		count++;
	}
	return (count);
}

int	ft_putnbr_U(unsigned int	nb)
{
	char		p;
	static int	count;

	count = 0;
	if (nb >= 10)
		ft_putnbr_U(nb / 10);
	p = (nb % 10) + '0';
	write(1, &p, 1);
	count++;
	return (count);
}

int	ft_printf_integer(va_list	argptr)
{
	int	n;

	n = va_arg(argptr, int);
	return (ft_putnbr(n));
}

int	ft_printf_U_int(va_list	argptr)
{
	unsigned int	n;

	n = va_arg(argptr, unsigned int);
	return (ft_putnbr_U(n));
}

int	check_flag(const char	*format, int	i, va_list	argptr)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
	{
		ft_printf_char(va_arg(argptr, int));
		count++;
	}
	if (format[i] == 's')
		count += ft_putstr(va_arg(argptr, char *));
	if (format[i] == 'p')
		count += ft_printf_pointer(va_arg(argptr, unsigned long long));
	if (format[i] == 'd' || format[i] == 'i')
		count += ft_printf_integer(argptr);
	if (format[i] == 'u')
		count += ft_printf_U_int(argptr);
	if (format[i] == 'x' || format[i] == 'X')
		count += ft_printf_hex(argptr, format[i]);
	if (format[i] == '%')
	{
		write(1, &format[i], 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	argptr;
	int		count;


	i = 0;
	count = 0;
	va_start (argptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += check_flag(format, i + 1, argptr);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end (argptr);
	return (count);
}

#include <stdio.h>
int	main(void)
{
	char a;
	char *b = &a;

	a = '8';
	char d= 'a', e = 'b', f = 'c';
	ft_printf("%c%c%c\n", d, e, f);
	int	k = ft_printf("test s = %s\n", "ag\0hahg");
	int j = printf("correct = %s\n", "ag\0hahg");
	k += ft_printf("test c = %c\n", a);
	j += printf("correct = %c\n", a);
	k += ft_printf("test p = %p\n", b);
	j += printf("correct =%p\n", b);
	k += ft_printf("test d = %d\n", 15);
	j += printf("correct = %d\n", 15);
	k += ft_printf("test i = %i\n", 8964);
	j += printf("correct = %i\n", 8964);
	k += ft_printf("test u = %u\n", 2999999999);
	j += printf("correct = %llu\n", 2999999999);
	k += ft_printf("test x = %x\n", 1564889);
	j += printf("correct = %x\n", 1564889);
	k += ft_printf("test X = %X\n", 1564889);
	j += printf("correct = %X\n", 1564889);
	k += ft_printf("test PERCENT = %%\n");
	j += printf("correct = %%\n");
	printf("MY returned = %d\n", k);
	printf("ORIGINAL returned = %d", j);
}
