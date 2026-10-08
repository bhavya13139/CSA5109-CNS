#include <stdio.h>

int main()
{
    char text[100];
    char cipher[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter text: ");
    scanf("%s", text);

    for(i = 0; text[i] != '\0'; i++)
        text[i] = cipher[text[i] - 'A'];

    printf("Ciphertext: %s", text);

    return 0;
}
