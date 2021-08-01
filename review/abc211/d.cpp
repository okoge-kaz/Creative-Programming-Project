#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;
int main(){
    int N,M; cin >> N >> M;
    vector<vector<int>>G(N);
    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        --a,--b;
        G[a].push_back(b); G[b].push_back(a);
    }
    vector<ll>dist(N,INF);
    queue<int>que; que.push(0); dist[0] = 0;
    vector<mint>dp(N); dp[0] = 1;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv:G[v]){
            if(dist[nv]==INF){
                dist[nv] = dist[v] + 1;
                que.push(nv);
                // 最短経路の本数も
                dp[nv] += dp[v];
            }
            else if(dist[nv]==dist[v]+1){
                // すでに訪れているとき
                // ここの処理をうまく書くことが求められている
                dp[nv] += dp[v];
                // ここでqueにいれてしまっては今後２重にカウントされてしまう
            }
        }
    }
    if(dist[N-1]==INF){ cout << 0 << endl; return 0;}
    cout << dp[N-1].val() << endl;
}