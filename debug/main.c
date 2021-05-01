#include "../headers/ft_printf.h"
#include <stdio.h>
#include <limits.h>

//mask printer:
/*
printf("alternative_mode = %d\nleft_justified = %d\nzero_padding = %d\nfree_space = %d\nprint_sign = %d\nuppercase = %d\nis_negative = %d\nwidth = %d\nprescision = %d\nspecifier = %c\nis_hh = %d\nis_h = %d\nis_l = %d\nis_ll = %d\nis_L = %d\nis_j = %d\nis_z = %d\n",
	mask->alternative_mode,	mask->left_justified, mask->zero_padding, mask->free_space, mask->print_sign, mask->uppercase, mask->is_negative, mask->width, mask->prescision, mask->specifier, mask->length_modifiers.is_hh, mask->length_modifiers.is_h, mask->length_modifiers.is_l, mask->length_modifiers.is_hh, mask->length_modifiers.is_L, mask->length_modifiers.is_j, mask->length_modifiers.is_z);
*/	

int		main ()
{
	//printf(str, 5, 7, 10, 11);
	//ft_printf("%p\n", &test);
	//printf("%p", &test);

	ft_printf("Testing %%d\n");
	ft_printf("Expected:0 :%d\n", 0);
	ft_printf("Expected:1 :%d\n", 1);
	ft_printf("Expected:-1 :%d\n", -1);

	ft_printf("Expected: '0' :'%.1d'\n", 0);
	ft_printf("Expected: '' :'%.0d'\n", 0);
	
	ft_printf("Expected:+0 :%+d\n", 0);
	ft_printf("Expected:+1012 :%+d\n", 1012);
	ft_printf("Expected:-123 :%+d\n", -123);

	ft_printf("Expected: 0 :% d\n", 0);
	ft_printf("Expected: 1012 :% d\n", 1012);
	ft_printf("Expected:-123 :% d\n", -123);

	ft_printf("Expected: '  123' :'%5d'\n", 123);
	ft_printf("Expected: ' -123' :'%5d'\n", -123);
	ft_printf("Expected: '123456789' :'%5d'\n", 123456789);

	ft_printf("Expected: '123  ' :'%-5d'\n", 123);
	ft_printf("Expected: '-123 ' :'%-5d'\n", -123);
	ft_printf("Expected: '123456789' :'%-5d'\n", 123456789);

	ft_printf("Expected: '00123' :'%05d'\n", 123);
	ft_printf("Expected: '-0123' :'%05d'\n", -123);
	ft_printf("Expected: '123456789' :'%05d'\n", 123456789);

	ft_printf("Expected: '123  ' :'%-05d'\n", 123);
	ft_printf("Expected: '-123 ' :'%-05d'\n", -123);
	ft_printf("Expected: '123456789' :'%-05d'\n", 123456789);

	ft_printf("Expected: '+123 ' :'%+-05d'\n", 123);
	ft_printf("Expected: '-123 ' :'%+-05d'\n", -123);
	ft_printf("Expected: '+123456789' :'%+-05d'\n", 123456789);

	ft_printf("Expected: ' 123 ' :'%- 05d'\n", 123);
	ft_printf("Expected: '-123 ' :'%- 05d'\n", -123);
	ft_printf("Expected: ' 123456789' :'%- 05d'\n", 123456789);

	ft_printf("Expected: ' 0123' :'% 05d'\n", 123);
	ft_printf("Expected: '-0123' :'% 05d'\n", -123);
	ft_printf("Expected: ' 123456789' :'% 05d'\n", 123456789);

	// this case will be fixed when the circle buffer will be introduced
	//ft_printf("%.15000f\n", 1000000000000000.12);
	ft_printf("%g\n", 1234567890.1);
	printf("%g\n", 1234567890.1);

/*
	int	a;
	int b;
	b = ft_printf("Haha I printed some words%n then printed some more!\n", &a);
	printf("%d %d", a, b);

	printf("\n\n%d", __LDBL_MIN_10_EXP__);
*/
/*
	signed char		hhd = -1;
	short int		hd = -1;
	long int		ld = -1;
	long long int	lld = -1;
	intmax_t		jd = -1;
	ssize_t			zd = -1;

	ft_printf("Expected:-1 :%hhd\n", hhd);
	ft_printf("Expected:-1 :%hd\n", hd);
	ft_printf("Expected:-1 :%ld\n", ld);
	ft_printf("Expected:-1 :%lld\n", lld);
	ft_printf("Expected:-1 :%jd\n", jd);
	ft_printf("Expected:-1 :%zd\n", zd);
*/
	return (0);
}
