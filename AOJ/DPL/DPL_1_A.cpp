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
// DP基本だからといって侮るなかれ
int main(){
    ll n, m; cin >> n >> m;
    vector<ll>c(m);
    for(int i=0;i<m;i++) cin >> c[i];

    vector<vector<ll>>dp(m+1,vector<ll>(61000,INF));
    for(int i=0;i<=m;i++) dp[i][0] = 0LL;

    for(int i=0;i<m;i++){
        for(int j=0;j<=50000;j++){
            // dp[i+1][j] 変化なしの部分を忘れるとバグる
            chmin(dp[i+1][j],dp[i][j]);//変化なし
            chmin(dp[i+1][j+c[i]], dp[i][j]+1);// 次の枚数に移行
            chmin(dp[i+1][j+c[i]], dp[i+1][j]+1);// 同じところで移行
        }
    }

    cout << dp[m][n] << endl;
}