#include <stdio.h>
#include <ctype.h>

char mat[5][5];

void create()
{
    char key[] = "ROYALNEWZEALANDNAVY";
    int used[26] = {0};
    int r = 0, c = 0, i;
    char ch;

    for(i = 0; key[i]; i++)
    {
        ch = key[i];

        if(ch == 'J')
            ch = 'I';

        if(!used[ch-'A'])
        {
            mat[r][c++] = ch;
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
            mat[r][c++] = ch;
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
            if(mat[i][j] == ch)
            {
                *r = i;
                *c = j;
            }
}

int main()
{
    char cipher[] =
    "KXJEYUREBEZWEHEWRYTUHEYFS"
    "KREHEGOYFIWTTTUOLKSYCAJPO"
    "BOTEIZONTXBYBNTGONEYCUZWR"
    "GDSONSXBOUYWRHEBAAHYUSEDQ";

    int i, r1, c1, r2, c2;

    create();

    printf("Plaintext: ");

    for(i = 0; cipher[i]; i += 2)
    {
        char x = cipher[i];
        char y = cipher[i+1];

        find(x, &r1, &c1);
        find(y, &r2, &c2);

        if(r1 == r2)
        {
            printf("%c%c",
                   mat[r1][(c1+4)%5],
                   mat[r2][(c2+4)%5]);
        }
        else if(c1 == c2)
        {
            printf("%c%c",
                   mat[(r1+4)%5][c1],
                   mat[(r2+4)%5][c2]);
        }
        else
        {
            printf("%c%c",
                   mat[r1][c2],
                   mat[r2][c1]);
        }
    }

    return 0;
}
