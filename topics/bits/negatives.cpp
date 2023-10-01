//#include <bits/std`c++.h>
#include <iostream>

#define com1(x) (~x)
#define com2(x) (com1(x) + 1)

using namespace std;

int main() {
	int x = 7;
	int y = com2(x);
	int z = -7;
	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';
	cout << "z = " << z << '\n';
	return 0;
}
