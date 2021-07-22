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

//  Connected-Components 連結成分(分解)
// verified https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D
class ConnectedComponents {
    private:
        vector<vector<int>>G;
        vector<int>cc;// connected components
        vector<bool>used;
        void dfs(int v, int cnt){
            if(used[v]) return;
            used[v] = true;
            cc[v] = cnt;
            for(int nv:G[v]) dfs(nv,cnt);
        }
    public:
        ConnectedComponents(const vector<vector<int>> &g){
            int n = (int)g.size(); G = g;
            cc.resize(n,-1); used.resize(n,false);
            int id = 0;
            for(int i=0;i<n;i++){
                if(used[i]) continue;
                dfs(i,id);
                id++;
            }
        }
        bool is_same(int u,int v){
            return cc[u] == cc[v];
        }
        vector<int> vec(){ return cc; }// 連結成分の番号が振られたvectorを返す
};

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>>G(n);
    for(int i=0;i<m;i++){
        int s,t; cin >> s >> t;
        G[s].push_back(t); G[t].push_back(s);
    }
    int q; cin >> q;
    ConnectedComponents cc(G);
    while(q-->0){
        int u,v;
        cin >> u >> v;
        if(cc.is_same(u,v)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}