#include <stdio.h>

int main()
{
    int i;
    long double a = 1, b = 1;

    for(i = 1; i <= 25; i++)
        a = a * i;

    for(i = 1; i <= 24; i++)
        b = b * i;

    printf("Possible keys = %.0Lf\n", a);
    printf("Unique keys = %.0Lf\n", b);

    return 0;
}
