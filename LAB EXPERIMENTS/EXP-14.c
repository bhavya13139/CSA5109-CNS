#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[100];
    int key[100], n, i;

    printf("Enter plaintext: ");
    scanf("%s", s);

    printf("Enter number of key values: ");
    scanf("%d", &n);

    printf("Enter key values:\n");
    for(i=0;i<n;i++)
        scanf("%d",&key[i]);

    printf("Ciphertext: ");

    for(i=0;s[i]!='\0';i++)
        printf("%c", (s[i]-'A'+key[i])%26+'A');

    return 0;
}
