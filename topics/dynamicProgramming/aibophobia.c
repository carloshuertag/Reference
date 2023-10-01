#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    register int i, j;
    memset(L, 0, (sizeof(int)) * (m + 1) * (n + 1)); // initialize matrix
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            L[i][j] = (X[i - 1] == Y[j - 1]) ? L[i - 1][j - 1] + 1 : max(L[i - 1][j], L[i][j - 1]);
    return L[m][n];
}

void reverseString(char *str, int n)
{
    register int i;
    register char tmp;
    for (i = 0; i < n / 2; i++)
    { // swap
        tmp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = tmp;
    }
}

int aibophobia(char *str, int n)
{
    char reversedStr[n];
    strcpy(reversedStr, str);
    reverseString(reversedStr, n);
    return n - lcs(str, reversedStr, n, n);
}

int main()
{
    int testCases, n ,i;
    scanf("%d", &testCases);
    char strs[testCases][6100];
    int result[testCases];
    i = testCases;
    while (i--)
    {
        scanf("%s", strs[0]);
        n = strlen(strs[0]);
        result[i] = aibophobia(strs[0], n);
    }
    i = testCases;
    while (i--)
        printf("%d\n", result[i]);
    return 0;
}