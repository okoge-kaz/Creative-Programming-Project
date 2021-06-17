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
    ll N,W; cin >> N >> W;
    vector<ll>v(N), w(N);
    for(int i=0;i<N;i++) cin >> v[i] >> w[i];
    vector<vector<ll>>dp(N+1,vector<ll>(11000,INF));
    dp[0][0] = 0LL;
    for(int i=0;i<N;i++){
        for(int j=0;j<=10000;j++){
            chmin(dp[i+1][j],dp[i][j]);
            if(j+v[i]<=10000){
                chmin(dp[i+1][j+v[i]],dp[i][j]+w[i]);
            }
        }
    }
    ll ans = 0;
    for(ll i=10000;i>=0;i--){
        if(dp[N][i]<=W) chmax(ans,i);
    }
    cout << ans << endl;
}