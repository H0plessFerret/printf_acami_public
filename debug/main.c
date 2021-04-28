#include "../headers/ft_printf.h"

int		main ()
{
	char	str[] = "%.**f %d\n";
	printf(str, 5, 7, 10, 11);
	//ft_printf("%0.0.0.0.0.0.d", 5);
	//ft_printf("%+- 0#10.15lld", -1);
	return (0);
}