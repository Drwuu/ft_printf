#include <stdio.h>
#include <limits.h>

int main()
{
    printf("*** OWN TESTS ***\n");
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
    printf("return = %d\n", printf("%050d\n", 20));
    return (0);
}
