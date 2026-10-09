#include <stdio.h>
#include <string.h>

int main()
{
    char s[100], temp[100];
    int i, k;

    printf("Enter ciphertext: ");
    scanf("%s", s);

    for(k=0;k<26;k++)
    {
        for(i=0;s[i]!='\0';i++)
            temp[i] = (s[i]-'A'-k+26)%26+'A';

        temp[i] = '\0';

        printf("Shift %d: %s\n",k,temp);
    }

    return 0;
}
