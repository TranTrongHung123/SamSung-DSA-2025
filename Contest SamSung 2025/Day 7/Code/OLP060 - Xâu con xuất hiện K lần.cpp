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

const int maxn = 100001;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

int n, k;
string s;
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

int getHashS(int l, int r){
    int h1 = (HashS1[r] - HashS1[l - 1] * p1[r - l + 1] + mod1 * mod1) % mod1;
    int h2 = (HashS2[r] - HashS2[l - 1] * p2[r - l + 1] + mod2 * mod2) % mod2;
    return (h1 << 32) | h2;
}

bool check(int x){
    unordered_map<int, int> fre;
    for(int i = 1; i <= n - x + 1; i++){
        ++fre[getHashS(i, i + x - 1)];
        if(fre[getHashS(i, i + x - 1)] >= k){
            return true;
        }
    }
    return false;
}

TranHungss(){
    FastIO();
    int TC; cin >> TC;
    while(TC--){
        cin >> n >> k >> s;
        s = " " + s;
        Build_HashS();
        int res = 0, left = 1, right = n;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(check(mid)){
                res = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        cout << res << endl;
    }
    return (0 ^ 0);
}