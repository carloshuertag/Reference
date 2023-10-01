// include <bits/stdc++.h>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	int x = 0;
	int y = INT_MAX;
	int z = INT_MIN;
	unsigned int pRangeSize = y - x + 1;
	unsigned int nRangeSize = -1 - z + 1;
	long int intRangeSize = (long int)pRangeSize + (long int)nRangeSize;
	cout << "x = " << x << '\n';
	cout << "++y = " << ++y << '\n';
	cout << "--z = " << --z << '\n';
	cout << "positive range size = " << pRangeSize << '\n';
	cout << "negative range size = " << nRangeSize << '\n';
	cout << "integers range size = " << intRangeSize << '\n';
	return 0;
}
