#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(x, y, z); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MAXC = 1e9;
const int INF = 1e18;

struct Node{
    Node *left = nullptr, *right = nullptr;
    int cnt = 0;
    int first = INF, last = -INF;
    int minGap = INF;
    bool hasDup = false;
    int selfCount = 0;
};

Node* root = nullptr;

Node mergeNode(const Node &a, const Node &b){
    Node res;
    res.cnt = a.cnt + b.cnt;
    res.first = min(a.first, b.first);
    res.last = max(a.last, b.last);
    res.minGap = INF;
    res.hasDup = a.hasDup || b.hasDup;
    if(a.cnt) res.minGap = min(res.minGap, a.minGap);
    if(b.cnt) res.minGap = min(res.minGap, b.minGap);
    if(a.cnt && b.cnt) res.minGap = min(res.minGap, b.first - a.last);
    if(res.hasDup) res.minGap = 0;
    return res;
}

void update(Node* &node, int l, int r, int pos){
    if(!node) node = new Node();
    if(l == r){
        node->selfCount++;
        node->cnt = node->selfCount; 
        node->first = node->last = pos;
        node->hasDup = (node->selfCount >= 2);
        node->minGap = (node->hasDup ? 0 : INF);
        return;
    }
    int m = (l + r) >> 1;
    if(pos <= m) update(node->left, l, m, pos);
    else update(node->right, m + 1, r, pos);
    Node L = node->left ? *node->left : Node();
    Node R = node->right ? *node->right : Node();
    Node merged = mergeNode(L, R);
    node->cnt = merged.cnt;
    node->first = merged.first;
    node->last = merged.last;
    node->minGap = merged.minGap;
    node->hasDup = merged.hasDup;
}

Node query(Node* node, int l, int r, int u, int v){
    if(!node || l > v || r < u) return Node();
    if(u <= l && r <= v) return *node;
    int m = (l + r) >> 1;
    Node L = query(node->left, l, m, u, v);
    Node R = query(node->right, m + 1, r, u, v);
    return mergeNode(L, R);
}

TranHungss(){
    FastIO();
    int n, m; cin >> n >> m;
    while(n--){
        int x; cin >> x;
        update(root, 0, MAXC, x);
    }
    while(m--){
        int type; cin >> type;
        if(type == 1){
            int p; cin >> p;
            update(root, 0, MAXC, p);
        }
        else{
            int l, r; cin >> l >> r;
            Node res = query(root, 0, MAXC, l, r);
            if(res.cnt <= 1) cout << -1 << endl;
            else cout << res.minGap << endl;
        }
    }
    return (0 ^ 0);
}
