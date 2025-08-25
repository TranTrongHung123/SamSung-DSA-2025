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
const int maxn = 200002;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

string s, t;
int n, q, p1[maxn] = {1}, p2[maxn] = {1};

struct Node {
    int len;
    pair<int, int> hash;
};

Node segs[4 * maxn], segt[4 * maxn];

Node merge(Node a, Node b){
    Node res;
    res.len = a.len + b.len;
    int h1 = ((a.hash.first * p1[b.len]) % mod1 + b.hash.first % mod1) % mod1;
    int h2 = ((a.hash.second * p2[b.len]) % mod2 + b.hash.second % mod2) % mod2;
    res.hash = {h1, h2};
    return res;
}

void build(int i, int l, int r, char c){
    if(l == r){
        if(c == 's'){
            segs[i].len = 1;
            segs[i].hash = {(int)s[l] % mod1, (int)s[l] % mod2};
        }
        else{
            segt[i].len = 1;
            segt[i].hash = {(int)t[l] % mod1, (int)t[l] % mod2};
        }
    }
    else{
        int m = (l + r) >> 1;
        build(2 * i, l, m, c);
        build(2 * i + 1, m + 1, r, c);
        if(c == 's'){
            segs[i] = merge(segs[2 * i], segs[2 * i + 1]);
        }   
        else{
            segt[i] = merge(segt[2 * i], segt[2 * i + 1]);
        }
    }
}

void update(int i, int l, int r, int pos, char val, char c){
    if(l == r){
        if(c == 's'){
            segs[i].len = 1;
            segs[i].hash = {(int)val % mod1, (int)val % mod2};
        }
        else{
            segt[i].len = 1;
            segt[i].hash = {(int)val % mod1, (int)val % mod2};
        }
    }
    else{
        int m = (l + r) >> 1;
        if(pos <= m){
            update(2 * i, l, m, pos, val, c);
        }
        else{
            update(2 * i + 1, m + 1, r, pos, val, c);
        }
        if(c == 's'){
            segs[i] = merge(segs[2 * i], segs[2 * i + 1]);
        }   
        else{
            segt[i] = merge(segt[2 * i], segt[2 * i + 1]);
        }
    }
}

Node get(int i, int l, int r, int u, int v, char c){
    if(l > v || r < u) return {0, {0, 0}};
    if(l >= u && r <= v){
        if(c == 's'){
            return segs[i];
        }
        else{
            return segt[i];
        }
    }
    int m = (l + r) >> 1;
    auto x1 = get(2 * i, l, m, u, v, c);
    auto x2 = get(2 * i + 1, m + 1, r, u, v, c);
    return merge(x1, x2);
}

TranHungss(){
    FastIO();
    cin >> s;
    t = s; reverse(begin(t), end(t));
    n = s.size();
    s = " " + s;
    t = " " + t;
    for(int i = 1; i <= n; i++){
        p1[i] = p1[i - 1] * base1 % mod1;
        p2[i] = p2[i - 1] * base2 % mod2;
    }
    build(1, 1, n, 's');
    build(1, 1, n, 't');
    cin >> q;
    while(q--){
        char c; cin >> c;
        if(c == 'c'){
            int pos; cin >> pos;
            char val; cin >> val;
            update(1, 1, n, pos, val, 's');
            update(1, 1, n, n - pos + 1, val, 't');
        }
        else{
            int u, v;
            cin >> u >> v;
            auto x1 = get(1, 1, n, u, v, 's');
            auto x2 = get(1, 1, n, n - v + 1, n - u + 1, 't');
            cout << (x1.len == x2.len && x1.hash == x2.hash ? "YES" : "NO") << endl;
        }
    }
    return (0 ^ 0);
}