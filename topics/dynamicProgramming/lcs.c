#include <stdio.h>
#include <string.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int lcs(int *X, int *Y, int m, int n)
{
    int L[m+1][n+1], i, j;
    memset(L, 0, (sizeof(int))*(m+1)*(n+1)); // initialize matrix
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            L[i][j] = X[i-1] == Y[j-1] ? L[i-1][j-1] + 1 : max(L[i-1][j], L[i][j-1]);
    return L[m][n];
}

int main()
{
    int m, n;
    char X[1000], Y[1000];
    scanf("%s", X);
    scanf("%s", Y);
    printf("%d\n", lcs(X, Y, strlen(X), strlen(Y)));
    return 0;
}
