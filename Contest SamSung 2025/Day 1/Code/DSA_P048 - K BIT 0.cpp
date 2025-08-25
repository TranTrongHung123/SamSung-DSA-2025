#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define back_insert back_inserter
#define __builtin_popcount __builtin_popcountll
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dp[40][2][2][40];

int solve(int pos, int tight, int started, int cnt, string &s, int k){
    if(pos == s.size()){
        if(started == false) return (k == 1);
        return cnt == k;
    }
    if(dp[pos][tight][started][cnt] != -1){
        return dp[pos][tight][started][cnt];
    }
    int res = 0, limit = tight ? s[pos] - '0' : 1;
    for(int d = 0; d <= limit; d++){
        if(started || d != 0){
            res += solve(pos + 1, tight && d == limit, started || d != 0, cnt + (d == 0), s, k);
        }
        else{
            res += solve(pos + 1, tight && d == limit, started || d != 0, cnt, s, k);
        }
    }
    return dp[pos][tight][started][cnt] = res;
}

int f(int n, int k){
    memset(dp, -1, sizeof(dp));
    string s = "";
    while(n){
        s += char((n % 2) + '0');
        n /= 2;
    }
    reverse(begin(s), end(s));
    return solve(0, 1, 0, 0, s, k);
}

TranHungss(){
    FastIO();
    int TC; cin >> TC;
    while(TC--){
        int n, k;
        cin >> n >> k;
        cout << f(n, k) << endl;
    }
    return (0 ^ 0);
}