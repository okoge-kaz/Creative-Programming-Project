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
// verified https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
// 計算量 O(V+E)
class SCC {
    // Strongly Connected Component
    private:
        vector<int>comp,order,used;// comp: component
        vector<vector<int>>G, rG; int num=0;// sccの数を返す
        void init(const vector<vector<int>> &g){
            int N = (int)g.size(); 
            G.resize(N); rG.resize(N);
            comp.resize(N,-1); used.resize(N,false);
            // G, rGを作成
            for(int s=0;s<N;s++){
                for(int t:g[s]) { rG[t].push_back(s); G[s].push_back(t); }
            }
            // G's order
            for(int v=0;v<N;v++){
                if(!used[v]) dfs(v);
            }
            used.assign(N,false);
            // rG's order
            for(int i=(int)order.size()-1;i>=0;i--){
                if(!used[order[i]]) rdfs(order[i],num++);
                // 同じsccにはsame number
            }
        }
        void dfs(int v){
            if(used[v]) return;
            used[v] = true;
            for(int nv:G[v]){ dfs(nv); }
            // post order 帰りがけ
            order.push_back(v);
        }
        void rdfs(int v, int cnt){
            if(used[v]) return;
            used[v] = true;
            comp[v] = cnt;
            for(int nv:rG[v]) rdfs(nv, cnt);
        }
    public:
        SCC(const vector<vector<int>>&G) { init(G); }
        bool is_same(int u,int v){
            return comp[u] == comp[v];
        }
        int size(){// not verified
            return num;// sccによって分割される強連結成分の個数
        }
        vector<vector<int>>scc(){// not verified
            vector<vector<int>>res(num);
            // 0-indexの頂点番号がscc成分ごとに入っている
            for(int v=0;v<(int)G.size();v++){
                res[comp[v]].push_back(v);
            }
            return res;
        }
};

int main(){
    int V, E; cin >> V >> E;
    vector<vector<int>>G(V);
    for(int i=0;i<E;i++){
        int s,t; cin >> s >> t;
        G[s].push_back(t);
    }
    SCC scc(G);
    int Q; cin >> Q;
    while(Q-->0){
        int u,v; cin >> u >> v;
        if(scc.is_same(u,v)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}