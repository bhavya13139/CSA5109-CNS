#include <stdio.h>

int main()
{
    char text[100];
    int a, b, i;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    for(i = 0; text[i]; i++)
        text[i] = (a * (text[i]-'A') + b) % 26 + 'A';

    printf("Ciphertext: %s", text);

    return 0;
}
