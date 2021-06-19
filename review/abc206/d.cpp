#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
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
struct UnionFind {
    vector<long long>par, siz, depth;
    // par: 各頂点の親頂点の番号を表します．自身が根の場合は-1とします．
    // siz: 各頂点の属する根付き木の頂点数を表します．
    // depth: 各頂点の深さを表します．（根の場合は depth=1 となる）

    // 初期化
    UnionFind(long long N) : par(N, -1LL), siz(N, 1LL), depth(N, 1LL) { }

    // 根を求める
    long long root(long long x){
        if(par[x] == -1) return x;// xが根の場合はxを返す
        else return par[x] = root(par[x]);// 経路圧縮
    }

    // x と y が同じグループに属するかどうか（根が一致するかどうか）
    bool issame(long long x,long long y){
        return root(x) == root(y);
    }

    // x を含むグループと yを含むグループとを併合する
    bool unite(long long x,long long y){
        // x, yをそれぞれ根まで移動する．
        x = root(x), y = root(y);

        // すでに同じグループのときは何もしない
        if(x == y) return false;// 統合(unite)していないのでfalseを返す

        // union by size( y 側のサイズが小さくなるようにする)
        if( depth[x] < depth[y]) swap(x,y);
        // 深さの更新
        if(depth[x] == depth[y]) depth[x]++;
        // y を x の子とする．
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    long long size(long long x){
        return siz[root(x)];
    }

    // xを含むグループの深さ（最深度）
    long long deep(long long x){
        return depth[root(x)];
    }
};
int main(){
    int N; cin >> N;
    vector<int>A(N); for(int i=0;i<N;i++) cin >> A[i];
    ll ans = 0;
    UnionFind uf(2*1e5+1);
    for(int i=0;i<N;i++){
        if(A[i]!=A[N-1-i]){
            if(uf.issame(A[i],A[N-1-i])) continue;
            ans++;
            uf.unite(A[i],A[N-1-i]);
        }
    }
    cout << ans << endl;
}