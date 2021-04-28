#include "../headers/ft_printf.h"

//mask printer:
/*
printf("alternative_mode = %d\nleft_justified = %d\nzero_padding = %d\nfree_space = %d\nprint_sign = %d\nuppercase = %d\nis_negative = %d\nwidth = %d\nprescision = %d\nspecifier = %c\nis_hh = %d\nis_h = %d\nis_l = %d\nis_ll = %d\nis_L = %d\nis_j = %d\nis_z = %d\n",
	mask->alternative_mode,	mask->left_justified, mask->zero_padding, mask->free_space, mask->print_sign, mask->uppercase, mask->is_negative, mask->width, mask->prescision, mask->specifier, mask->length_modifiers.is_hh, mask->length_modifiers.is_h, mask->length_modifiers.is_l, mask->length_modifiers.is_hh, mask->length_modifiers.is_L, mask->length_modifiers.is_j, mask->length_modifiers.is_z);
*/	

int		main ()
{
	//char	str[] = "%.**f %d\n";
	//printf(str, 5, 7, 10, 11);
	//ft_printf("%+- 0#10.15d", -1);
	ft_printf("Testing %d:\n");
	ft_printf("%d\n", 0);
	ft_printf("%d\n", 1);
	ft_printf("%d\n", -1);
	ft_printf("%+d\n", 0);
	ft_printf("%+d\n", 1012);
	ft_printf("%+d\n", -123);
	ft_printf("% d\n", 0);
	ft_printf("% d\n", 1012);
	ft_printf("% d\n", -123);
	return (0);
}