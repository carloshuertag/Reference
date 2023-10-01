#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int n = 8;

int knapsack(int W[], int V[], int w, int i)
{
    int current, next = 0;
    if (w <= 0 || i >= n)
        return 0;
    if (w >= W[i])
        next = V[i] + knapsack(W, V, w - W[i], i + 1);
    current = knapsack(W, V, w, i + 1);
    return max(current, next);
}

int main()
{
    int w, n;
    scanf("%d %d", &w, &n);
    int W[n], V[n];
    register int i;
    for (i = 0; i < n; i++)
        scanf("%d %d", &W[i], &V[i]);
    printf("\n%d", knapsack(W, V, w, 0));
    return 0;
}