#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	dprintf(1, "PF :: ");
	dprintf(1, "%.*d", -1, 0);
	dprintf(1, "\n");
	dprintf(1, "ME :: ");
	ft_printf("%.*d", -1, 0);
	dprintf(1, "\n");
	//while(1);
	return (0);
}
