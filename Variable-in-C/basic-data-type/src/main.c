#include "userincl.h"

int main(void)
{
	printf("%ld\n", sizeof(char));	// 1
	printf("%ld\n", sizeof(int));	// 4
	printf("%ld\n", sizeof(float));	// 4
	printf("%ld\n", sizeof(double));	// 8
	printf("%ld\n", sizeof(short int));	// 2
	printf("%ld\n", sizeof(long int));	// 8
	printf("%ld\n", sizeof(long double));	//16
	printf("\n");
	printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);	// 127
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);	// -128
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);	//255
    printf("\n");
    printf("INT_MAX     :   %d\n", INT_MAX);	// 2147483647
    printf("INT_MIN     :   %d\n", INT_MIN);	// -2147483648
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);	// 32767
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);	// -32768
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);	// 4294967295
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);	// 65535
    printf("\n");
    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
	return 0;
}
