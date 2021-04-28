#include "../headers/ft_printf.h"

//mask printer:
/*
printf("alternative_mode = %d\nleft_justified = %d\nzero_padding = %d\nfree_space = %d\nprint_sign = %d\nuppercase = %d\nis_negative = %d\nwidth = %d\nprescision = %d\nspecifier = %c\nis_hh = %d\nis_h = %d\nis_l = %d\nis_ll = %d\nis_L = %d\nis_j = %d\nis_z = %d\n",
	mask->alternative_mode,	mask->left_justified, mask->zero_padding, mask->free_space, mask->print_sign, mask->uppercase, mask->is_negative, mask->width, mask->prescision, mask->specifier, mask->length_modifiers.is_hh, mask->length_modifiers.is_h, mask->length_modifiers.is_l, mask->length_modifiers.is_hh, mask->length_modifiers.is_L, mask->length_modifiers.is_j, mask->length_modifiers.is_z);
*/	

int		main ()
{
	//printf(str, 5, 7, 10, 11);
	//ft_printf("%+- 0#10.15d", -1);
	signed char		hhd = -1;
	short int		hd = -1;
	long int		ld = -1;
	long long int	lld = -1;
	intmax_t		jd = -1;
	ssize_t			zd = -1;

	ft_printf("Testing %%d\n");
	ft_printf("Expected:0 :%d\n", 0);
	ft_printf("Expected:1 :%d\n", 1);
	ft_printf("Expected:-1 :%d\n", -1);
	
	ft_printf("Expected:+0 :%+d\n", 0);
	ft_printf("Expected:+1012 :%+d\n", 1012);
	ft_printf("Expected:-123 :%+d\n", -123);

	ft_printf("Expected: 0 :% d\n", 0);
	ft_printf("Expected: 1012 :% d\n", 1012);
	ft_printf("Expected:-123 :% d\n", -123);

	ft_printf("Expected: '  123' :'%5d'\n", 123);
	ft_printf("Expected: '123456789' :'%5d'\n", 123456789);

	ft_printf("Expected: '123  ' :'%-5d'\n", 123);
	ft_printf("Expected: '123456789' :'%-5d'\n", 123456789);

	ft_printf("Expected: '00123' :'%05d'\n", 123);
	ft_printf("Expected: '123456789' :'%05d'\n", 123456789);

	ft_printf("Expected: '123  ' :'%-05d'\n", 123);
	ft_printf("Expected: '123456789' :'%-05d'\n", 123456789);

	ft_printf("Expected: '+123 ' :'%+-05d'\n", 123);
	ft_printf("Expected: '+123456789' :'%+-05d'\n", 123456789);

	ft_printf("Expected:-1 :%hhd\n", hhd);
	ft_printf("Expected:-1 :%hd\n", hd);
	ft_printf("Expected:-1 :%ld\n", ld);
	ft_printf("Expected:-1 :%lld\n", lld);
	ft_printf("Expected:-1 :%jd\n", jd);
	ft_printf("Expected:-1 :%zd\n", zd);

	return (0);
}
