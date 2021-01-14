#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int j = 25;

	dprintf(1, "*** MINE ***\n");
	ft_printf("test%cbest%%bo\n", 'T');
	ft_printf("test%sbest%%bo\n", "coucou");
	ft_printf("test%dbest%%bo\n", INT_MIN);
	ft_printf("test%ibest%%bo\n", INT_MAX);
	ft_printf("test%ubest%%bo\n", UINT_MAX);
	ft_printf("test%xbest%%bo\n", UINT_MAX);
	ft_printf("test%Xbest%%bo\n", 1250005554);
	ft_printf("test%pbest%%bo\n", &j);
	dprintf(1, "*** REAL ***\n");
	dprintf(1, "test%cbest%%bo\n", 'T');
	dprintf(1, "test%sbest%%bo\n", "coucou");
	dprintf(1, "test%dbest%%bo\n", INT_MIN);
	dprintf(1, "test%ibest%%bo\n", INT_MAX);
	dprintf(1, "test%ubest%%bo\n", UINT_MAX);
	dprintf(1, "test%xbest%%bo\n", UINT_MAX);
	dprintf(1, "test%Xbest%%bo\n", 1250005554);
	dprintf(1, "test%pbest%%bo\n", &j);
	while(1);
	/* printf("*** OWN TESTS ***\n");
	printf("%%10.5d for 12 = ");
	printf("return = %d\n", printf("%10.5d\n", 12));
	printf("%%-*(50)d for 20 = ");
	printf("return = %d\n", printf("%-*d\n", 50, 20));
	printf("%%-.*(20)d for 500 = ");
	printf("return = %d\n", printf("%-.*d\n", 20, 500));
	printf("%%*(50).10d for 20 = ");
	printf("return = %d\n", printf("%*.10d\n", 50, 20));
	printf("%%1.*(50)s for \"20\" = ");
	printf("return = %d\n", printf("%1.*s\n", 50, "20"));
	printf("%%50.*(1)s for \"20\" = ");
	printf("return = %d\n", printf("%50.*s\n", 1, "20"));
	printf("%%050d for 20 = ");
	printf("return = %d\n", printf("%050d\n", 20)); */
	return (0);
}
