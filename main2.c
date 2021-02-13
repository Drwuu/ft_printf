#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	/* int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678; */
	/* char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0"; */

	/* dprintf(1, "PF :: ");
	dprintf(1, " ret = %d ", dprintf(1, "%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	dprintf(1, "\n");
	dprintf(1, "ME :: ");
	dprintf(1, " ret = %d ", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	dprintf(1, "\n"); */
	dprintf(1, "ME :: ");
	dprintf(1, " ret = %d ", ft_printf("%0*.*d", 4, -2, -12));
	dprintf(1, "\n");
	dprintf(1, "PF :: ");
	dprintf(1, " ret = %d ", dprintf(1, "%0*.*d", 4, -2, -12));
	dprintf(1, "\n");
	dprintf(1, "ME :: ");
	dprintf(1, " ret = %d ", ft_printf("%00d", -12));
	dprintf(1, "\n");
	dprintf(1, "PF :: ");
	dprintf(1, " ret = %d ", dprintf(1, "%00d", -12));
	dprintf(1, "\n");
	//while(1);
	
	/* dprintf(1, "MAZOISE TESTS :: ");
	dprintf(1, "\n"); */
	/* while (a < 5) //T34-69
	{
		dprintf(1, "** A = %d **\n", a);
		dprintf(1, "ME :: ");
		ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		dprintf(1, "\n");
		dprintf(1, "PF :: ");
		dprintf(1, "%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		dprintf(1, "\n");
		dprintf(1, "ME :: ");
		ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		dprintf(1, "\n");
		dprintf(1, "PF :: ");
		dprintf(1, "%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		dprintf(1, "\n");
		dprintf(1, "ME :: ");
		ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		dprintf(1, "\n");
		dprintf(1, "PF :: ");
		dprintf(1, "%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		dprintf(1, "\n");
		dprintf(1, "ME :: ");
		ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		dprintf(1, "\n");
		dprintf(1, "PF :: ");
		dprintf(1, "%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		dprintf(1, "\n");
		a++;
	} */
	/* a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			dprintf(1, "** a = %d **\n", a);
			dprintf(1, "** b = %d **\n", b);
			dprintf(1, "ME :: ");
			ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			dprintf(1, "\n");
			dprintf(1, "PF :: ");
			dprintf(1, "%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			dprintf(1, "\n");
			dprintf(1, "ME :: ");
			ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			dprintf(1, "\n");
			dprintf(1, "PF :: ");
			dprintf(1, "%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			dprintf(1, "\n");
			dprintf(1, "ME :: ");
			ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			dprintf(1, "\n");
			dprintf(1, "PF :: ");
			dprintf(1, "%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			dprintf(1, "\n");
			b++;
		}
		a++;
	} */
	return (0);
}
