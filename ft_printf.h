#ifndef FT_PRINTF
# define FT_PRINTF
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int	ft_printf_pointer(unsigned long long	nbr);
int	ft_printf_hex(va_list	argptr, char	c);
#endif
