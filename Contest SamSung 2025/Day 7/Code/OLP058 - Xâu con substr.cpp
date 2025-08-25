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
const int maxn = 1000001;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

string s, t;
int n, m;
int HashS1[maxn], HashS2[maxn], p1[maxn], p2[maxn];

void Build_HashS(){
    p1[0] = p2[0] = 1;
    for(int i = 1; i <= n; i++){
        HashS1[i] = (HashS1[i - 1] * base1 + (int)s[i]) % mod1;
        HashS2[i] = (HashS2[i - 1] * base2 + (int)s[i]) % mod2;
        p1[i] = p1[i - 1] * base1 % mod1;
        p2[i] = p2[i - 1] * base2 % mod2;
    }
}

pair<int, int> getHashS(int l, int r){
    int h1 = (HashS1[r] - HashS1[l - 1] * p1[r - l + 1] + mod1 * mod1) % mod1;
    int h2 = (HashS2[r] - HashS2[l - 1] * p2[r - l + 1] + mod2 * mod2) % mod2;
    return {h1, h2};
}

TranHungss(){
    FastIO();
    cin >> s >> t;
    n = s.size(); m = t.size();
    s = " " + s; t = " " + t;
    Build_HashS();
    pair<int, int> HashT = {0, 0};
    for(int i = 1; i <= m; i++){
        HashT.first = (HashT.first * base1 + (int)t[i]) % mod1;
        HashT.second = (HashT.second * base2 + (int)t[i]) % mod2;
    }
    for(int i = 1; i <= n - m + 1; i++){
        if(getHashS(i, i + m - 1) == HashT){
            cout << i << " ";
        }
    }
    return (0 ^ 0);
}