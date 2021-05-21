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
int main(){
    int N, M;
    cin >> N >> M;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    vector<vector<int>>G(N);
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        G[x].push_back(y);
    }
    // x < y であることが保証されていることがかなり大きい
    // 更新方向が決まっている場合はDAGなのでDPをしましょう
    vector dp(N,INF);
    ll ans = -INF;
    for(int i=0;i<N;i++){
        if(G[i].empty()){
            chmax(ans,A[i] - dp[i]);
            continue;
        }
        for(int to:G[i]){
            chmin(dp[to],dp[i]);
            chmin(dp[to],A[i]);
        }
        chmax(ans,A[i] - dp[i]);
    }
    cout << ans << endl;
}