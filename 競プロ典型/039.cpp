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
void dfs(int pos, int pre, vector<ll> &dp, vector<vector<int>> &G){// pos:現在いる点, pre:前の点
    dp[pos]=1;
    // 木の先は1になるように関数を書く
    for(int v:G[pos]){
        if(v==pre) continue;
        dfs(v,pos,dp,G);
        dp[pos] += dp[v];// これで子ノードを調べる。
    }
    return;
}
int main(){
    // LCAのアルゴリズムはまだ知らないが、dist(u,v)の取得にも必ずO(1)以上かかる
    // すなわち、O(N^2)かかるシグマの中ではどんなに工夫しても意味ない。よってシグマの分解が急務
    ll N; cin >> N;
    vector<int>a(N-1),b(N-1);
    for(int i=0;i<N-1;i++) cin >> a[i] >> b[i];

    vector<vector<int>>G(N);
    for(int i=0;i<N-1;i++){
        a[i]--; b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    vector<ll>dp(N);
    dfs(0,-1,dp,G);
    ll ans = 0;
    for(int i=0;i<N;i++) ans += dp[i]*(N-dp[i]);
    cout << ans << endl;
}