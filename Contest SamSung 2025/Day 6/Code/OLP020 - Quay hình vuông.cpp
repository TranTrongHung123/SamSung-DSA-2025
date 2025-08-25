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

vector<int> change1(vector<int> vt){
    vector<int> res(6);
    res[0] = vt[3]; res[1] = vt[0];
    res[2] = vt[2]; res[3] = vt[4];
    res[4] = vt[1]; res[5] = vt[5];
    return res;
}

vector<int> change2(vector<int> vt){
    vector<int> res(6);
    res[0] = vt[0]; res[1] = vt[4];
    res[2] = vt[1]; res[3] = vt[3];
    res[4] = vt[5]; res[5] = vt[2];
    return res;
}

int BFS(vector<int> &st, vector<int> &en){
    queue<pair<vector<int>, int>> Q;
    map<vector<int>, int> mp;
    Q.push({st, 0});
    mp[st] = 1;
    while(Q.size()){
        auto [vt, cnt] = Q.front(); Q.pop();
        if(vt == en){
            return cnt;
        }
        vector<int> tmp1 = change1(vt);
        vector<int> tmp2 = change2(vt);
        if(mp[tmp1] == 0){
            mp[tmp1] = 1;
            Q.push({tmp1, cnt + 1});
        }
        if(mp[tmp2] == 0){
            mp[tmp2] = 1;
            Q.push({tmp2, cnt + 1});
        }
    }
    return -1;
}

TranHungss(){
    FastIO();
    vector<int> st, en;
    for(int i = 0; i < 6; i++){
        int x; cin >> x;
        st.push_back(x);
    }
    for(int i = 0; i < 6; i++){
        int x; cin >> x;
        en.push_back(x);
    }
    cout << BFS(st, en) << endl;
    return (0 ^ 0);
}