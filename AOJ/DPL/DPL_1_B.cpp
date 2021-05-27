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
    ll N, W; cin >> N >> W;
    vector<ll>v(N), w(N);
    for(int i=0;i<N;i++) cin >> v[i] >> w[i];

    vector dp(N+1,vector (20000,0LL));
    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            chmax(dp[i+1][j],dp[i][j]);// 変化なし
            if(j+w[i] <= W) chmax(dp[i+1][j+w[i]],dp[i][j]+v[i]);
        }
    }
    cout << dp[N][W] << endl;
}