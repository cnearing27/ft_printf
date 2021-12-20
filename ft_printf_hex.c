#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long long	nb, char	*base)
{
	char		p;
	static int	count;

	count = 0;
	if (nb >= 16)
		ft_putnbr_hex(nb / 16, base);
	p = base[(nb % 16)];
	write(1, &p, 1);
	count++;
	return (count);
}

int	ft_printf_hex(va_list	argptr, char	c)
{
	unsigned int	x;

	x = va_arg(argptr, unsigned int);
	if (c == 'X')
		return (ft_putnbr_hex(x, "0123456789ABCDEF"));
	else
		return (ft_putnbr_hex(x, "0123456789abcdef"));
}
