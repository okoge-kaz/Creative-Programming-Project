#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using lll = __int128_t;
// verified https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
// verified siz member function  https://atcoder.jp/contests/abc157/tasks/abc157_d
template<typename T>
class UnionFind {
    private:
        vector<T>par, siz, depth;// 親ノード、要素数、深さ
        void init(T N){
            par.assign(N,-1); siz.assign(N,1); depth.assign(N,1);
        }
    public:
        UnionFind(T N) { init(N); }
        T root(T x){// 根を求める
            if(par[x]==-1) return x;
            else return par[x] = root(par[x]);// 経路圧縮
        }
        bool issame(T x,T y){
            return root(x)==root(y);
        }
        bool unite(T x, T y){
            x = root(x), y = root(y);// x,yの値まで移動する
            if(x==y) return false;
            if(depth[x]<depth[y]) swap(x,y);// 常にxの方が深い
            if(depth[x]==depth[y]) depth[x]++;
            par[y] = x; siz[x] += siz[y];
            return true;
        }
        T size(T x){
            return siz[root(x)];// xを含むグループのサイズ
        }
        T deep(ll x){
            return depth[root(x)];
        }
};
int main(){
    int n,m; cin >> n >> m;
    UnionFind uf(n);
    for(int i=0;i<m;i++){
        int s,t; cin >> s >> t;
        uf.unite(s,t);
    }
    int q; cin >> q;
    while(q-->0){
        int u,v; cin >> u >> v;
        if(uf.issame(u,v))cout << "yes" << endl;
        else cout << "no" << endl;
    }
}