#include <bits/stdc++.h>
using namespace std;
#define fastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

ll gcd(ll a, ll b, ll *x, ll *y);

int main(int argc, const char * argv[]) {
    fastIO();
    ll a = 69, b = 239, x, y, gcdab;
    gcdab = gcd(a, b, &x, &y);
    cout << "gcd(" << a << "," << b << ") = " << gcdab << endl;
    cout << "Bezout coefficients: " << x << " and " << y << endl;
    cout << "Check: " << a << "*" << x << " + " << b << "*" << y << " = " << gcdab << endl;
    return 0;
}

ll gcd(ll a, ll b, ll *x, ll *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return abs(a);
    }
    ll x1, y1, gcdab = gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return gcdab;
}