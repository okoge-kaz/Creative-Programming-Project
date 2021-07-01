#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
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
vector<vector<int>>G;
vector<char>c;

void dfs(int crr_v, int pre_v, vector<vector<mint>>&dp){
    mint val1 = 1; mint val2 = 1; 
    for(int nv:G[crr_v]){
        if(nv==pre_v) continue;//逆流しないように
        dfs(nv,crr_v,dp);
        if(c[crr_v]=='a'){
            val1 = val1 * (dp[nv][0] + dp[nv][2]);
            val2 = val2 * (dp[nv][0] + dp[nv][1] + 2LL * dp[nv][2]);
        }
        if(c[crr_v]=='b'){
            val1 *= (dp[nv][1] + dp[nv][2]);
            val2 *= (dp[nv][0] + dp[nv][1] + 2LL * dp[nv][2]);
        }
    }
    if(c[crr_v]=='a'){
        dp[crr_v][0] = val1;
        dp[crr_v][2] = (val2 - val1 + MOD);
    }
    if(c[crr_v]=='b'){
        dp[crr_v][1] = val1;
        dp[crr_v][2] = val2 - val1 + MOD;
    }
}

int main(){
    int N; cin >> N;
    c.resize(N);
    for(int i=0;i<N;i++) cin >> c[i];
    G.resize(N);
    for(int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        a--,b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    // 木DPの問題
    vector<vector<mint>>dp(N,vector<mint>(3));
    // 本文の場合はDFSの中身をつくることも難しいが、DPに３つの状態量を持たせる発想もとても重要
    // dp[v][0]: 頂点v すべてa, dp[v][1] all b, dp[v][2] both a and b
    dfs(0,-1,dp);
    cout << dp[0][2].val() << endl;
}