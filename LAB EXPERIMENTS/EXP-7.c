#include <stdio.h>

int main()
{
    char cipher[200], key[27];
    int i;

    printf("Enter ciphertext: ");
    scanf("%s", cipher);

    printf("Enter cipher alphabet: ");
    scanf("%s", key);

    printf("Plaintext: ");

    for(i = 0; cipher[i]; i++)
    {
        int j;

        for(j = 0; j < 26; j++)
        {
            if(key[j] == cipher[i])
            {
                printf("%c", 'A' + j);
                break;
            }
        }
    }

    return 0;
}
