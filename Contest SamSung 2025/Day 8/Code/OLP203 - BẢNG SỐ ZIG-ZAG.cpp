#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int inf = (int)1e18;

TranHungss(){
    FastIO();
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x + y - 1) * (x + y) / 2 - x + 1 << endl;
    int t = (-1 + (int)sqrt(8 * z - 7)) / 2 + 1;;
    int i = (t * (t + 1) / 2) - z + 1;
    int j = t - i + 1;
    cout << i << " " << j << endl;
    return (0 ^ 0);
}
