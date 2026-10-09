#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int a, b, i, x, y;

    printf("Enter even-length text: ");
    scanf("%s", s);

    printf("Ciphertext: ");

    for(i = 0; s[i] != '\0'; i += 2)
    {
        a = s[i] - 'A';
        b = s[i+1] - 'A';

        x = (9*a + 4*b) % 26;
        y = (5*a + 7*b) % 26;

        printf("%c%c", x+'A', y+'A');
    }

    return 0;
}
