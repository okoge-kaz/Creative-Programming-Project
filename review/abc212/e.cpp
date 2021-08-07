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
using mint = modint998244353;
using lll = __int128_t;
int main(){
    // まず初手で計算量が超過するDFSを考えてしまったので反省
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>>G(n);
    while(m-->0){
        int u,v; cin >> u >> v;
        u--,v--;
        G[u].push_back(v); G[v].push_back(u);
    }
    vector<vector<mint>>dp(k+1,vector<mint>(n));
    dp[0][0] = 1;
    for(int day=0;day<k;day++){
        mint sum = 0;
        for(int i=0;i<n;i++) sum+=dp[day][i];
        for(int v=0;v<n;v++) dp[day+1][v] += sum;
        // 一見するとO(N^2)だが、辺はたかだかO(M)である
        for(int cv=0;cv<n;cv++){
            for(int nv:G[cv]) dp[day+1][nv] -= dp[day][cv];
            dp[day+1][cv] -= dp[day][cv];// 自分自身から伸びる辺は消去
        }
    }
    cout << dp[k][0].val() << endl;
}