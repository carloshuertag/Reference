//#include <bits/stdc++.h>
#include <iostream>
#include <limits>

#define isOdd(x) (x & 1)

using namespace std;

void printInt2Binary(int x);

int main() {
	int x = 7;
	printInt2Binary(x);
	cout << '\n';
	cout << x << (isOdd(x) ? " is odd." : " is even.") << '\n';
	cout << "~(x = " << x << ")  = " << (~x);
	cout << "\nx / 2 = " << (x >> 1) << "\nx * 2 = " << (x << 1);
	int y = 12;
	cout << "\n(x = " << x << ") & (y = " << y << ") = " << (x & y);
	cout << "\n(x = " << x << ") | (y = " << y << ") = " << (x | y) << '\n';
	return 0;
}

void printInt2Binary(int x) {
	if(!x) return;
	printInt2Binary(x >> 1);
	cout << (x & 1);
}
