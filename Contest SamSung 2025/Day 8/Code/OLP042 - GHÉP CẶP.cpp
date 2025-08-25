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

int p[maxn] = {0};

void sieve(){
    for(int i = 1; i < maxn; i++){
        p[i] = i;
    }
    for(int i = 2; i * i < maxn; i++){
        if(p[i]){
            for(int j = i * i; j < maxn; j += i){
                if(p[j] == j){
                    p[j] = i;
                }
            }
        }
    }
}

TranHungss(){
    FastIO();
    sieve();
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        if(n == 0){
            cout << 0 << endl;
            continue;
        }
        int res = 1;
        while(n != 1){
            int deg = 0;
            int tmp = p[n];
            while(n % tmp == 0){
                deg += 1;
                n /= tmp;
            }
            res *= (deg + 1);
        }
        cout << res << endl;
    }
    return (0 ^ 0);
}