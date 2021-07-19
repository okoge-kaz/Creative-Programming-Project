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
using lll = __int128_t;
int main(){
    int n; cin >> n;
    vector<int>T(n); for(int &e:T) cin >> e;
    ll total = 0; for(int e:T) total += e;
    sort(T.begin(),T.end());
    // 貪欲法が上手く使えない
    // DPであると気づけなかった
    vector<vector<ll>>dp(n+1,vector<ll>(110000,inf));
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=100000;j++){
            chmin(dp[i+1][j],dp[i][j]);
            if(j+T[i]<=100000) chmin(dp[i+1][j+T[i]],dp[i][j]+T[i]);
        }
    }
    // ナップザック問題の変形
    ll ans = INF;
    for(ll e:dp[n]) chmin(ans,max(total-e,e)); 
    cout << ans << endl;
}