#include <stdio.h>

int main()
{
    char cipher[200];
    int i, a = 9, b = 21;
    int inv = 3;

    printf("Enter ciphertext: ");
    scanf("%s", cipher);

    printf("Plaintext: ");

    for(i = 0; cipher[i]; i++)
    {
        int c = cipher[i] - 'A';
        int p = inv * (c - b);

        p = (p % 26 + 26) % 26;

        printf("%c", p + 'A');
    }

    return 0;
}
