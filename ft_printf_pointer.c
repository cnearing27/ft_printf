#include "ft_printf.h"

void	ft_putpointer(unsigned long long	nb, char	*base, char	*p, int	count)
{
	if (nb > 0)
	{
		count++;
		ft_putpointer(nb / 16, base, p, count);
	}
	p[15 - count + 1] = base[(nb % 16)];
	count--;
}

int	ft_printf_pointer(unsigned long long	nbr)
{
	char		*base;
	char		*p;
	int			i;
	static int	count;

	base = "0123456789abcdef";
	count = 0;
	i = 0;
	p = malloc(sizeof(char) * 16);
	while (i < 16)
	{
		p[i] = '0';
		i++;
	}
	ft_putpointer(nbr, base, p, count);
	i = 0;
	while (i < 16)
	{
		write(1, &p[i], 1);
		i++;
	}
	return (16);
}
