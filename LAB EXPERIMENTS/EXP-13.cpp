#include <stdio.h>

int main()
{
    int p[2][2], c[2][2];
    int a, b, d, det, inv, i, j;
    int k[2][2];

    printf("Enter plaintext matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&p[i][j]);

    printf("Enter ciphertext matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&c[i][j]);

    det = (p[0][0]*p[1][1]-p[0][1]*p[1][0]) % 26;
    if(det < 0) det += 26;

    for(inv=1;inv<26;inv++)
        if((det*inv)%26 == 1) break;

    if(inv == 26)
    {
        printf("Inverse does not exist");
        return 0;
    }

    a = p[1][1]; b = -p[0][1];
    d = -p[1][0];

    k[0][0] = (inv*a*c[0][0] + inv*b*c[1][0]) % 26;
    k[0][1] = (inv*a*c[0][1] + inv*b*c[1][1]) % 26;
    k[1][0] = (inv*d*c[0][0] + inv*p[0][0]*c[1][0]) % 26;
    k[1][1] = (inv*d*c[0][1] + inv*p[0][0]*c[1][1]) % 26;

    printf("Recovered key:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            k[i][j] = (k[i][j] % 26 + 26) % 26;
            printf("%d ",k[i][j]);
        }
        printf("\n");
    }

    return 0;
}
