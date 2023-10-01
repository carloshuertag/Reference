#include <stdio.h>
#include <string.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int knapsack(int W[], int V[], int w, int n)
{
    register int i, j, in;
    int K[n+1][w+1];
    memset(K, 0, (sizeof(int))*(n+1)*(w+1)); // initialize matrix
    for (i = 1; i <= n; i++)
        for (j = 1; j <= w; j++)
        { // bottom-up approach
            in = (W[i-1] <= j) ? V[i-1] + K[i-1][j-W[i-1]] : 0;
            K[i][j] = max(in,  K[i-1][j]);
        }
    return K[n][w];
}

int main()
{
    int w, n;
    scanf("%d %d", &w, &n);
    int W[n], V[n];
    register int i;
    for(i = 0; i < n; i++)
        scanf("%d %d", &W[i], &V[i]);
    printf("\n%d", knapsack(W, V, w, n));
    return 0;
}