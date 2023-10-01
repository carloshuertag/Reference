#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main() {
    fastio
    ll n, a, b, acc = 1LL;
    cin >> n;
    cin >> a;
    while (--n){
        cin >> b;
        acc += (a ^ b) != 0;
        a = b;
    }
    cout << acc;
    return 0;
}