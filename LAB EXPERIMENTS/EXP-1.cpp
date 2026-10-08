#include <stdio.h>

int main()
{
    char text[100];
    int key, i;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; text[i] != '\0'; i++)
        text[i] = (text[i] - 'A' + key) % 26 + 'A';

    printf("Ciphertext: %s", text);

    return 0;
}
