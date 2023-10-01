#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int compare(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

int lcs(int *X, int *Y, int m, int n)
{
    int L[m+1][n+1];
    register int i, j;
    memset(L, 0, (sizeof(int))*(m+1)*(n+1)); // initialize matrix
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            L[i][j] = (X[i-1] == Y[j-1]) ? L[i-1][j-1] + 1 : max(L[i-1][j], L[i][j-1]);
    return L[m][n];
}

int lis(int *arr, int n)
{
    int sortedArr[n], aux[n], i, j = 0, found = 0;
    memcpy(sortedArr, arr, sizeof(int)*n);
    qsort(sortedArr, n, sizeof(int), compare);
    aux[j] = sortedArr[0];
    for (i = 0; i < n; i++)
    { // remove duplicates from sorted array
        if(aux[j] == sortedArr[i] && !found) found = 1;
        else if(aux[j] != sortedArr[i])
        {
            aux[++j] = sortedArr[i];
            found = 0;
        }
    }
    return lcs(arr, aux, n, ++j);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; scanf("%d", &arr[i++]));
    printf("%d\n", lis(arr, n));
    return 0;
}
