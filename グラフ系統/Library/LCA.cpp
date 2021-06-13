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
// verify https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C

// LCA Lowest Common Ancestor 計算量 O(N log(K)) = O(N log(N))
class LCA {
    private:
        vector<vector<int>>parent; // ダブリングを用いた parent[k][u] := uの2^k先の親 
        vector<int>depth;// 根からの深さ（距離)
        void init(const vector<vector<int>> &G, int root=0){
            int V = (int)G.size();
            int K = 1;
            while((1<<K) < V) K++;
            // assign 指定サイズまで動的確保
            parent.assign(K,vector<int>(V,-1));
            depth.assign(V,-1);
            dfs(G, root, -1, 0);// 根の深さは0とする
            for(int k=0;k+1<K;k++){
                for(int v=0;v<V;v++){
                    if(parent[k][v]<0) parent[k+1][v] = -1;// v の 2^k 先の親が存在しないとき、当然 2^(k+1)先にも存在しない
                    else{
                        parent[k+1][v] = parent[k][parent[k][v]];// ダブリング 
                    }
                }
            }
        }
        void dfs(const vector<vector<int>> &G, int v, int p, int d){
            parent[0][v] = p;
            depth[v] = d;
            for(int nv:G[v]){
                if(nv!=p) dfs(G, nv, v, d+1);// 親への逆流を防ぐ
            }
        }
    public:
        LCA(const vector<vector<int>> &G, int root = 0) { init(G, root); }
        int query(int u, int v){
            // 2頂点のLCA(Lowest Common Ancestor)を求める
            if(depth[u] < depth[v]) swap(u,v);// uの方が深いとして考える
            int K = (int)parent.size();
            // LCAまでの距離を同じにする
            for(int k=0;k<K;k++){
                if((depth[u]-depth[v]) & (1<<k)){
                    u = parent[k][u];
                }
            }
            // 二分探索でLCAを求める
            if(u==v) return u;
            for(int k=K-1;k>=0;k--){
                if(parent[k][u]!=parent[k][v]){
                    // 深さを揃えたのでいずれ同じ頂点に到達する
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            return parent[0][u];
        }
        int get_dist(int u,int v){
            // LCAを用いた２頂点間距離
            return depth[u] + depth[v] - 2 * depth[query(u,v)];
        }
        bool is_on_path(int u, int v, int a){
            // 頂点aが、頂点uと頂点vとの間のパス上にある
            return (get_dist(u,a)+get_dist(a,v) == get_dist(u,v));
        }
};


int main(){
    int N; cin >> N;
    vector<vector<int>>G(N);
    for(int i=0;i<N;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            int c; cin >> c;
            G[i].push_back(c);
        }
    }
    LCA lca(G);
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int u, v; cin >> u >> v;
        cout << lca.query(u,v) << endl;
    }
}