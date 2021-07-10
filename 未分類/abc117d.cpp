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
    ll N,K; cin >> N >> K;
    vector<ll>A(N); for(ll &e:A) cin >> e;
    // 桁DPというやつが使えるらしい
    // 解説: https://drken1215.hatenablog.com/entry/2019/02/03/224200
    vector<vector<ll>>dp(62,vector<ll>(2,-INF));
    dp[60][0] = 0LL;// 60桁以上をきめたときそこまではKと一致する
    for(int d=60;d>=0;d--){
        ll bit = 1LL << d;
        ll cnt=0;
        for(int i=0;i<N;i++) if(A[i] & (bit)) ++cnt;
        // cnt は d桁におけるA[i]においてbitがたっている個数

        // d+1桁目以上を決めた時
        if(dp[d+1][1] >= 0) chmax(dp[d][1],dp[d+1][1] + bit * max(cnt,N-cnt));
        if(dp[d+1][0] >= 0){
            if(K & (1LL << d)){
                chmax(dp[d][1], dp[d+1][0]+bit*cnt);
                chmax(dp[d][0], dp[d+1][0]+bit*(N-cnt));
            }
            else chmax(dp[d][0], dp[d+1][0]+bit*cnt);
        }
    }
    cout << max(dp[0][0],dp[0][1]) << endl;
}