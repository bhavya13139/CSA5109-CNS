#include <stdio.h>
#include <ctype.h>

char a[5][5];

void matrix(char key[])
{
    int used[26] = {0};
    int r = 0, c = 0, i;
    char ch;

    for(i = 0; key[i]; i++)
    {
        ch = toupper(key[i]);

        if(ch == 'J')
            ch = 'I';

        if(ch >= 'A' && ch <= 'Z' && !used[ch-'A'])
        {
            a[r][c++] = ch;
            used[ch-'A'] = 1;

            if(c == 5)
            {
                c = 0;
                r++;
            }
        }
    }

    for(ch = 'A'; ch <= 'Z'; ch++)
    {
        if(ch == 'J')
            continue;

        if(!used[ch-'A'])
        {
            a[r][c++] = ch;
            used[ch-'A'] = 1;

            if(c == 5)
            {
                c = 0;
                r++;
            }
        }
    }
}

void find(char ch, int *r, int *c)
{
    int i, j;

    if(ch == 'J')
        ch = 'I';

    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            if(a[i][j] == ch)
            {
                *r = i;
                *c = j;
            }
}

int main()
{
    char key[50], text[100];
    int i, r1, c1, r2, c2;

    printf("Enter key: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", text);

    matrix(key);

    printf("Ciphertext: ");

    for(i = 0; text[i]; i += 2)
    {
        char x = toupper(text[i]);
        char y = toupper(text[i+1]);

        find(x, &r1, &c1);
        find(y, &r2, &c2);

        if(r1 == r2)
            printf("%c%c", a[r1][(c1+1)%5],
                           a[r2][(c2+1)%5]);

        else if(c1 == c2)
            printf("%c%c", a[(r1+1)%5][c1],
                           a[(r2+1)%5][c2]);

        else
            printf("%c%c", a[r1][c2], a[r2][c1]);
    }

    return 0;
}
