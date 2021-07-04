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
struct edge {
    int from; int to; ll w;
    edge(int from, int to, ll w) : from(from), to(to), w(w) {}
};
// verify https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A
int main(){
    int V,E; cin >> V >> E;
    vector<vector<edge>>G(V);
    for(int i=0;i<E;i++){
        int s,t; ll d;
        cin >> s >> t >> d;
        G[s].push_back(edge(s,t,d));
    }
    ll N = (1LL << V);
    ll ans = INF;
    for(int sv=0;sv<V;sv++){
        vector<vector<ll>>dp(N,vector<ll>(V,INF));
        for(edge e:G[sv]){
            dp[1LL<<e.to][e.to] = e.w;
        }

        for(ll bit=0;bit<N;bit++){
            for(int v=0;v<V;v++){
                if(bit & (1LL<<v)){
                    for(edge e:G[v]){
                        if(bit & (1LL<<e.to)) continue;
                        chmin(dp[bit|(1LL<<e.to)][e.to],dp[bit][e.from]+e.w);
                    }
                }
            }
        }
        chmin(ans,dp[N-1][sv]);
    }
    if(ans==INF){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}