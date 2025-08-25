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

multiset<int> low, high;

void balance(){
    if(low.size() > high.size() + 1){
        high.insert(*low.rbegin());
        low.erase(prev(low.end()));
    }
    else if(low.size() < high.size()){
        low.insert(*high.begin());
        high.erase(high.begin());
    }
}

void add(int x){
    if(low.empty() || x <= *low.rbegin()){
        low.insert(x);
    } 
    else{
        high.insert(x);
    }
    balance();
}


void del(int x){
    if(low.size() && x <= *low.rbegin()){
        low.erase(low.find(x));
    }
    else{
        high.erase(high.find(x));
    }
    balance();
}

TranHungss(){
    FastIO();
    int n; cin >> n;
    while(n--){
        string type; cin >> type;
        if(type == "add"){
            int x; cin >> x;
            add(x);
        }
        else if(type == "del"){
            int x; cin >> x;
            del(x);
        }
        else{
            cout << *low.rbegin() << endl;
        }
    }
    return (0 ^ 0);
}