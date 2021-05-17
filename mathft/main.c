#include "mathft.h"

// gcc -Wall -Wextra -Werror conversions_1.c main.c support.c -g -I ./ -o test.debug

int		main(void)
{
	t_strdouble test1;
	t_strdouble test2;

	test1.is_negative = false;
	test1.number = "52345678";
	test1.num_len = 8;
	test1.power = 4;
	test1.last_sig_digit = test1.power + 1 - test1.num_len;

	test2.is_negative = false;
	test2.number = "52345678";
	test2.num_len = 8;
	test2.power = 4;
	test2.last_sig_digit = test2.power + 1 - test2.num_len;

	ft_add_sd(&test1, &test2);
	return (0);
}
