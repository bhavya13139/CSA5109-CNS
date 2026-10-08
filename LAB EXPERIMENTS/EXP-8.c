#include <stdio.h>

int main()
{
    char key[50], cipher[27], text[100];
    int used[26] = {0};
    int i, j = 0;

    printf("Enter keyword: ");
    scanf("%s", key);

    for(i = 0; key[i]; i++)
    {
        char ch = key[i];

        if(!used[ch-'A'])
        {
            cipher[j++] = ch;
            used[ch-'A'] = 1;
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(!used[i])
            cipher[j++] = 'A' + i;
    }

    cipher[26] = '\0';

    printf("Cipher alphabet: %s\n", cipher);

    printf("Enter text: ");
    scanf("%s", text);

    for(i = 0; text[i]; i++)
        text[i] = cipher[text[i]-'A'];

    printf("Ciphertext: %s", text);

    return 0;
}
