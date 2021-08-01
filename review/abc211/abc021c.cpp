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
using lll = __int128_t;
using mint = modint1000000007;
int main(){
    int N; cin >> N;
    int s,t; cin >> s >> t;
    --s,--t;
    int M; cin >> M;
    vector<vector<int>>G(N);
    for(int i=0;i<M;i++){
        int x,y; cin >> x >> y;
        --x,--y; G[x].push_back(y); G[y].push_back(x);
    }
    vector<ll>dist(N,INF); dist[s] = 0;
    queue<int>que; que.push(s);
    vector<mint>dp(N); dp[s] = 1;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv:G[v]){
            if(dist[nv]==INF){
                dist[nv] = dist[v] + 1;
                que.push(nv);
                dp[nv] += dp[v];
            }
            else if(dist[nv] == dist[v]+1){
                dp[nv] += dp[v];
            }
        }
    }
    cout << dp[t].val() << endl;
}