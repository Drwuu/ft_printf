#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	dprintf(1, "PF :: ");
	dprintf(1, "%5c", '\0');
	dprintf(1, "\n");
	dprintf(1, "ME :: ");
	ft_printf("%5c", '\0');
	dprintf(1, "\n");
	return (0);
}
