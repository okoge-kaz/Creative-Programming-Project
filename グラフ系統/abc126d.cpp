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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
struct Edge{
    ll to;
    ll w;
    Edge(ll to, ll w): to(to), w(w) {};
};
int N;
vector<vector<Edge>>G;
void dfs(int v,int p, vector<int>&v_colors){
    int self_color = v_colors[v];
    for(auto e:G[v]){
        if(e.to==p) continue;
        // 距離が偶数なら同じ色
        if(e.w%2==0){
            v_colors[e.to] = self_color;
            dfs(e.to,v,v_colors);
        }
        else{
            v_colors[e.to] = 1 - self_color;
            dfs(e.to,v,v_colors);
        }
    }
}
int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        --u,--v;
        G[u].emplace_back(Edge(v,w));
        G[v].emplace_back(Edge(u,w));// emplace_backだと (型)(引数,引数)とかける
    }
    vector<int>v_colors(N,-1);
    v_colors[0] = 0;
    dfs(0,-1,v_colors);
    for(int c:v_colors) cout << c << endl;
}