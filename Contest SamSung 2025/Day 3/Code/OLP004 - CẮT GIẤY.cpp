#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(x, y, z); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int a, b, c, d, e;
vector<vector<int>> matrix, prefix;

bool check(int x){
    for(int i = x; i <= a; i++){
        for(int j = x; j <= b; j++){
            int tmp = prefix[i][j] - prefix[i][j - x] - prefix[i - x][j] + prefix[i - x][j - x];
            if(tmp <= e){
                return true;
            }
        }
    }
    return false;
}

TranHungss(){
    FastIO();
    cin >> a >> b >> c >> d >> e;
    matrix.assign(a + 1, vector<int>(b + 1, 0));
    prefix.assign(a + 1, vector<int>(b + 1, 0));
    for(int i = 0; i < c; i++){
        int x, y;
        cin >> x >> y;
        matrix[x][y] = 1;
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            prefix[i][j] = matrix[i][j] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
        }
    }
    vector<int> vt;
    for(int i = 1; ; i++){
        if(i * d > min(a, b)) break;
        vt.push_back(i * d);
    }
    int res = 0, left = 0, right = vt.size() - 1;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(check(vt[mid])){
            res = vt[mid];
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << res << endl;
    return (0 ^ 0);
}