#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define back_insert back_inserter
#define __builtin_popcount __builtin_popcountll
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dp[20][2][10][20];

int solve(int pos, int tight, int sum, int cnt, string &s){
    if(pos == s.size()){
        if(sum == 0){
            return cnt;
        }
        return 0;
    }
    if(dp[pos][tight][sum][cnt] != -1){
        return dp[pos][tight][sum][cnt];
    }
    int res = 0, limit = tight ? s[pos] - '0' : 9;
    for(int d = 0; d <= limit; d++){
        res += solve(pos + 1, tight && d == limit, (10 * sum + d) % 8, cnt + (d == 6 || d == 8), s);
    }
    return dp[pos][tight][sum][cnt] = res;
}

int f(int n){
    memset(dp, -1, sizeof(dp));
    string s = to_string(n);
    return solve(0, 1, 0, 0, s);
}

main(){
    FastIO();
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        cout << f(n) << endl;
    }
    return (0 ^ 0);
}