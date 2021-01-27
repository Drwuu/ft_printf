#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	//int j = 0;
	
	//dprintf(1, "*** MINE ***\n");
	/* ft_printf("test%cBest%%Go\n", 'T');
	ft_printf("test%cBest%%Go%%Coco\n", 'T');
	ft_printf("test%sbest%%bo\n", "coucou");
	ft_printf("test%dbest%%bo\n", INT_MIN);
	ft_printf("test%ibest%%bo\n", INT_MAX);
	ft_printf("test%ubest%%bo\n", UINT_MAX);
	ft_printf("test%xbest%%bo\n", UINT_MAX);
	ft_printf("test%Xbest%%bo\n", 1250005554); */
	//ft_printf("test%pbest%%bo\n", &j);
	/* ft_printf("%.*s\n", 2, "125");
	ft_printf("%*.15d\n", 12, 125);
	ft_printf("%0.10d\n", 125); */
	//dprintf(1, "\n");
	
	//dprintf(1, "*** REAL ***\n");
	/* dprintf(1, "test%cBest%%Go\n", 'T');
	dprintf(1, "test%cBest%%Go%%Coco\n", 'T');
	dprintf(1, "test%sbest%%bo\n", "coucou");
	dprintf(1, "test%dbest%%bo\n", INT_MIN);
	dprintf(1, "test%ibest%%bo\n", INT_MAX);
	dprintf(1, "test%ubest%%bo\n", UINT_MAX);
	dprintf(1, "test%xbest%%bo\n", UINT_MAX);
	dprintf(1, "test%Xbest%%bo\n", 1250005554); */
	//dprintf(1, "test%pbest%%bo\n", &j);
	/* dprintf(1, "%.*s\n", 2, "125");
	dprintf(1, "%*.15d\n", 5, 125);
	dprintf(1, "%0.10d\n", 125); */
	//dprintf(1, "\n");

	dprintf(1, "*** MINE FLAGS ***\n");
	/* ft_printf("%s\n", "");
	ft_printf("%s\n", "0");
	ft_printf("%s %s\n", "", "");
	ft_printf("%s %s\n", "0", "1");
	ft_printf("%s %s \n", "0", "1");
	ft_printf("%1s %1s \n", "123", "4567");
	ft_printf("%4s %4s \n", "123", "4567");
	ft_printf("%-4s %4s \n", "123", "4567");
	ft_printf("%4s %-4s \n", "123", "4567");
	ft_printf("%-4s %-4s \n", "123", "4567");
	ft_printf("%*s %*s \n", 1, "123", 10, "4567");
	ft_printf("*%s %*s \n", "123", 10, "4567");
	ft_printf("%*s %s \n", 10, "123", "4567");
	ft_printf("%5c\n", 'a');
	ft_printf("%4s %.1s \n", "123", "4567");
	ft_printf("%*.s %.1s \n", 10, "123", "4567");
	ft_printf("%*.0s %.2s \n", 10, "123", "4567");
	ft_printf("%*.3s %.3s \n", 10, "123", "4567");
	ft_printf("%*.4s %.4s \n", 10, "123", "4567");
	ft_printf("%*.5s %.5s \n", 10, "123", "4567"); */
	/* ft_printf("%*.5s %*.5s \n", 10, "123", 10, "4567");
	ft_printf("%*.5s %*.5s \n", -10, "123", 10, "4567");
	ft_printf("%*.5s %*.5s \n", 10, "123", -10, "4567");
	ft_printf("%*.5s %*.5s \n", -10, "123", -10, "4567");
	ft_printf("%10.s %1.s \n", "789", "6789");
	//ft_printf("%0.s %0.s \n", "123", "4567");
	ft_printf("%.s %.s \n", "123", "4567");
	ft_printf("%3.3s %3.3s \n", "123", "4567"); */
	ft_printf("%4.3s %-4.3s \n", "123", "4567");
	ft_printf("%.s\n", "");
	ft_printf("%.0s\n", "");
	ft_printf("%.1s\n", "");
	ft_printf("%4.2s %-4.2s \n", "123", "4567");
	dprintf(1, "\n");

	dprintf(1, "*** TRIPOUILLE ***\n");
	/* dprintf(1, "%s\n", "");
	dprintf(1, "%s\n", "0");
	dprintf(1, "%s %s\n", "", "");
	dprintf(1, "%s %s\n", "0", "1");
	dprintf(1, "%s %s \n", "0", "1");
	dprintf(1, "%1s %1s \n", "123", "4567");
	dprintf(1, "%4s %4s \n", "123", "4567");
	dprintf(1, "%-4s %4s \n", "123", "4567");
	dprintf(1, "%4s %-4s \n", "123", "4567");
	dprintf(1, "%-4s %-4s \n", "123", "4567");
	dprintf(1, "%*s %*s \n", 1, "123", 10, "4567");
	dprintf(1, "*%s %*s \n", "123", 10, "4567");
	dprintf(1, "%*s %s \n", 10, "123", "4567");
	dprintf(1, "%5c\n", 'a');
	dprintf(1, "%4s %.1s \n", "123", "4567");
	dprintf(1, "%*.s %.1s \n", 10, "123", "4567");
	dprintf(1, "%*.0s %.2s \n", 10, "123", "4567");
	dprintf(1, "%*.3s %.3s \n", 10, "123", "4567");
	dprintf(1, "%*.4s %.4s \n", 10, "123", "4567");
	dprintf(1, "%*.5s %.5s \n", 10, "123", "4567"); */
	/* dprintf(1, "%*.5s %*.5s \n", 10, "123", 10, "4567");
	dprintf(1, "%*.5s %*.5s \n", -10, "123", 10, "4567");
	dprintf(1, "%*.5s %*.5s \n", 10, "123", -10, "4567");
	dprintf(1, "%*.5s %*.5s \n", -10, "123", -10, "4567");
	dprintf(1, "%10.s %1.s \n", "789", "6789");
	//dprintf(1, "%0.s %0.s \n", "123", "4567");
	dprintf(1, "%.s %.s \n", "123", "4567");
	dprintf(1, "%3.3s %3.3s \n", "123", "4567"); */
	dprintf(1, "%4.3s %-4.3s \n", "123", "4567");
	dprintf(1, "%.s\n", "");
	dprintf(1, "%.0s\n", "");
	dprintf(1, "%.1s\n", "");
	dprintf(1, "%4.2s %-4.2s \n", "123", "4567");
	dprintf(1, "\n");


	//dprintf(1, "test%pbest%%bo\n", &j);
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
