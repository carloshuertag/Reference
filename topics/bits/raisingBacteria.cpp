#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main() {
    fastio
    ll n;
    cin >> n;
    cout << __builtin_popcountll(n) << endl;
    return 0;
}