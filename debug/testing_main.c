#include <stdio.h>

int		main(void)
{
	int		test;
	char	*teststr;

	teststr = "%p\n";
	printf(teststr, &test);
	teststr = "%20p\n";
	printf(teststr, &test);
	teststr = "%020p\n";
	printf(teststr, &test);
	teststr = "%#p\n";
	printf(teststr, &test);
	teststr = "%#020p\n";
	printf(teststr, &test);
	teststr = "%+p\n";
	printf(teststr, &test);

	printf("%f\n", 123456789.123456789);
	printf("%e\n", 123456789.123456789);
	printf("%g\n\n", 123456789.123456789);

	printf("%25f\n", 123456789.123456789);
	printf("%25e\n", 123456789.123456789);
	printf("%25g\n\n", 123456789.123456789);

	printf("%25.4f\n", 123456789.123456789);
	printf("%25.4e\n", 123456789.123456789);
	printf("%25.4g\n\n", 123456789.123456789);

	printf("%25.20f\n", 123456789.123456789);
	printf("%25.20e\n", 123456789.123456789);
	printf("%25.20g\n\n", 123456789.123456789);
	
	printf("%30.2f\n", 100000000000000000000.1234);
	printf("%30.2e\n", 100000000000000000000.1234);
	printf("%30.2g\n\n", 100000000000000000000.1234);

	printf("%110.2f\n", 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.1234);
	printf("%110.2e\n", 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.1234);
	printf("%110.2g\n\n", 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.1234);
	
	printf("%110f\n", 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.1234);
	printf("%110e\n", 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.1234);
	printf("%110g\n\n", 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.1234);

	printf("%f\n", 1234567.123456789);
	printf("%e\n", 1234567.123456789);
	printf("%g\n\n", 1234567.123456789);

	printf("%f\n", 12345.123456789);
	printf("%e\n", 12345.123456789);
	printf("%g\n\n", 12345.123456789);

	printf("%f\n", 1234.123456789);
	printf("%e\n", 1234.123456789);
	printf("%g\n\n", 1234.123456789);

	printf("%f\n", 123.123456789);
	printf("%e\n", 123.123456789);
	printf("%g\n\n", 123.123456789);

	printf("%f\n", 12.123456789);
	printf("%e\n", 12.123456789);
	printf("%g\n\n", 12.123456789);

	printf("%f\n", 1.123456789);
	printf("%e\n", 1.123456789);
	printf("%g\n\n", 1.123456789);

	printf("%f\n", 0.123456789);
	printf("%e\n", 0.123456789);
	printf("%g\n\n", 0.123456789);

	printf("%f\n", 0.0123456789);
	printf("%e\n", 0.0123456789);
	printf("%g\n\n", 0.0123456789);

	printf("%f\n", 0.00123456789);
	printf("%e\n", 0.00123456789);
	printf("%g\n\n", 0.00123456789);

	printf("%f\n", 0.000123456789);
	printf("%e\n", 0.000123456789);
	printf("%g\n\n", 0.000123456789);

	printf("%f\n", 0.0000123456789);
	printf("%e\n", 0.0000123456789);
	printf("%g\n\n", 0.0000123456789);
	
	printf("%f\n", 0.00000123456789);
	printf("%e\n", 0.00000123456789);
	printf("%g\n\n", 0.00000123456789);

	printf("%.4f\n", 0.000123456789);
	printf("%.4e\n", 0.000123456789);
	printf("%.4g\n\n", 0.000123456789);

	printf("%.2f\n", 0.00000123456789);
	printf("%.2e\n", 0.00000123456789);
	printf("%.2g\n\n", 0.00000123456789);
	return (0);
}