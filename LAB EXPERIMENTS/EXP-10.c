#include <stdio.h>
#include <ctype.h>
char m[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};
int main()
{
    char s[100], a, b;
    int i, j, r1, c1, r2, c2;
    printf("Enter text (even letters): ");
    scanf("%s", s);
    printf("Ciphertext: ");

    for(i = 0; s[i] != '\0'; i += 2)
    {
        a = toupper(s[i]);
        b = toupper(s[i+1]);

        for(r1=0; r1<5; r1++)
            for(c1=0; c1<5; c1++)
                if(m[r1][c1] == a) goto A;

        A:
        for(r2=0; r2<5; r2++)
            for(c2=0; c2<5; c2++)
                if(m[r2][c2] == b) goto B;

        B:
        if(r1 == r2)
            printf("%c%c", m[r1][(c1+1)%5],
                           m[r2][(c2+1)%5]);
        else if(c1 == c2)
            printf("%c%c", m[(r1+1)%5][c1],
                           m[(r2+1)%5][c2]);
        else
            printf("%c%c", m[r1][c2], m[r2][c1]);
    }

    return 0;
}
