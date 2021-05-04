#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using mint = modint998244353;
// 自動でmodをとりたいの以下のような構造体を用意する
struct S {
    mint a;
    int size;
};

struct F {
    mint a, b;
};

S op(S l, S r){
    // S という型の l という変数, S 型 r 変数を引数に取る関数
    return S{l.a + r.a, l.size + r.size};
}

S e() { return S{0, 0}; }

S mapping(F l, S r){
    return S{r.a * l.a + r.size * l.b , r.size};
}

F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }

F id() { return F{1, 0}; }

int main(){
    int n,q;
    cin >> n >> q;
    vector<S>a(n);//自動的にmodをとるもの
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a[i] = S{x,1};
    }

    lazy_segtree<S,op,e,F,mapping,composition, id>seg(a);
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==0){
            int l,r;
            int c,d;
            cin >> l >> r >> c >> d;
            seg.apply(l,r,F{c,d});
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l,r).a.val() << endl;
        }
    }
}