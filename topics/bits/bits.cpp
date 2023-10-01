//#include <bits/stdc++.h>
#include <iostream>
#include <limits>

#define setBitRange(l, r) ((((1 << (l - 1)) - 1) ^ ((1 << (r)) - 1)))
#define setBitRangeTo(x, l , r) x | setBitRange(l, r)

using namespace std;

void printInt2Binary(int x);

int main() {
	int x = 7;
	cout << __builtin_popcount(x) << '\n';
	int y = setBitRange(24, 8);
	printInt2Binary(y);
	cout << '\n';
	x = setBitRangeTo(x, 24, 8);
	printInt2Binary(x);
	cout << '\n';
	return 0;
}

void printInt2Binary(int x) {
        if(!x) return;
        printInt2Binary(x >> 1);
        cout << (x & 1);
}
